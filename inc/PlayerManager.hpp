#ifndef PLAYER_MANAGER_HPP // include guard
#define PLAYER_MANAGER_HPP

#include "PlayerContext.hpp"
#include "IPlayerManager.hpp"

#include "PlayList.hpp"
#include "StateMachine.hpp"
#include "PlayerExecutor.hpp"
#include "Output.hpp"
#include "ConfigSystemFiles.hpp"

namespace AudioPlayer
{
    class StateMachine;
    /**
     * @brief The manager of the audio player.
     */
    class PlayerManager : public IPlayerManager
    {
    public:
        /**
         * @brief Constructor of the player manager.
         *
         * @param mv_output_writer The output writer used by the player.
         */
        PlayerManager(const IOutputWriter &mv_output_writer);

        /**
         * @brief Processes a command passed to the player.
         *
         * @param mv_cmd The command to be processed.
         */
        void process_command(CommandVariant mv_cmd) override;

        /**
         * @brief Indicates if the player is running or not.
         *
         * @return true if the player is running, false otherwise.
         */
        bool is_running();

        /**
         * @brief Destructor of the player manager.
         */
        virtual ~PlayerManager(){};

    private:
        /**
         * @brief Handles the command of adding a track to the playlist.
         *
         * @param cmd The command to be handled.
         */
        void handleCommand(std::shared_ptr<const AddTrackCommand> cmd);

        /**
         * @brief Handles the command of removing a track from the playlist.
         *
         * @param cmd The command to be handled.
         */
        void handleCommand(std::shared_ptr<const RemoveTrackCommand> cmd);

        /**
         * @brief Handles the command of removing duplicate tracks from the playlist.
         *
         * @param cmd The command to be handled.
         */
        void handleCommand(std::shared_ptr<const RemoveDuplicatesCommand> cmd);

        /**
         * @brief Handles the command of playing or pausing the player.
         *
         * @param cmd The command to be handled.
         */
        void handleCommand(std::shared_ptr<const PlayPauseCommand> cmd);

        /**
         * @brief Handles the command of stopping the player.
         *
         * @param cmd The command to be handled.
         */
        void handleCommand(std::shared_ptr<const StopCommand> cmd);

        /**
         * @brief Handles the command of playing the next track in the playlist.
         *
         * @param cmd The command to be handled.
         */
        void handleCommand(std::shared_ptr<const NextCommand> cmd);

        /**
         * @brief Handles the command of playing the previous track in the playlist.
         *
         * @param cmd The command to be handled.
         */
        void handleCommand(std::shared_ptr<const PreviousCommand> cmd);

        /**
         * @brief Handles the command of playing a random track from the playlist.
         *
         * @param cmd The command to be handled.
         */
        void handleCommand(std::shared_ptr<const RandomCommand> cmd);

        /**
         * @brief Handles the command of playing the same track again.
         *
         * @param cmd The command to be handled.
         */
        void handleCommand(std::shared_ptr<const RepeatCommand> cmd);

        /**
         * @brief Handles the command of showing information about the current track.
         *
         * @param cmd The command to be handled.
         */
        void handleCommand(std::shared_ptr<const ShowTrackCommand> cmd);

        /**
         * @brief Handles the ShowPlaylistCommand
         *
         * This function takes a shared pointer to a constant ShowPlaylistCommand and handles it accordingly.
         *
         * @param cmd The shared pointer to the constant ShowPlaylistCommand to be handled.
         */
        void handleCommand(std::shared_ptr<const ShowPlaylistCommand> cmd);

        /**
         * @brief Handles the EndCommand
         *
         * This function takes a shared pointer to a constant EndCommand and handles it accordingly.
         *
         * @param cmd The shared pointer to the constant EndCommand to be handled.
         */
        void handleCommand(std::shared_ptr<const EndCommand> cmd);

        /**
         * @brief Handles the nullptr_t command
         *
         * This function is called when a command has not been implemented yet. It takes a nullptr_t as parameter
         * and can be modified to handle any commands that are not yet implemented.
         *
         * @param cmd The nullptr_t to be handled.
         */
        void handleCommand(std::nullptr_t);

        /**
         * @brief Displays system files
         *
         * This function displays the system files used by the audio player.
         */
        void displaySystemFiles();

        StateMachine m_state_machine;                 ///< The state machine of the audio player.
        PlayerContext m_context;                      ///< The context of the audio player.
        PlayerExecutor m_executor;                    ///< The executor of the audio player.
        Output m_output;                              ///< The output of the audio player.
        SystemFiles::ConfigSystemFiles m_system_conf; ///< The system configuration files of the audio player.
        bool m_running = true;                        ///< A flag indicating whether the audio player is running.
    };
}
#endif
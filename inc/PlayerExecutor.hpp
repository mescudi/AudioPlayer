#ifndef PLAYER_EXECUTOR_HPP // include guard
#define PLAYER_EXECUTOR_HPP

#include "IPlayerExecutor.hpp"
#include "IPlayerContext.hpp"
#include "IPlayerManager.hpp"
#include "PlayList.hpp"
#include "IOutput.hpp"
#include "ConfigSystemFiles.hpp"
#include "StateMachine.hpp"

namespace AudioPlayer
{

    /**
     * @brief The PlayerExecutor class is responsible for handling the execution of logical functions of the player.
     */
    class PlayerExecutor : public IPlayerExecutor
    {
    public:
        /**
         * @brief Constructs a new PlayerExecutor object.
         *
         * @param context An instance of the IPlayerContext interface.
         * @param system_conf An instance of the IConfigSystemFiles interface.
         * @param output An instance of the IOutput interface.
         */
        PlayerExecutor(IPlayerContext &context, const SystemFiles::IConfigSystemFiles &system_conf, IOutput &output);

        /**
         * @brief Adds a track to the playlist.
         *
         * @param mv_string The string representing the track to be added.
         */
        void add_track_to_playlist(const std::string &mv_string) override;

        /**
         * @brief Adds a every audio file of the System Files to the playlist.
         */
        void add_all_system_tracks_to_playlist() override;
        /**
         * @brief Removes a track from the playlist.
         *
         * @param track_id The id of the track to be removed.
         */
        void remove_track(uint32_t track_id) override;

        /**
         * @brief Removes duplicate tracks from the playlist.
         */
        void remove_duplicates() override;

        /**
         * @brief Starts playing the current track.
         */
        void start() override;

        /**
         * @brief Stops the player.
         */
        void stop() override;

        /**
         * @brief Pauses the player.
         */
        void pause() override;

        /**
         * @brief Resumes playing the current track.
         */
        void resume() override;

        /**
         * @brief Shows information about the current track.
         */
        void show_track() override;

        /**
         * @brief Shows information about the playlist.
         */
        void show_playlist() override;

        /**
         * @brief Sets the previous track as the current track.
         */
        void set_previous_track() override;

        /**
         * @brief Sets the next track as the current track.
         */
        void set_next_track() override;

        /**
         * @brief Sets a random track as the current track.
         */
        void set_random_track() override;

        /**
         * @brief Plays the same track again.
         */
        void set_same_track() override;

    private:
        IPlayerContext &m_context;                            ///< An reference of the IPlayerContext interface.
        const SystemFiles::IConfigSystemFiles &m_system_conf; ///< An reference of the IConfigSystemFiles interface.
        IOutput &m_output;                                    ///< An reference of the IOutput interface.
        PlayList m_playlist;                                  ///< An instance of the PlayList class.
    };

}

#endif // PLAYER_EXECUTOR_HPP

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

    class PlayerManager : public IPlayerManager
    {
    public:
        PlayerManager(const IOutputWriter &);
        void process_command(CommandVariant mv_cmd) override;
        bool is_running();

    private:
        void handleCommand(std::shared_ptr<const AddTrackCommand> cmd);
        void handleCommand(std::shared_ptr<const RemoveTrackCommand> cmd);
        void handleCommand(std::shared_ptr<const RemoveDuplicatesCommand> cmd);
        void handleCommand(std::shared_ptr<const PlayPauseCommand> cmd);
        void handleCommand(std::shared_ptr<const StopCommand> cmd);
        void handleCommand(std::shared_ptr<const NextCommand> cmd);
        void handleCommand(std::shared_ptr<const PreviousCommand> cmd);

        void handleCommand(std::shared_ptr<const RandomCommand> cmd);
        void handleCommand(std::shared_ptr<const RepeatCommand> cmd);

        void handleCommand(std::shared_ptr<const ShowTrackCommand> cmd);
        void handleCommand(std::shared_ptr<const ShowPlaylistCommand> cmd);
        void handleCommand(std::shared_ptr<const EndCommand> cmd);

        void handleCommand(std::nullptr_t); // TODO modify visit so that all commands can be not implemented

        PlayerContext m_context;
        PlayerExecutor m_executor;
        Output m_output;
        SystemFiles::ConfigSystemFiles m_system_conf;
        // PlayList m_playlist;
        StateMachine m_state_machine;

        bool m_running = true;

        void displaySystemFiles();
    };
}
#endif
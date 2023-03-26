#ifndef PLAYER_MANAGER_HPP // include guard
#define PLAYER_MANAGER_HPP

#include "PlayerContext.hpp"
#include "IPlayerManager.hpp"

#include "PlayList.hpp"
#include "StateMachine.hpp"
#include "PlayerExecutor.hpp"

#include "ConfigSystemFiles.hpp"
namespace AudioPlayer
{

    class PlayerManager : public IPlayerManager
    {
    public:
        PlayerManager();
        void process_command(CommandVariant mv_cmd) override;

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
        void handleCommand(std::nullptr_t); // TODO modify visit so that all commands can be not implemented

        PlayerContext m_context;
        PlayerExecutor m_executor;

        SystemFiles::ConfigSystemFiles m_system_conf;
        // PlayList m_playlist;
        StateMachine m_state_machine;
    };
}
#endif
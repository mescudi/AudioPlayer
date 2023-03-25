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
        // void process_command(const Command &);
        void process_command(std::shared_ptr<const Command>) override;

    private:
        PlayerContext m_context;
        PlayerExecutor m_executor;

        SystemFiles::ConfigSystemFiles m_system_conf;
        // Playlist m_playlist;
        std::unique_ptr<StateMachine> m_state_machine;
    };
}
#endif
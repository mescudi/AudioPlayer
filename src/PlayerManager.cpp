#include "PlayerManager.hpp"
#include "match.hpp"
#include <variant>
#include "Logger.hpp"
namespace AudioPlayer
{
    PlayerManager::PlayerManager() : m_context(),
                                     m_system_conf(),
                                     m_executor(m_context, m_system_conf),
                                     m_state_machine(m_executor)

    {
    }

    void PlayerManager::process_command(CommandVariant mv_cmd)
    {
        std::visit([this](auto &&cmd)
                   { this->handleCommand(cmd); },
                   mv_cmd);
    }

    void PlayerManager::handleCommand(std::shared_ptr<const AddTrackCommand> cmd) {}
    void PlayerManager::handleCommand(std::shared_ptr<const RemoveTrackCommand> cmd) {}
    void PlayerManager::handleCommand(std::shared_ptr<const RemoveDuplicatesCommand> cmd) {}
    void PlayerManager::handleCommand(std::shared_ptr<const PlayPauseCommand> cmd)
    {
        std::cout << "On dans handle playpause" << std::endl;
        m_state_machine.start();
    }
    void PlayerManager::handleCommand(std::shared_ptr<const StopCommand> cmd)
    {
        std::cout << "On dans handle stop" << std::endl;

        m_state_machine.stop();
    }
    void PlayerManager::handleCommand(std::shared_ptr<const NextCommand> cmd) {}
    void PlayerManager::handleCommand(std::shared_ptr<const PreviousCommand> cmd)
    {
    }

    void PlayerManager::handleCommand(std::shared_ptr<const RandomCommand> cmd)
    {
        m_executor.random();
    }
    void PlayerManager::handleCommand(std::shared_ptr<const RepeatCommand> cmd)
    {
        m_executor.repeat();
    }

    void PlayerManager::handleCommand(std::shared_ptr<const ShowTrackCommand> cmd) {}
    void PlayerManager::handleCommand(std::shared_ptr<const ShowPlaylistCommand> cmd) {}
    void PlayerManager::handleCommand(std::nullptr_t) {} // TODO modify visit so that all commands can be not implemented

}

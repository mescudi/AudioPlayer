#include "PlayerManager.hpp"
#include "match.hpp"
#include <variant>
#include "Logger.hpp"
namespace AudioPlayer
{
    void PlayerManager::process_command(std::shared_ptr<const Command> mv_cmd)
    {
        CommandVariant var_cmd = mv_cmd;

        std::visit([this](auto &&mv_cmd)
                   {
            using T = std::decay_t<decltype(mv_cmd)>;
            if constexpr (std::is_same_v<T, std::shared_ptr<const AddTrackCommand>>)
            {
            LOG("INFO", mv_cmd->m_name+": "+mv_cmd->m_track_name);

            } else if constexpr (std::is_same_v<T, std::shared_ptr<const RemoveTrackCommand>>) {
            LOG("INFO", mv_cmd->m_name);
            } else if constexpr (std::is_same_v<T, std::shared_ptr<const RemoveDuplicatesCommand>>) {
            LOG("INFO", mv_cmd->m_name);
            } else if constexpr (std::is_same_v<T, std::shared_ptr<const PlayPauseCommand>>) {
            LOG("INFO", mv_cmd->m_name);
            }else if constexpr (std::is_same_v<T, std::shared_ptr<const NextCommand>>) {
            LOG("INFO", mv_cmd->m_name);
            } else if constexpr (std::is_same_v<T, std::shared_ptr<const PreviousCommand>>) {
            LOG("INFO", mv_cmd->m_name);
            } else if constexpr (std::is_same_v<T, std::shared_ptr<const RandomCommand>>) {
            LOG("INFO", mv_cmd->m_name);
            } else if constexpr (std::is_same_v<T, std::shared_ptr<const RepeatCommand>>) {
            LOG("INFO", mv_cmd->m_name);
            } else if constexpr (std::is_same_v<T, std::shared_ptr<const ShowTrackCommand>>) {
            LOG("INFO", mv_cmd->m_name);
            } else if constexpr (std::is_same_v<T, std::shared_ptr<const ShowPlaylistCommand>>) {
            LOG("INFO", mv_cmd->m_name);
            } },
                   var_cmd);
    }
}

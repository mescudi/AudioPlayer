#include "PlayerManager.hpp"
#include "match.hpp"
#include <variant>
#include "Logger.hpp"
namespace AudioPlayer
{
    PlayerManager::PlayerManager(const IOutputWriter &mv_output_writer) : m_system_conf(),
                                                                          m_playlist(),
                                                                          m_output(m_playlist, mv_output_writer),
                                                                          m_executor(m_playlist, m_system_conf, m_output),
                                                                          m_state_machine(m_executor)

    {
        displaySystemFiles();
    }

    void PlayerManager::process_command(CommandVariant mv_cmd)
    { /* thanks to type of contained in CommandVariant, will redirect to the adequat handleCommand */
        std::visit([this](auto &&cmd)
                   { this->handleCommand(cmd); },
                   mv_cmd);
    }

    void PlayerManager::handleCommand(std::shared_ptr<const AddTrackCommand> cmd)
    {
        LOG("DEV", cmd->m_name + ", track : " + cmd->m_track_name);
        m_executor.add_track_to_playlist(cmd->m_track_name);
    }

    void PlayerManager::handleCommand(std::shared_ptr<const AddAllTracksCommand> cmd)
    {
        LOG("DEV", "");
        m_executor.add_all_system_tracks_to_playlist();
    }
    void PlayerManager::handleCommand(std::shared_ptr<const RemoveTrackCommand> cmd)
    {
        LOG("DEV", "");
        if (m_playlist.is_there_track_to_play())
        {
            m_state_machine.remove_track(cmd->m_track_number);
        }
        else
        {
            m_output.display_message("No track in the playlist, before removing add one with add_track \'name of your track\'");
        }
    }
    void PlayerManager::handleCommand(std::shared_ptr<const RemoveDuplicatesCommand> cmd)
    {
        LOG("DEV", "");
        if (m_playlist.is_there_track_to_play())
        {
            m_executor.remove_duplicates();
        }
        else
        {
            m_output.display_message("No track in the playlist, before removing add one with add_track \'name of your track\'");
        }
    }
    void PlayerManager::handleCommand(std::shared_ptr<const PlayPauseCommand> cmd)
    {
        if (m_playlist.is_there_track_to_play())
        {
            m_state_machine.start_pause();
        }
        else
        {
            m_output.display_message("No track in the playlist, add one before with add_track \'name of your track\'");
        }
    }
    void PlayerManager::handleCommand(std::shared_ptr<const StopCommand> cmd)
    {
        if (m_playlist.is_there_track_to_play())
        {
            m_state_machine.stop();
        }
        else
        {
            m_output.display_message("No track in the playlist, before stopping add one with add_track \'name of your track\'");
        }
    }
    void PlayerManager::handleCommand(std::shared_ptr<const NextCommand> cmd)
    {
        // appeler le visitor correspondant
        if (m_playlist.is_there_track_to_play())
        {
            m_state_machine.next();
        }
        else
        {
            m_output.display_message("No track in the playlist, before stopping add one with add_track \'name of your track\'");
        }
    }
    void PlayerManager::handleCommand(std::shared_ptr<const PreviousCommand> cmd)
    {
        // appeler le visitor correspondant
        if (m_playlist.is_there_track_to_play())
        {
            m_state_machine.previous();
        }
        else
        {
            m_output.display_message("No track in the playlist, before stopping add one with add_track \'name of your track\'");
        }
    }

    void PlayerManager::handleCommand(std::shared_ptr<const RandomCommand> cmd)
    {
        m_state_machine.set_random();
    }
    void PlayerManager::handleCommand(std::shared_ptr<const RepeatCommand> cmd)
    {
        LOG("DEV", cmd->m_name);
        m_state_machine.set_repeat();
    }

    void PlayerManager::handleCommand(std::shared_ptr<const ShowTrackCommand> cmd)
    {

        m_executor.show_track();
    }
    void PlayerManager::handleCommand(std::shared_ptr<const ShowPlaylistCommand> cmd)
    {
        m_executor.show_playlist();
    }
    void PlayerManager::handleCommand(std::nullptr_t) {} // useless and ugly TODO modify visit so that all commands can be not implemented
    void PlayerManager::handleCommand(std::shared_ptr<const EndCommand> cmd)
    {
        m_running = false;
    }

    bool PlayerManager::is_running()
    {
        return m_running;
    }
    void PlayerManager::displaySystemFiles() // deplacer
    {
        std::string iv_display = "\nSystem Tracks available to add :\n";
        for (auto iv_it : m_system_conf.getFileSystemMap())
        {
            iv_display += "\n [" + iv_it.first + "]\n";
        }
        m_output.display_message(iv_display);
    }

}

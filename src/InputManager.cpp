#include "InputManager.hpp"
#include <string>
#include <sstream>

namespace AudioPlayer
{

    InputManager::InputManager(const IOutputWriter &mv_output_writer) : m_output_writer(mv_output_writer)
    {
        m_help_string = "\n Help : \n - " + m_add_track + " \'track name\'\n - " + m_remove_track + " \'track index\'\n - " + m_remove_duplicates + "\n - " + m_play_pause + "\n - " + m_stop + "\n - " + m_next + "\n - " + m_previous + "\n - " + m_random + "\n - " + m_repeat + "\n - " + m_show_track + "\n - " + m_show_playlist + "\n - " + m_end;
        m_output_writer.display_message("Type : \"" + m_help + "\" to display again : " + m_help_string);
    }
    CommandVariant InputManager::input() const
    {

        m_output_writer.display_message("Waiting your Command >> ");
        std::string input_str;
        std::getline(std::cin, input_str);
        std::istringstream iss(input_str);

        std::string iv_command_str;
        iss >> iv_command_str;
        if (iv_command_str == m_help)
        {
            m_output_writer.display_message(m_help_string);
        }
        else if (iv_command_str == m_add_track)
        {
            std::string iv_track_name;
            iss >> iv_track_name;
            return std::make_shared<AddTrackCommand>(iv_track_name);
        }
        else if (iv_command_str == m_remove_track)
        {
            return std::make_shared<RemoveTrackCommand>();
        }
        else if (iv_command_str == m_remove_duplicates)
        {
            return std::make_shared<RemoveDuplicatesCommand>();
        }
        //-----------------------------------------------------------------------------
        else if (iv_command_str == m_play_pause)
        {
            return std::make_shared<PlayPauseCommand>();
        }
        else if (iv_command_str == m_stop)
        {
            return std::make_shared<StopCommand>();
        }
        else if (iv_command_str == m_next)
        {
            return std::make_shared<NextCommand>();
        }
        else if (iv_command_str == m_previous)
        {
            return std::make_shared<PreviousCommand>();
        }
        //-----------------------------------------------------------------------------
        else if (iv_command_str == m_random)
        {
            return std::make_shared<RandomCommand>();
        }
        else if (iv_command_str == m_repeat)
        {
            return std::make_shared<RepeatCommand>();
        }
        //-----------------------------------------------------------------------------
        else if (iv_command_str == m_show_track)
        {
            return std::make_shared<ShowTrackCommand>();
        }
        else if (iv_command_str == m_show_playlist)
        {
            return std::make_shared<ShowPlaylistCommand>();
        }
        else if (iv_command_str == m_end)
        {
            m_output_writer.display_message("Exit Player");
            return std::make_shared<EndCommand>();
        }
        else
        {
            m_output_writer.display_message("Unknown command, try again");
        }

        return nullptr;
    }
}
#include "InputManager.hpp"
#include <string>
#include <sstream>

namespace AudioPlayer
{

    InputManager::InputManager(const IOutputWriter &mv_output_writer) : m_output_writer(mv_output_writer)
    {
        m_help_string = "\n Help : \n - " + m_add_all_tracks + "\n -" + m_add_track + " \'track name\'\n - " + m_remove_track + " \'track index\'\n - " + m_remove_duplicates + "\n - " + m_play_pause + "\n - " + m_stop + "\n - " + m_next + "\n - " + m_previous + "\n - " + m_random + "\n - " + m_repeat + "\n - " + m_show_track + "\n - " + m_show_playlist + "\n - " + m_end;
        m_output_writer.display_message("Type : \"" + m_help + "\" to display again : " + m_help_string);
    }
    // Function to get user input and return a CommandVariant object
    CommandVariant InputManager::input() const
    {
        // Display message asking for input
        m_output_writer.display_message("Waiting your Command >> ");

        // Get input from user as a string
        std::string input_str;
        std::getline(std::cin, input_str);

        // Create a stringstream object from the input string
        std::istringstream iss(input_str);

        // Get the first word in the input string as the command string
        std::string iv_command_str;
        iss >> iv_command_str;

        // Check which command was entered and return a CommandVariant object
        if (iv_command_str == m_help)
        {
            // If "help" command is entered, display help string
            m_output_writer.display_message(m_help_string);
        }
        else if (iv_command_str == m_add_track)
        {
            // If "add track" command is entered, get the track name from input and return an AddTrackCommand object
            std::string iv_track_name;
            iss >> iv_track_name;
            return std::make_shared<AddTrackCommand>(iv_track_name);
        }
        else if (iv_command_str == m_add_all_tracks)
        {
            // If "add_all_track" command is entered, return a RemoveTrackCommand object
            return std::make_shared<AddAllTracksCommand>();
        }
        else if (iv_command_str == m_remove_track)
        {
            // If "remove track" command is entered, get the track index from input and return a RemoveTrackCommand object
            std::string iv_track_index_str;
            iss >> iv_track_index_str;
            // Check if the input string contains only numeric characters
            if (iv_track_index_str == "" || iv_track_index_str.find_first_not_of("0123456789") != std::string::npos)
            {
                m_output_writer.display_message("Invalid input: track number must be a positive integer");
            }
            else
            {
                uint32_t iv_track_index = std::stoi(iv_track_index_str);
                return std::make_shared<RemoveTrackCommand>(iv_track_index);
            }
        }
        else if (iv_command_str == m_remove_duplicates)
        {
            // If "remove duplicates" command is entered, return a RemoveDuplicatesCommand object
            return std::make_shared<RemoveDuplicatesCommand>();
        }
        //-----------------------------------------------------------------------------
        else if (iv_command_str == m_play_pause)
        {
            // If "play/pause" command is entered, return a PlayPauseCommand object
            return std::make_shared<PlayPauseCommand>();
        }
        else if (iv_command_str == m_stop)
        {
            // If "stop" command is entered, return a StopCommand object
            return std::make_shared<StopCommand>();
        }
        else if (iv_command_str == m_next)
        {
            // If "next" command is entered, return a NextCommand object
            return std::make_shared<NextCommand>();
        }
        else if (iv_command_str == m_previous)
        {
            // If "previous" command is entered, return a PreviousCommand object
            return std::make_shared<PreviousCommand>();
        }
        //-----------------------------------------------------------------------------
        else if (iv_command_str == m_random)
        {
            // If "random" command is entered, return a RandomCommand object
            return std::make_shared<RandomCommand>();
        }
        else if (iv_command_str == m_repeat)
        {
            // If "repeat" command is entered, return a RepeatCommand object
            return std::make_shared<RepeatCommand>();
        }
        //-----------------------------------------------------------------------------
        else if (iv_command_str == m_show_track)
        {
            // If "show_track" command is entered, return a RandomCommand object
            return std::make_shared<ShowTrackCommand>();
        }
        else if (iv_command_str == m_show_playlist)
        {
            // If "show_playlist" command is entered, return a RandomCommand object
            return std::make_shared<ShowPlaylistCommand>();
        }
        else if (iv_command_str == m_end)
        {
            // If "end" command is entered, return a EndCommand object
            m_output_writer.display_message("Exit Player");
            return std::make_shared<EndCommand>();
        }
        else
        { // If the command does not find a case in which it can be interpreted it will return nullptr

            m_output_writer.display_message("Unknown command, try again");
        }

        return nullptr;
    }
}
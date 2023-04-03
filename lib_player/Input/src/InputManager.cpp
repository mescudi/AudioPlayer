#include "InputManager.hpp"
#include <string>
#include <sstream>
#include <vector>

namespace AudioPlayer
{

    InputManager::InputManager(const IOutputWriter &mv_output_writer) : m_output_writer(mv_output_writer)
    {
        m_help_string = "\n Help : \n - " + Command<add_track>::name() + " \'track name\'\n - " + Command<remove_track>::name() + " \'track index\'";
        for (const auto iv_command_string_view : getCommandNames())
        {
            m_help_string.append("\n - ");
            m_help_string.append(iv_command_string_view);
        }
        m_output_writer.display_message("Type : " + m_help + " to display again : " + m_help_string);
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
        else if (iv_command_str == Command<add_track>::name())
        {
            // If "add track" command is entered, get the track name from input and return an AddTrackCommand object
            std::string iv_track_name;
            iss >> iv_track_name;
            return std::make_shared<add_track>(iv_track_name);
        }
        else if (iv_command_str == Command<add_all_tracks>::name())
        {
            // If "add_all_track" command is entered, return a RemoveTrackCommand object
            return std::make_shared<add_all_tracks>();
        }
        else if (iv_command_str == Command<remove_track>::name())
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
                return std::make_shared<remove_track>(iv_track_index);
            }
        }
        else if (iv_command_str == Command<remove_duplicates>::name())
        {
            // If "remove duplicates" command is entered, return a RemoveDuplicatesCommand object
            return std::make_shared<remove_duplicates>();
        }
        //-----------------------------------------------------------------------------
        else if (iv_command_str == Command<play_pause>::name())
        {
            // If "play/pause" command is entered, return a PlayPauseCommand object
            return std::make_shared<play_pause>();
        }
        else if (iv_command_str == Command<stop>::name())
        {
            // If "stop" command is entered, return a StopCommand object
            return std::make_shared<stop>();
        }
        else if (iv_command_str == Command<next>::name())
        {
            // If "next" command is entered, return a NextCommand object
            return std::make_shared<next>();
        }
        else if (iv_command_str == Command<previous>::name())
        {
            // If "previous" command is entered, return a PreviousCommand object
            return std::make_shared<previous>();
        }
        //-----------------------------------------------------------------------------
        else if (iv_command_str == Command<random>::name())
        {
            // If "random" command is entered, return a RandomCommand object
            return std::make_shared<random>();
        }
        else if (iv_command_str == Command<repeat>::name())
        {
            // If "repeat" command is entered, return a RepeatCommand object
            return std::make_shared<repeat>();
        }
        //-----------------------------------------------------------------------------
        else if (iv_command_str == Command<show_track>::name())
        {
            // If "show_track" command is entered, return a RandomCommand object
            return std::make_shared<show_track>();
        }
        else if (iv_command_str == Command<show_playlist>::name())
        {
            // If "show_playlist" command is entered, return a RandomCommand object
            return std::make_shared<show_playlist>();
        }
        else if (iv_command_str == Command<end>::name())
        {
            // If "end" command is entered, return a EndCommand object
            m_output_writer.display_message("Exit Player");
            return std::make_shared<end>();
        }
        else
        { // If the command does not find a case in which it can be interpreted it will return nullptr

            m_output_writer.display_message("Unknown command, try again");
        }

        return nullptr;
    }
}
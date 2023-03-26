#include "InputManager.hpp"
namespace AudioPlayer
{

    InputManager::InputManager(const IOutputWriter &mv_output_writer) : m_output_writer(mv_output_writer)
    {
        m_help_string = "\n Help : \n - " + m_add_track + " \'track name\'\n - " + m_remove_track + " \'track index\'\n - " + m_remove_duplicates + "\n - " + m_play_pause + "\n - " + m_stop + "\n - " + "\n - " + m_next + "\n - " + m_previous + "\n - " + m_random + "\n - " + m_repeat + "\n - " + m_show_track + "\n - " + m_show_playlist;
        m_output_writer.display_message("Type : \"" + m_help + "\" to display again : " + m_help_string);
    }
    CommandVariant InputManager::input() const
    {
        std::string iv_first_input;
        std::string parameter;

        std::cin >> iv_first_input;
        if (iv_first_input != "end") // will return nullptr
        {
            if (iv_first_input == "help")
            {
                m_output_writer.display_message(m_help_string);
            }
            else if (iv_first_input == m_add_track)
            {
                std::string iv_second_input;
                std::cin >> iv_second_input; // read of the second parameter
                return std::make_shared<AddTrackCommand>(iv_second_input);
            }
            else if (iv_first_input == m_remove_track)
            {
                return std::make_shared<RemoveTrackCommand>();
            }
            else if (iv_first_input == m_remove_duplicates)
            {
                return std::make_shared<RemoveDuplicatesCommand>();
            }
            //-----------------------------------------------------------------------------
            else if (iv_first_input == m_play_pause)
            {
                return std::make_shared<PlayPauseCommand>();
            }
            else if (iv_first_input == m_stop)
            {
                return std::make_shared<PlayPauseCommand>();
            }
            else if (iv_first_input == m_next)
            {
                return std::make_shared<NextCommand>();
            }
            else if (iv_first_input == m_previous)
            {
                return std::make_shared<PreviousCommand>();
            }
            //-----------------------------------------------------------------------------
            else if (iv_first_input == m_random)
            {
                return std::make_shared<RandomCommand>();
            }
            else if (iv_first_input == m_repeat)
            {
                return std::make_shared<RepeatCommand>();
            }
            //-----------------------------------------------------------------------------
            else if (iv_first_input == m_show_track)
            {
                return std::make_shared<ShowTrackCommand>();
            }
            else if (iv_first_input == m_show_playlist)
            {
                return std::make_shared<ShowPlaylistCommand>();
            }
            else
            {
                m_output_writer.display_message("Unknown command, try again");

                input();
            }
        }
        else
        {
            m_output_writer.display_message("Exit Player");
        }
        return nullptr;
    }
}
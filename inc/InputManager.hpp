#ifndef INPUT_MANAGER_HPP // include guard
#define INPUT_MANAGER_HPP
#include <memory>
#include <iostream>
#include "IOutputWriter.hpp"

#include "Command.hpp"
namespace AudioPlayer
{

    class InputManager
    {
    public:
        /**
         *
         */
        CommandVariant input() const;

        InputManager(const IOutputWriter &m_output_writer);

    private:
        const IOutputWriter &m_output_writer;
        std::string m_help_string;
        const std::string m_help = "help";
        const std::string m_end = "end";
        const std::string m_add_track = "add_track";
        const std::string m_remove_track = "remove_track";
        const std::string m_remove_duplicates = "remove_duplicates";
        const std::string m_play_pause = "play_pause";
        const std::string m_stop = "stop";
        const std::string m_next = "next";
        const std::string m_previous = "previous";
        const std::string m_random = "random";
        const std::string m_repeat = "repeat";
        const std::string m_show_track = "show_track";
        const std::string m_show_playlist = "show_playlist";
    };
}
#endif
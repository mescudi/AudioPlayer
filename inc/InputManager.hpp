#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <memory>
#include <iostream>
#include "IOutputWriter.hpp"

#include "Command.hpp"

namespace AudioPlayer
{

    /**
     * @brief Class for managing input commands from the user
     */
    class InputManager
    {
    public:
        /**
         * @brief Get the user input as a CommandVariant object
         *
         * @return A CommandVariant object representing the user input
         */
        CommandVariant input() const;

        /**
         * @brief Construct a new Input Manager object
         *
         * @param m_output_writer The output writer to use for displaying messages
         */
        InputManager(const IOutputWriter &m_output_writer);

    private:
        const IOutputWriter &m_output_writer;                        ///< The output writer to use for displaying messages
        std::string m_help_string;                                   ///< The help message string
        const std::string m_help = "help";                           ///< The command string for displaying the help message
        const std::string m_end = "end";                             ///< The command string for ending the player
        const std::string m_add_track = "add_track";                 ///< The command string for adding a track
        const std::string m_remove_track = "remove_track";           ///< The command string for removing a track
        const std::string m_remove_duplicates = "remove_duplicates"; ///< The command string for removing duplicate tracks
        const std::string m_play_pause = "play_pause";               ///< The command string for toggling between playing and pausing
        const std::string m_stop = "stop";                           ///< The command string for stopping playback
        const std::string m_next = "next";                           ///< The command string for skipping to the next track
        const std::string m_previous = "previous";                   ///< The command string for going back to the previous track
        const std::string m_random = "random";                       ///< The command string for toggling random playback
        const std::string m_repeat = "repeat";                       ///< The command string for toggling repeat playback
        const std::string m_show_track = "show_track";               ///< The command string for showing the current track information
        const std::string m_show_playlist = "show_playlist";         ///< The command string for showing the current playlist information
    };
}

#endif

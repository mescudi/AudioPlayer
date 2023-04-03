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
        const IOutputWriter &m_output_writer; ///< The output writer to use for displaying messages
        std::string m_help_string;            ///< The help message string
        const std::string m_help = "help";    ///< The command string for displaying the help message
    };
}

#endif

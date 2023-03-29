#ifndef IPLAYER_MANAGER_HPP // include guard
#define IPLAYER_MANAGER_HPP

#include "Command.hpp"
#include <memory>

namespace AudioPlayer
{

    /**
     * @brief The interface for the player manager class that processes user input
     */
    class IPlayerManager
    {
    public:
        /**
         * @brief Processes the given command
         *
         * @param command The command to be processed
         */
        virtual void process_command(CommandVariant command) = 0;

        /**
         * @brief Virtual destructor
         */
        virtual ~IPlayerManager(){};
    };

}
#endif
#ifndef IPLAYER_MANAGER_HPP // include guard
#define IPLAYER_MANAGER_HPP

#include "Command.hpp"
#include <memory>

namespace AudioPlayer
{
    class IPlayerManager
    {
    public:
        virtual void process_command(std::shared_ptr<const Command>) = 0;
        virtual ~IPlayerManager(){};
    };
}
#endif
#ifndef INPUT_MANAGER_HPP // include guard
#define INPUT_MANAGER_HPP
#include <memory>
#include <iostream>

#include "Command.hpp"
namespace AudioPlayer
{

    class InputManager
    {
    public:
        /**
         *
         */
        std::shared_ptr<Command> input() const;
    };
}
#endif
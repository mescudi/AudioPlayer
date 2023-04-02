
#ifndef PLAYER_HPP // include guard
#define PLAYER_HPP
#include "PlayerManager.hpp"
#include "OutputWriter.hpp"
#include "InputManager.hpp"

namespace AudioPlayer
{

    /*
    @brief Enter point of the soft
    */
    class Player
    {
    public:
        void run();
    };
} // namespace AudioPlayer

#endif
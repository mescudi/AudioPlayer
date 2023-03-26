#ifndef PLAYER_HPP // include guard
#define PLAYER_HPP
#include "InputManager.hpp"
#include "PlayerManager.hpp"
#include "OutputWriter.hpp"

namespace AudioPlayer
{

    class Player
    {
    public:
        void run()
        {
            OutputWriter iv_output_writer;
            iv_output_writer.display_message(" Welcome on Player");
            InputManager input_manager(iv_output_writer);
            PlayerManager player_manager; // passage en parametre du outputWriter

            while (true)
            {
                auto command = input_manager.input();
                if (std::get_if<std::nullptr_t>(&command))
                {
                    break;
                }
                player_manager.process_command(command);
            }
        }
    };
}
#endif
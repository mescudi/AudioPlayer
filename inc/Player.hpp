
#ifndef PLAYER_HPP // include guard
#define PLAYER_HPP
#include "PlayerManager.hpp"
#include "OutputWriter.hpp"
#include "InputManager.hpp"

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
            PlayerManager player_manager(iv_output_writer); // passage en parametre du outputWriter

            CommandVariant iv_command = nullptr;
            while (player_manager.is_running())
            {
                do
                { // quand imput vaut nullptr c'est que commande pas comprise
                    iv_command = input_manager.input();
                } while (std::get_if<std::nullptr_t>(&iv_command)); // while command = to a Command
                // it is egal to a command, process command
                player_manager.process_command(iv_command);
            }
        }
    };
} // namespace AudioPlayer

#endif
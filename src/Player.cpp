
#include "Player.hpp"

namespace AudioPlayer
{

    void Player::run()
    {
        OutputWriter iv_output_writer;
        iv_output_writer.display_message(" Welcome on Player");
        InputManager input_manager(iv_output_writer);
        PlayerManager player_manager(iv_output_writer);

        CommandVariant iv_command = nullptr;

        while (player_manager.is_running()) // while running we continue the loop ask for input/ process
        {

            do
            { // when iv_command == nullptr it is unknown command
                iv_command = input_manager.input();

            } while (std::get_if<std::nullptr_t>(&iv_command)); // while command == we ask again till it return a command different from nullptr
            // it is egal to a known command, process command
            player_manager.process_command(iv_command);
        }
    }

} // namespace AudioPlayer

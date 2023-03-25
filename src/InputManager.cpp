#include "InputManager.hpp"
namespace AudioPlayer
{
    std::shared_ptr<Command> InputManager::input() const
    {
        std::shared_ptr<Command> iv_command;
        std::string iv_first_input;
        std::string parameter;

        std::cin >> iv_first_input;

        if (iv_first_input == "help")
        {
        }
        else if (iv_first_input == "add_track")
        {
            std::string iv_second_input;
            std::cin >> iv_second_input; // read of the second parameter
            // iv_command = std::make_shared<AddTrackCommand>(iv_second_input);
        }
        else if (iv_first_input == "remove_track")
        {
            iv_command = std::make_shared<RemoveTrackCommand>();
        }
        else if (iv_first_input == "remove_duplicates")
        {
            iv_command = std::make_shared<RemoveDuplicatesCommand>();
        }
        //-----------------------------------------------------------------------------
        else if (iv_first_input == "play")
        {
            iv_command = std::make_shared<PlayPauseCommand>();
        }
        else if (iv_first_input == "next")
        {
            iv_command = std::make_shared<NextCommand>();
        }
        else if (iv_first_input == "previous")
        {
            iv_command = std::make_shared<PreviousCommand>();
        }
        //-----------------------------------------------------------------------------

        else if (iv_first_input == "random")
        {
            iv_command = std::make_shared<RandomCommand>();
        }
        else if (iv_first_input == "repeat")
        {
            iv_command = std::make_shared<RepeatCommand>();
        }
        //-----------------------------------------------------------------------------

        else if (iv_first_input == "show_track")
        {
            iv_command = std::make_shared<ShowTrackCommand>();
        }
        else if (iv_first_input == "show_playlist")
        {
            iv_command = std::make_shared<ShowPlaylistCommand>();
        }
        else
        {
            input();
        }
        return iv_command;
    }
}
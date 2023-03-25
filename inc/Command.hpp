#ifndef COMMAND_HPP // include guard
#define COMMAND_HPP
#include <iostream>
#include <variant>

#define DEFINE_COMMAND(commandName)               \
    class commandName : public Command            \
    {                                             \
    public:                                       \
        const std::string m_name = "commandName"; \
    };
;

namespace AudioPlayer
{

    class Command
    {
    public:
        virtual ~Command(){};
    };

    class AddTrackCommand : public Command
    {
    public:
        const std::string m_name = "AddTrackCommand"; // TODO definir a la compilation

        std::string m_track_name;
    };

    DEFINE_COMMAND(RemoveTrackCommand);
    DEFINE_COMMAND(RemoveDuplicatesCommand);

    DEFINE_COMMAND(PlayPauseCommand);
    DEFINE_COMMAND(NextCommand);
    DEFINE_COMMAND(PreviousCommand);

    DEFINE_COMMAND(RandomCommand);
    DEFINE_COMMAND(RepeatCommand);
    DEFINE_COMMAND(ShowTrackCommand);
    DEFINE_COMMAND(ShowPlaylistCommand);

    using CommandVariant = std::variant<
        std::shared_ptr<const Command>,
        std::shared_ptr<const AddTrackCommand>,
        std::shared_ptr<const RemoveTrackCommand>,
        std::shared_ptr<const RemoveDuplicatesCommand>,
        std::shared_ptr<const PlayPauseCommand>,
        std::shared_ptr<const NextCommand>,
        std::shared_ptr<const PreviousCommand>,
        std::shared_ptr<const RandomCommand>,
        std::shared_ptr<const RepeatCommand>,
        std::shared_ptr<const ShowTrackCommand>,
        std::shared_ptr<const ShowPlaylistCommand>>;
}

#endif
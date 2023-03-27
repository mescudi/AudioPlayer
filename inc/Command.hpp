#ifndef COMMAND_HPP // include guard
#define COMMAND_HPP
#include <iostream>
#include <variant>

#define DEFINE_COMMAND(commandName)              \
    class commandName                            \
    {                                            \
    public:                                      \
        const std::string m_name = #commandName; \
    };

namespace AudioPlayer
{

    class AddTrackCommand
    {
    public:
        AddTrackCommand(std::string &mv_track_name) : m_track_name(mv_track_name) {}
        const std::string m_name = "AddTrackCommand"; // TODO definir a la compilation

        std::string m_track_name;
    };

    DEFINE_COMMAND(EndCommand);
    DEFINE_COMMAND(RemoveTrackCommand);
    DEFINE_COMMAND(RemoveDuplicatesCommand);

    DEFINE_COMMAND(PlayPauseCommand);
    DEFINE_COMMAND(StopCommand);

    DEFINE_COMMAND(NextCommand);
    DEFINE_COMMAND(PreviousCommand);

    DEFINE_COMMAND(RandomCommand);
    DEFINE_COMMAND(RepeatCommand);
    DEFINE_COMMAND(ShowTrackCommand);
    DEFINE_COMMAND(ShowPlaylistCommand);

    using CommandVariant = std::variant<
        std::nullptr_t,
        std::shared_ptr<const AddTrackCommand>,
        std::shared_ptr<const RemoveTrackCommand>,
        std::shared_ptr<const RemoveDuplicatesCommand>,
        std::shared_ptr<const PlayPauseCommand>,
        std::shared_ptr<const StopCommand>,
        std::shared_ptr<const NextCommand>,
        std::shared_ptr<const PreviousCommand>,
        std::shared_ptr<const RandomCommand>,
        std::shared_ptr<const EndCommand>,
        std::shared_ptr<const RepeatCommand>,
        std::shared_ptr<const ShowTrackCommand>,
        std::shared_ptr<const ShowPlaylistCommand>>;
}

#endif
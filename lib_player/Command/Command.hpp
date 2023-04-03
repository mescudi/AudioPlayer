#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <variant>
#include <memory>

namespace AudioPlayer
{

    template <typename T>
    class CommandBase
    {
    public:
        CommandBase() : m_name("CommandBase") {}
        explicit CommandBase(const std::string &name) : m_name(name) {}
        virtual ~CommandBase() = default;
        std::string m_name;
    };

    template <typename T>
    class Command : public CommandBase<T>
    {
    public:
        Command() : CommandBase<T>(typeid(T).name()) {}
        explicit Command(const std::string &name) : CommandBase<T>(name) {}
    };

#define DEFINE_COMMAND(commandName)                 \
    class commandName : public Command<commandName> \
    {                                               \
    public:                                         \
        using Command<commandName>::Command;        \
    };

    DEFINE_COMMAND(EndCommand);
    DEFINE_COMMAND(AddAllTracksCommand);
    DEFINE_COMMAND(RemoveDuplicatesCommand);
    DEFINE_COMMAND(PlayPauseCommand);
    DEFINE_COMMAND(StopCommand);
    DEFINE_COMMAND(NextCommand);
    DEFINE_COMMAND(PreviousCommand);
    DEFINE_COMMAND(RandomCommand);
    DEFINE_COMMAND(RepeatCommand);
    DEFINE_COMMAND(ShowTrackCommand);
    DEFINE_COMMAND(ShowPlaylistCommand);

    class AddTrackCommand : public Command<AddTrackCommand>
    {
    public:
        AddTrackCommand(const std::string &mv_track_name) : Command<AddTrackCommand>(), m_track_name(mv_track_name) {}
        std::string m_track_name;
    };

    class RemoveTrackCommand : public Command<RemoveTrackCommand>
    {
    public:
        RemoveTrackCommand(uint32_t mv_track_number) : Command<RemoveTrackCommand>(), m_track_number(mv_track_number) {}
        uint32_t m_track_number;
    };

    using CommandVariant = std::variant<
        std::nullptr_t,
        std::shared_ptr<const AddTrackCommand>,
        std::shared_ptr<const AddAllTracksCommand>,
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

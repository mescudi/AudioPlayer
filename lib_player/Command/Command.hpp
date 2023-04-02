
#ifndef COMMAND_HPP
#define COMMAND_HPP
/**

@file Command.hpp
@brief This file contains the declaration of the Command class and its related classes.
*/
#include <iostream>
#include <variant>
#include <memory>

/**

*@brief The namespace containing all classes related to the AudioPlayer system.
*/
namespace AudioPlayer
{
    /*

    *@brief The RemoveTrackCommand class represents a command to add a track to the playlist.
    */
    class RemoveTrackCommand
    {
    public:
        /*

        @brief Construct a newRemoveTrackCommand object.
        @param mv_track_index The index of the track to remove from the playlist.
        */
        RemoveTrackCommand(uint32_t mv_track_number) : m_track_number(mv_track_number) {}
        const std::string m_name = "RemoveTrackCommand"; /*!< The name of the command. */
        uint32_t m_track_number;                         /*!< The name of the track to add to the playlist. */
    };

    /*

    *@brief The AddTrackCommand class represents a command to add a track to the playlist.
    */
    class AddTrackCommand
    {
    public:
        /*

        @brief Construct a new AddTrackCommand object.
        @param mv_track_name The name of the track to add to the playlist.
        */
        AddTrackCommand(std::string &mv_track_name) : m_track_name(mv_track_name) {}
        const std::string m_name = "AddTrackCommand"; /*!< The name of the command. */
        std::string m_track_name;                     /*!< The name of the track to add to the playlist. */
    };
/**
 *@brief Macro to define a command class with its name as the macro argument.
 */
#define DEFINE_COMMAND(commandName)              \
    class commandName                            \
    {                                            \
    public:                                      \
        const std::string m_name = #commandName; \
    };
    DEFINE_COMMAND(EndCommand);              /*!< The command to end the AudioPlayer. */
    DEFINE_COMMAND(AddAllTracksCommand);     /*!< The command to end the AudioPlayer. */
    DEFINE_COMMAND(RemoveDuplicatesCommand); /**< The command to remove duplicate tracks from the playlist. */

    DEFINE_COMMAND(PlayPauseCommand); /*!< The command to play or pause the current track. */
    DEFINE_COMMAND(StopCommand);      /*!< The command to stop the AudioPlayer. */

    DEFINE_COMMAND(NextCommand);     /*!< The command to play the next track in the playlist. */
    DEFINE_COMMAND(PreviousCommand); /*!< The command to play the previous track in the playlist. */

    DEFINE_COMMAND(RandomCommand);       /*!< The command to play a random track from the playlist. */
    DEFINE_COMMAND(RepeatCommand);       /*!< The command to repeat the current track. */
    DEFINE_COMMAND(ShowTrackCommand);    /*!< The command to show the details of the current track. */
    DEFINE_COMMAND(ShowPlaylistCommand); /*!< The command to show the tracks in the playlist. */

    /**
     *@brief A variant type to store all possible command types.
     **/
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
#ifndef IPLAYER_CONTEXT_HPP // include guard
#define IPLAYER_CONTEXT_HPP
#include <iostream>
/**
 * @class IPlayerContext
 * @brief Interface for the audio player context.
 */
class IPlayerContext
{
public:
    /**
     * @brief Gets the name of the current track being played.
     * @return The name of the current track being played.
     */
    virtual std::string get_current_track_name() const = 0;

    /**
     * @brief Sets the name of the current track being played.
     * @param m_current_track_name The name of the current track being played.
     */
    virtual void set_current_track_name(const std::string &m_current_track_name) = 0;

    /**
     * @brief Determines whether there is a track to play.
     * @return True if there is a track to play, false otherwise.
     */
    virtual bool is_there_track_to_play() = 0;

    /**
     * @brief Destructor.
     */
    virtual ~IPlayerContext(){};
};
#endif
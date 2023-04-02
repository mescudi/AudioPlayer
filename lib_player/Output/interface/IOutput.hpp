#ifndef IOUTPUT_HPP // include guard
#define IOUTPUT_HPP

#include <iostream>

namespace AudioPlayer
{
    /**
     * @brief Abstract interface for output related functions of the audio player
     *
     */
    class IOutput
    {
    public:
        /**
         * @brief Displays a message to the user
         *
         * @param mv_message the message to be displayed
         */
        virtual void display_message(const std::string &mv_message) const = 0;

        /**
         * @brief Displays the currently playing track
         *
         */
        // virtual void display_track() const = 0;

        /**
         * @brief Displays a message that a track has been added to the playlist
         *
         * @param mv_track_name the name of the track that was added
         */
        // virtual void display_added_track(const std::string &mv_track_name) const = 0;

        /**
         * @brief Displays a message that the audio player has started playing
         *
         */
        virtual void display_started() const = 0;

        /**
         * @brief Displays a message that the audio player has stopped playing
         *
         */
        virtual void display_stopped() const = 0;

        /**
         * @brief Displays a message that the audio player has paused playback
         *
         */
        virtual void display_paused() const = 0;

        /**
         * @brief Displays a message that the audio player has resumed playback
         *
         */
        virtual void display_resumed() const = 0;

        /**
         * @brief Displays a message that the audio player is repeating playback
         *
         */
        virtual void display_repeat() const = 0;

        /**
         * @brief Displays a message that the audio player is shuffling playback
         *
         */
        virtual void display_random() const = 0;

        /**
         * @brief Virtual destructor to ensure proper cleanup of derived classes
         *
         */
        virtual ~IOutput(){};
    };
}

#endif

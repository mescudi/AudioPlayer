#ifndef IPLAYER_EXECUTOR_HPP // include guard
#define IPLAYER_EXECUTOR_HPP
#include <iostream>
namespace AudioPlayer
{
    /**
     * @brief Interface of the logical functions of the player
     */
    class IPlayerExecutor
    {
    public:
        ~IPlayerExecutor(){};

        /**
         * @brief Starts playing the current track.
         */
        virtual void start() = 0;

        /**
         * @brief Stops the player.
         */
        virtual void stop() = 0;

        /**
         * @brief Pauses the player.
         */
        virtual void pause() = 0;

        /**
         * @brief Resumes playing the current track.
         */
        virtual void resume() = 0;

        /**
         * @brief Adds a track to the playlist.
         *
         * @param mv_string The string representing the track to be added.
         */
        virtual void add_track_to_playlist(const std::string &mv_string) = 0;

        /**
         * @brief Removes a track from the playlist.
         *
         * @param track_id The id of the track to be removed.
         */
        virtual void remove_track(uint32_t track_id) = 0;

        /**
         * @brief Removes duplicate tracks from the playlist.
         */
        virtual void remove_duplicates() = 0;

        /**
         * @brief Shows information about the current track.
         */
        virtual void show_track() = 0;

        /**
         * @brief Shows information about the playlist.
         */
        virtual void show_playlist() = 0;

        /**
         * @brief Sets the previous track as the current track.
         */
        virtual void set_previous_track() = 0;

        /**
         * @brief Sets the next track as the current track.
         */
        virtual void set_next_track() = 0;

        /**
         * @brief Sets a random track as the current track.
         */
        virtual void set_random_track() = 0;

        /**
         * @brief Plays the same track again.
         */
        virtual void set_same_track() = 0;
    };

}

#endif
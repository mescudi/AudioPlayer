#ifndef PLAYER_CONTEXT_HPP // include guard
#define PLAYER_CONTEXT_HPP
#include <iostream>
#include "IPlayerContext.hpp"
#include "IConfigSystemFiles.hpp"

namespace AudioPlayer
{
    /*!
     *class AudioPlayer::OutputWriter
     *brief A class that provides an implementation of the IOutputWriter interface to write output messages.
     */
    class PlayerContext : public IPlayerContext
    {
    public:
        /**
         * @brief Constructor for the PlayerContext class.
         */
        PlayerContext();
        /**
         * @brief Virtual destructor for the PlayerContext class.
         */
        virtual ~PlayerContext(){};

        // PlayingMode get_playing_mode() const override;
        // void set_playing_mode(const PlayingMode &mv_playing_mode);

        /**
         * @brief Returns the name of the current audio track.
         * @return The name of the current audio track.
         */
        std::string get_current_track_name() const override;

        /**
         * @brief Sets the name of the current audio track.
         * @param mv_current_track_name The name of the current audio track.
         */
        void set_current_track_name(const std::string &mv_current_track_name) override;

        /**
         * @brief Determines whether there is a track to play or not.
         * @return True if there is a track to play, false otherwise.
         */
        bool is_there_track_to_play() override;

    private:
        std::string m_current_track_name; ///< The name of the current audio track.
    };

}

#endif
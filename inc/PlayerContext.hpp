#ifndef PLAYER_CONTEXT_HPP // include guard
#define PLAYER_CONTEXT_HPP
#include <iostream>
#include "IPlayerContext.hpp"
#include "IConfigSystemFiles.hpp"

namespace AudioPlayer
{
    class PlayerContext : public IPlayerContext
    {
    public:
        PlayerContext();
        PlayingMode get_playing_mode() const override;
        void set_playing_mode(const PlayingMode &mv_playing_mode);

        std::string get_current_track_name() const override;
        void set_current_track_name(const std::string &mv_current_track_name) override;

        uint32_t get_current_track_index() const override;
        void set_current_track_index(uint32_t m_current_track_index) override;

    private:
        PlayingMode m_playing_mode;
        std::string m_current_track_name;
        uint32_t m_current_track_index;
    };
}

#endif
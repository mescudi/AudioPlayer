#include "PlayerContext.hpp"

namespace AudioPlayer
{

    PlayerContext::PlayerContext() : m_playing_mode(PlayingMode::Normal), m_current_track_name(""), m_current_track_index(0)
    {
    }
    PlayingMode PlayerContext::get_playing_mode() const
    {
        return m_playing_mode;
    }
    void PlayerContext::set_playing_mode(const PlayingMode &mv_playing_mode)
    {
        m_playing_mode = mv_playing_mode;
    };

    std::string PlayerContext::get_current_track_name() const
    {
        return m_current_track_name;
    }
    void PlayerContext::set_current_track_name(const std::string &mv_current_track_name)
    {
        m_current_track_name = mv_current_track_name;
    }

    uint32_t PlayerContext::get_current_track_index() const
    {
        return m_current_track_index;
    }
    void PlayerContext::set_current_track_index(uint32_t mv_current_track_index)
    {
        m_current_track_index = mv_current_track_index;
    }

}

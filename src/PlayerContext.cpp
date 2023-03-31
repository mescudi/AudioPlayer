#include "PlayerContext.hpp"

namespace AudioPlayer
{

    PlayerContext::PlayerContext() : m_current_track_name("") // current track initialized to "" before a  track is added
    {
    }
    // PlayingMode PlayerContext::get_playing_mode() const
    // {
    //     return m_playing_mode;
    // }
    // void PlayerContext::set_playing_mode(const PlayingMode &mv_playing_mode)
    // {
    //     m_playing_mode = mv_playing_mode;
    // };

    std::string PlayerContext::get_current_track_name() const
    {
        return m_current_track_name;
    }
    void PlayerContext::set_current_track_name(const std::string &mv_current_track_name)
    {
        m_current_track_name = mv_current_track_name;
    }

    bool PlayerContext::is_there_track_to_play()
    {
        return (get_current_track_name() != ""); // if "" is the current string name of the track no track has been added
    }

}

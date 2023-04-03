#include "Track.hpp"

namespace AudioPlayer
{
    bool Track::operator==(const Track &other) const
    {
        return m_track_name == other.m_track_name;
    }
}
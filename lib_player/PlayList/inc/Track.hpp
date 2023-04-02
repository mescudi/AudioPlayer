#ifndef TRACK_HPP // include guard
#define TRACK_HPP
#include <string>

namespace AudioPlayer
{
    struct Track
    {
        Track(std::string mv_track_name) : m_track_name(mv_track_name)
        {
        }
        std::string m_track_name;
    };

}
#endif
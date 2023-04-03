#ifndef TRACK_HPP // include guard
#define TRACK_HPP
#include <string>
#pragma once

namespace AudioPlayer
{
    struct Track
    {
        Track(const std::string &mv_track_name) : m_track_name(mv_track_name)
        {
        }
        std::string m_track_name;

        bool operator==(const Track &other) const;
    };

    class TrackHash
    {
    public:
        size_t operator()(const Track &t) const
        {
            return std::hash<std::string>()(t.m_track_name);
        }
    };

}
#endif
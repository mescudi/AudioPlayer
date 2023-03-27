#ifndef IPLAYER_CONTEXT_HPP // include guard
#define IPLAYER_CONTEXT_HPP
#include <iostream>
namespace AudioPlayer
{
    enum class PlayingMode
    {
        Random,
        Repeat,
        Normal
    };

    class IPlayerContext // TODO sortir
    {
    public:
        virtual PlayingMode get_playing_mode() const = 0;
        virtual void set_playing_mode(const PlayingMode &) = 0;

        virtual std::string get_current_track_name() const = 0;
        virtual void set_current_track_name(const std::string &) = 0;

        virtual uint32_t get_current_track_index() const = 0;
        virtual void set_current_track_index(uint32_t m_current_track_index) = 0;
        virtual bool is_there_track_to_play() = 0;
        virtual ~IPlayerContext(){};
    };
}
#endif
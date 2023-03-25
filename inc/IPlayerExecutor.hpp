#ifndef IPLAYER_EXECUTOR_HPP // include guard
#define IPLAYER_EXECUTOR_HPP
#include <iostream>
namespace AudioPlayer
{
    class IPlayerExecutor
    {
    public:
        ~IPlayerExecutor(){};

        virtual void start() = 0;
        virtual void stop() = 0;
        virtual void pause() = 0;
        virtual void resume() = 0;
        virtual void next() = 0;
        virtual void previous() = 0;

        // command that does not interfer with machine state
        virtual void add_track_to_playlist(const std::string &mv_string) = 0;
        virtual void remove_track(uint32_t) = 0;
        virtual void remove_duplicates() = 0;

        virtual void random() = 0;
        virtual void repeat() = 0;
        virtual void show_track() = 0;
        virtual void show_playlist() = 0;
    };
}
#endif
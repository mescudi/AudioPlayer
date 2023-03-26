#ifndef IOUTPUT_HPP // include guard
#define IOUTPUT_HPP
#include <iostream>
namespace AudioPlayer
{
    class IOutput
    {

    public:
        virtual void display_message(const std::string &mv_message) const = 0;
        // virtual void display_track() const = 0;
        // virtual void display_added_track(const std::string &mv_track_name) const = 0;
        virtual void display_started() const = 0;
        virtual void display_stopped() const = 0;
        // virtual void display_resume() const = 0;
        // virtual void display_playlist(const std::vector<std::string> &) const = 0;
        virtual void display_repeat() const = 0;
        virtual void display_random() const = 0;

        virtual ~IOutput(){};
    };

}
#endif
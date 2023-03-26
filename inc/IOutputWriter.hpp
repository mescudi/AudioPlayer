#ifndef IOUTPUT_WRITER_HPP // include guard
#define IOUTPUT_WRITER_HPP
#include <iostream>
namespace AudioPlayer
{
    class IOutputWriter
    {

    public:
        virtual void display_message(const std::string &mv_message) const = 0;

        virtual ~IOutputWriter(){};
    };

}
#endif
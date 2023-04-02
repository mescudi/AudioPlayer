#ifndef IOUTPUT_WRITER_HPP // include guard
#define IOUTPUT_WRITER_HPP
#include <iostream>
namespace AudioPlayer
{
    /**
     * @brief Abstract interface to display a message to the user
     *
     */
    class IOutputWriter
    {

    public:
            /**
         *@brief Displays a message to the output device.
         * @param mv_message The message to be displayed.
         */
        virtual void display_message(const std::string &mv_message) const = 0;

        virtual ~IOutputWriter(){};
    };

}
#endif
#ifndef OUTPUT_WRITER_HPP // include guard
#define OUTPUT_WRITER_HPP
#include "IOutputWriter.hpp"
#include <vector>

namespace AudioPlayer
{
    class OutputWriter : public IOutputWriter
    {

    public:
        OutputWriter();

        void display_message(const std::string &mv_message) const override;
    };
}

#endif
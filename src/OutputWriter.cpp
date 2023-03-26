#include "OutputWriter.hpp"
namespace AudioPlayer
{

    OutputWriter::OutputWriter()

    {
    }

    void OutputWriter::display_message(const std::string &mv_message) const
    {
        std::cout << mv_message << std::endl;
    }
}
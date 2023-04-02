#include "OutputWriter.hpp"
namespace AudioPlayer
{

    OutputWriter::OutputWriter()

    {
    }
    // Output implementation of Player uses the console to display messages
    void OutputWriter::display_message(const std::string &mv_message) const
    {
        std::cout << mv_message << std::endl;
    }
}
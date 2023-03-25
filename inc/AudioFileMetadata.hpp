#ifndef AUDIO_FILE_META_HPP // include guard
#define AUDIO_FILE_META_HPP

#include <chrono>
namespace SystemFiles
{

    struct AudioFileMetadata // Templatiser
    {
        // std::chrono::seconds m_seconds; // TODO
        int m_seconds;
        std::string m_codec;
        std::string m_title;
    };
}
#endif
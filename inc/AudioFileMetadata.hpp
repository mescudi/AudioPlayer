#ifndef AUDIO_FILE_META_HPP // include guard
#define AUDIO_FILE_META_HPP

#include <chrono>
#include <string>

namespace SystemFiles
{

    struct AudioFileMetadata // Templatiser
    {
        std::string m_duration;
        std::string m_codec;
        std::string m_title;
    };
}
#endif
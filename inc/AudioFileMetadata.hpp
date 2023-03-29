#ifndef AUDIO_FILE_META_HPP // include guard
#define AUDIO_FILE_META_HPP

#include <chrono>
#include <string>

/*
 *@brief The namespace SystemFiles contains classes and structures related to file management.
 */
namespace SystemFiles
{
    /*
     *@brief The AudioFileMetadata struct contains metadata information of an audio file.
     */
    struct AudioFileMetadata
    {
        std::string m_duration; /*!< The duration of the audio file.*/
        std::string m_codec;    /*!< The codec used to encode the audio file.*/
        std::string m_title;    /*!< The title of the audio file. */
    };
}

#endif
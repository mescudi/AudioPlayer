#ifndef CONFIG_SYSTEM_FILES_HPP // include guard
#define CONFIG_SYSTEM_FILES_HPP
#include <map>
#include <iostream>
#include "AudioFileMetadata.hpp"
#include "IConfigSystemFiles.hpp"

/**
 * To respond to the hard-coded parameters associated with tracks
 * I chose to hard-code the configuration in a header
 *
 * an other choice was to go with a json file and code a parser because only std is allowed
 * but I thought it was irrelevant to the exercise and I leave it as a future implementation
 */

namespace SystemFiles
{
    class ConfigSystemFiles : public IConfigSystemFiles
    {
    private:
        std::map<std::string, AudioFileMetadata> conf_map{
            {"01_intro.music", AudioFileMetadata{"1:20:15", "mp3", "Introduction"}},
            {"02_running.music", AudioFileMetadata{"00:13:14", "wav", "Running"}},
            {"03_suspens.music", AudioFileMetadata{"00:00:60", "Flac", "Suspens"}},
            {"04_end.music", AudioFileMetadata{"00:00:09", "mp3", "End"}}

        };

    public:
        std::map<std::string, AudioFileMetadata> getFileSystemMap() const override
        {
            return conf_map;
        }
    };
}
#endif
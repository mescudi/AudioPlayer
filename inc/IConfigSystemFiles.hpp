#ifndef ICONFIG_SYSTEM_FILES_HPP // include guard
#define ICONFIG_SYSTEM_FILES_HPP
#include <map>
#include <iostream>
#include "AudioFileMetadata.hpp"
/**
 * To respond to the hard-coded parameters associated with tracks
 * I chose to hard-code the configuration in a header
 *
 * an other choice was to go with a json file and code a parser because only std is allowed
 * but I thought it was irrelevant to the exercise and I leave it as a future implementation
 */

namespace SystemFiles
{
    class IConfigSystemFiles
    {
    public:
        virtual std::map<std::string, AudioFileMetadata> getFileSystemMap() const = 0;
        virtual ~IConfigSystemFiles(){};
    };
}
#endif
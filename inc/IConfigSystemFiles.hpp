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
    /**
     * @brief Interface for managing system configuration files.
     *
     * This interface provides methods for managing system configuration files and accessing metadata of recorded audio files.
     */
    class IConfigSystemFiles
    {
    public:
        /**
         * @brief Returns a copy of the file system map containing audio file metadata.
         *
         * This method returns a copy of the file system map that contains metadata for recorded audio files.
         *
         * @return A copy of the file system map containing audio file metadata.
         */
        virtual std::map<std::string, AudioFileMetadata> getFileSystemMap() const = 0;

        /**
         * @brief Destructor.
         *
         * This virtual destructor is needed to ensure proper cleanup of resources when working with interfaces.
         */
        virtual ~IConfigSystemFiles(){};
    };

}
#endif
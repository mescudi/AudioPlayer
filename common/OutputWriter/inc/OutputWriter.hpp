#ifndef OUTPUT_WRITER_HPP // Include guard
#define OUTPUT_WRITER_HPP

#include "IOutputWriter.hpp"
#include <vector>

namespace AudioPlayer
{
    /**
     * @brief A concrete implementation of the IOutputWriter interface
     *
     */
    class OutputWriter : public IOutputWriter
    {

    public:
        /**
         * @brief Constructor of OutputWriter
         *
         */
        OutputWriter();

        /**
         * @brief Virtual Destructor of  OutputWriter
         *
         */
        virtual ~OutputWriter(){};

        /**
         * @brief Displays a message to the user
         *
         * @param mv_message The message to be displayed
         */
        void display_message(const std::string &mv_message) const override;
    };
}

#endif

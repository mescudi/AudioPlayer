#ifndef OUTPUT_HPP // include guard
#define OUTPUT_HPP
#include "IOutput.hpp"
#include "IPlayerContext.hpp"
#include "IOutputWriter.hpp"

#include <vector>

namespace AudioPlayer
{
    /**
     * @brief Concrete implementation of the output related functions of the audio player
     *
     */
    class Output : public IOutput
    {

    public:
        /**
         * @brief Constructor that takes in a player context and an output writer
         *
         * @param player_context The context of the audio player
         * @param output_writer The output writer used to display messages
         */
        Output(const IPlayerContext &player_context, const IOutputWriter &output_writer);

        /**
         * @brief Virtual destructor to ensure proper cleanup of derived classes
         *
         */
        virtual ~Output(){};

        /**
         * @brief Displays a message to the user
         *
         * @param mv_message The message to be displayed
         */
        void display_message(const std::string &mv_message) const override;

        /**
         * @brief Displays a message that the audio player has started playing
         *
         */
        void display_started() const override;

        /**
         * @brief Displays a message that the audio player has stopped playing
         *
         */
        void display_stopped() const override;

        /**
         * @brief Displays a message that the audio player has paused playback
         *
         */
        void display_paused() const override;

        /**
         * @brief Displays a message that the audio player is repeating playback
         *
         */
        void display_repeat() const override;

        /**
         * @brief Displays a message that the audio player is randomazing the next and previous track
         *
         */
        void display_random() const override;

    private:
        const IPlayerContext &m_player_context; /*>! reference to the shared context*/
        const IOutputWriter &m_output_writer;   /*>! reference to the output writer*/
    };
}

#endif
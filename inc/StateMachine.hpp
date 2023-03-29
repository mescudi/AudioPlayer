#ifndef STATE_MACHINE_HPP // include guard
#define STATE_MACHINE_HPP
#include <variant>
#include "IPlayerExecutor.hpp"
#include "IPlayerContext.hpp"
#include "PlayingModeStrategy.hpp"

namespace AudioPlayer
{

    /**
     * @brief A structure representing the stopped state of the state machine
     */
    struct Stopped
    {
        /**
         * @brief Constructs a Stopped object and stops the player
         * @param executor The player executor object
         */
        Stopped(IPlayerExecutor &executor)
        {
            executor.stop();
        }
    };

    /**
     * @brief A structure representing the started state of the state machine
     */
    struct Started
    {
        /**
         * @brief Constructs a Started object and starts the player
         * @param executor The player executor object
         */
        Started(IPlayerExecutor &executor)
        {
            executor.start();
        }
    };

    /**
     * @brief A structure representing the paused state of the state machine
     */
    struct Paused
    {
        /**
         * @brief Constructs a Paused object and pauses the player
         * @param executor The player executor object
         */
        Paused(IPlayerExecutor &executor)
        {
            executor.pause();
        }
    };

    /**
     * @brief A variant representing the possible states of the state machine
     */
    using State = std::variant<
        Started,
        Stopped,
        Paused>;

    /**
     * @brief A variant representing the possible playing modes of the state machine
     */
    using PlayingMode = std::variant<
        NormalPlayingStrategy,
        RandomPlayingStrategy,
        RepeatPlayingStrategy>;

    /**
     * @brief The StateMachine class represents the state machine of the audio player
     */
    class StateMachine
    {
    public:
        /**
         * @brief Constructs a StateMachine object with a player executor and player context objects
         * @param mv_player_executor The player executor object
         * @param mv_context The player context object
         */
        StateMachine(IPlayerExecutor &mv_player_executor, IPlayerContext &mv_context);

        /**
         * @brief Stops the player and transitions to the Stopped state
         */
        void stop();

        /**
         * @brief Starts or pauses the player depending on the current state, and transitions to the appropriate state
         */
        void start_pause();

        /**
         * @brief Sets the player's playing mode to Random
         */
        void set_random();

        /**
         * @brief Sets the player's playing mode to Repeat
         */
        void set_repeat();

        /**
         * @brief Skips to the next track
         */
        void next();

        /**
         * @brief Skips to the previous track
         */
        void previous();

    private:
        State m_state;                               /**< The current state of the state machine */
        std::unique_ptr<PlayingMode> m_playing_mode; /**< The current playing mode of the state machine */

        IPlayerExecutor &m_executor; /**< The player executor object */
        IPlayerContext &m_context;   /**< The player context object */
    };

}
#endif
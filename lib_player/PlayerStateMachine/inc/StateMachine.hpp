#ifndef STATE_MACHINE_HPP // include guard
#define STATE_MACHINE_HPP
#include <variant>
#include "IPlayerExecutor.hpp"
#include "PlayingModeStrategy.hpp"

namespace AudioPlayer
{

    /**
     * @brief A structure representing the stopped state of the state machine
     */
    class Stopped
    {
    public:
        /**
         * @brief Constructs a Stopped object and stops the player
         */
        Stopped()
        {
        }

        void exec_stop(IPlayerExecutor &mv_executor)
        {
            mv_executor.stop();
        }
    };

    /**
     * @brief A structure representing the started state of the state machine
     */
    class Started
    {
    public:
        /**
         * @brief Constructs a Started object and starts the player
         */
        Started()
        {
        }

        void exec_start(IPlayerExecutor &mv_executor)
        {
            mv_executor.start();
        }

        void exec_resume(IPlayerExecutor &mv_executor)
        {
            mv_executor.resume();
        }
    };

    /**
     * @brief A structure representing the paused state of the state machine
     */
    class Paused
    {
    public:
        /**
         * @brief Constructs a Paused object and pauses the player
         */
        Paused()
        {
        }

        void exec_pause(IPlayerExecutor &mv_executor)
        {
            mv_executor.pause();
        }
    };

    /**
     * @brief A variant representing the possible states of the state machine
     */
    using State = std::variant<
        Started,
        Stopped,
        Paused>;
    /*
     *
     *@brief A variant representing the possible playing modes which are like states in the states machines
     */
    using PlayingModeStrategy = std::variant<
        NormalPlayingStrategy,
        RepeatPlayingStrategy,
        RandomPlayingStrategy>;

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
        StateMachine(IPlayerExecutor &mv_player_executor);

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

        /**
         * @brief Remove the track from the playlist
         * @param the number of the track
         */
        void remove_track(uint32_t);

    private:
        State m_state; /**< The current state of the state machine */

        PlayingModeStrategy m_playing_strategy; /**< The current playing mode of the state machine */

        IPlayerExecutor &m_executor; /**< The player executor object */
    };

}
#endif
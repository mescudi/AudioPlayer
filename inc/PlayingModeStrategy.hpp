#ifndef PLAYING_MODE_STRATEGY_EXECUTOR_HPP // include guard
#define PLAYING_MODE_STRATEGY_EXECUTOR_HPP
#include "PlayingMode.hpp"
#include "IPlayerExecutor.hpp"
#include <memory>
namespace AudioPlayer
{
    // class PlayingModeStrategy
    // {

    // public:
    //     virtual ~PlayingModeStrategy(){};
    //     PlayingModeStrategy(IPlayerExecutor &);

    // protected:
    //     IPlayerExecutor &m_executor;
    // };

    /**
     * @brief Implements the Normal playing strategy.
     */
    class NormalPlayingStrategy
    {

    public:
        NormalPlayingStrategy(std::shared_ptr<IPlayerExecutor>);
        /**
         * @brief Switches to the previous track in the playlist.
         */
        void previous();

        /**
         * @brief Switches to the next track in the playlist.
         */
        void next();

    private:
        std::shared_ptr<IPlayerExecutor> m_executor; /**< The executor to use for playing the tracks. */
    };

    /**
     * @brief Implements the Random playing strategy.
     */
    class RandomPlayingStrategy
    {
    public:
        /**
         * @brief Construct a new Random Playing Strategy object.
         *
         * @param executor The executor to use for playing the tracks.
         */
        RandomPlayingStrategy(std::shared_ptr<IPlayerExecutor> executor);

        /**
         * @brief Switches to a random track in the playlist.
         */
        void random();

    private:
        std::shared_ptr<IPlayerExecutor> m_executor; /**< The executor to use for playing the tracks. */
    };

    /**
     * @brief Implements the Repeat playing strategy.
     */
    class RepeatPlayingStrategy
    {
    public:
        /**
         *
         * @param executor The executor to use for playing the tracks.
         */
        RepeatPlayingStrategy(std::shared_ptr<IPlayerExecutor> executor);

        /**
         * @brief Repeats the current track.
         */
        void repeat_current();

    private:
        std::shared_ptr<IPlayerExecutor> m_executor; /**< The executor to use for playing the tracks. */
    };

}
#endif

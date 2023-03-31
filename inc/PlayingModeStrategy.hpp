#ifndef PLAYING_MODE_STRATEGY_HPP // include guard
#define PLAYING_MODE_STRATEGY_HPP
#include "IPlayerExecutor.hpp"
#include <memory>
/**
 * @brief This header defines all the PlayingModeStrategy and what
 *  happens when previous and next are called
 */
namespace AudioPlayer
{

    /**
     * @brief Implements the Normal playing strategy.
     */
    class NormalPlayingStrategy // : public PlayingModeStrategyAbstract
    {

    public:
        NormalPlayingStrategy();
        /**
         * @brief Switches to the previous track in the playlist.
         */
        void previous(IPlayerExecutor &);

        /**
         * @brief Switches to the next track in the playlist.
         */
        void next(IPlayerExecutor &);
    };

    /**
     * @brief Implements the Random playing strategy.
     */
    class RandomPlayingStrategy // : public PlayingModeStrategyAbstract
    {
    public:
        /**
         * @brief Constructor of Random Playing Strategy object.
         *

         */
        RandomPlayingStrategy();

        /**
         * @brief Switches to a random track in the playlist.
         */
        void next(IPlayerExecutor &);

        /**
         * @brief Switches to a random track in the playlist.
         */
        void previous(IPlayerExecutor &);
    };

    /**
     * @brief Implements the Repeat playing strategy.
     */
    class RepeatPlayingStrategy //: public PlayingModeStrategyAbstract
    {
    public:
        RepeatPlayingStrategy();

        /**
         * @brief Repeat the same track in the playlist.
         */
        void next(IPlayerExecutor &);

        /**
         * @brief Repeat the same track in the playlist.
         */
        void previous(IPlayerExecutor &);
    };
}
#endif

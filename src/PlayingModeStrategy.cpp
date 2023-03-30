
#include "PlayingModeStrategy.hpp"

namespace AudioPlayer
{

    NormalPlayingStrategy::NormalPlayingStrategy()
    {
    }
    void NormalPlayingStrategy::previous(IPlayerExecutor &mv_executor)
    {
        mv_executor.set_previous_track(); // the strategy in normal mode when previous is called is to play the previous track
    }
    void NormalPlayingStrategy::next(IPlayerExecutor &mv_executor)
    {
        mv_executor.set_next_track(); // the strategy in normal mode when next is called is to play the next track
    }

    RandomPlayingStrategy::RandomPlayingStrategy()
    {
    }
    void RandomPlayingStrategy::next(IPlayerExecutor &mv_executor)
    {
        mv_executor.set_random_track(); // the strategy in normal mode when previous is called is to play the previous track
    }

    RepeatPlayingStrategy::RepeatPlayingStrategy()
    {
    }
    void RepeatPlayingStrategy::next(IPlayerExecutor &mv_executor)
    {
        mv_executor.set_same_track(); // the strategy in normal mode when previous is called is to play the previous track
    }

}
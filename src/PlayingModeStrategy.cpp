
#include "PlayingModeStrategy.hpp"

namespace AudioPlayer
{

    NormalPlayingStrategy::NormalPlayingStrategy(std::shared_ptr<IPlayerExecutor> mv_executor) : m_executor(mv_executor)
    {
    }
    void NormalPlayingStrategy::previous()
    {
        m_executor->set_previous_track(); // the strategy in normal mode when previous is called is to play the previous track
    }
    void NormalPlayingStrategy::next()
    {
        m_executor->set_next_track(); // the strategy in normal mode when next is called is to play the next track
    }

    RandomPlayingStrategy::RandomPlayingStrategy(std::shared_ptr<IPlayerExecutor> mv_executor) : m_executor(mv_executor)
    {
    }
    void RandomPlayingStrategy::random()
    {
        m_executor->set_random_track(); // the strategy in random mode will be to find a random track for the next and the previous calls
    }

    RepeatPlayingStrategy::RepeatPlayingStrategy(std::shared_ptr<IPlayerExecutor> mv_executor) : m_executor(mv_executor)
    {
    }
    void RepeatPlayingStrategy::repeat_current()
    {
        m_executor->set_same_track(); // the strategy in repeat mode will be used to play the same track for the next and the previous calls
    }

}
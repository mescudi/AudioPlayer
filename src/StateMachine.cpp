#include "StateMachine.hpp"
#include "match.hpp"
#include "PlayerExecutor.hpp"
#include <variant>
namespace AudioPlayer
{

    StateMachine::StateMachine(IPlayerExecutor &executor, IPlayerContext &mv_context)
        : m_executor(executor),
          m_context(mv_context),
          m_state(State{Stopped{m_executor}})
    {
        m_playing_mode = std::make_unique<PlayingMode>(std::make_unique<NormalPlayingStrategy>(std::make_shared<PlayerExecutor>(m_executor)));
    }

    void StateMachine::stop()
    {
        std::visit( // when stop is received visits the state, if State is of type Started, the state is now Stopped type
            [&](auto &state)
            {
                using T = std::decay_t<decltype(state)>;
                if constexpr (std::is_same_v<T, Started>)
                {
                    m_state = State{Stopped{m_executor}};
                }
            },
            m_state);
    }

    void StateMachine::start_pause()
    {
        std::visit(
            [&](auto &state)
            {
                using T = std::decay_t<decltype(state)>;
                if constexpr (std::is_same_v<T, Stopped> || std::is_same_v<T, Paused>) // when start_pause is received visits the state, if State is of type Stopped or Pause, the state is now Started type
                {
                    if (m_context.is_there_track_to_play())
                        m_state = State{Started{m_executor}};
                }
                else if constexpr (std::is_same_v<T, Started>) // on the contrary if it was Started it is now of type Paused
                {
                    m_state = State{Paused{m_executor}};
                }
            },
            m_state);
    }

    void StateMachine::set_random()
    {
        decltype(auto) result = std::visit(
            [](auto &mode)
            {
                using T = std::decay_t<decltype(mode)>;
                if constexpr (std::is_same_v<T, NormalPlayingStrategy> || std::is_same_v<T, RepeatPlayingStrategy>)
                {
                    m_playing_mode = RandomPlayingStrategy{std::make_shared<PlayerExecutor>(m_executor)};
                }
            },
            m_playing_mode);
    }

    void StateMachine::set_repeat()
    {
        std::visit(
            [&](auto &mode)
            {
                using T = std::decay_t<decltype(mode)>;
                if constexpr (std::is_same_v<T, RepeatPlayingStrategy>)
                {
                    if (m_context.is_there_track_to_play())
                    {
                        m_playing_mode = NormalPlayingStrategy{std::make_shared<PlayerExecutor>(m_executor)};
                    }
                }
                else if constexpr (std::is_same_v<T, NormalPlayingStrategy> || std::is_same_v<T, RandomPlayingStrategy>)
                {
                    m_playing_mode = RepeatPlayingStrategy{std::make_shared<PlayerExecutor>(m_executor)};
                }
            },
            m_playing_mode);
    }

    void StateMachine::next()
    {
        std::visit([&](auto &strategy)
                   {
        using T = std::decay_t<decltype(strategy)>;
        if constexpr (std::is_same_v<T, NormalPlayingStrategy>)
        {
            strategy.next();
        }
        else if constexpr (std::is_same_v<T, RandomPlayingStrategy>)
        {
            strategy.random();
        }
        else if constexpr (std::is_same_v<T, RepeatPlayingStrategy>)
        {
            strategy.repeat_current();
        } },
                   m_playing_mode);
    }

    void StateMachine::previous()
    {
        std::visit([&](auto &strategy)
                   {
        using T = std::decay_t<decltype(strategy)>;
        if constexpr (std::is_same_v<T, NormalPlayingStrategy>)
        {
            strategy.previous();
        }
        else if constexpr (std::is_same_v<T, RandomPlayingStrategy>)
        {
            strategy.random();
        }
        else if constexpr (std::is_same_v<T, RepeatPlayingStrategy>)
        {
            strategy.repeat_current();
        } },
                   m_playing_mode);
    }
}

#include "StateMachine.hpp"
#include "match.hpp"
#include "PlayerExecutor.hpp"
#include <variant>
namespace AudioPlayer
{

    StateMachine::StateMachine(IPlayerExecutor &executor, IPlayerContext &mv_context)
        : m_executor(executor),
          m_context(mv_context),
          m_state(State{Stopped{}}),
          m_playing_strategy(std::in_place_index<0>, NormalPlayingStrategy{}) // initialize with type 1 which is NormalPlayingStrategy
    {
    }

    void StateMachine::stop()
    {
        std::visit(
            [this](auto &state)
            {
                using T = std::decay_t<decltype(state)>;
                if constexpr (std::is_same_v<T, Started> || std::is_same_v<T, Paused>)
                {
                    m_state = State{Stopped{}};
                    // std::visit([this](auto &new_state)
                    //            { new_state.exec_state(this->m_executor); },
                    //            m_state);
                    auto iv_state = std::get<Stopped>(m_state);
                    iv_state.exec_stop(m_executor);
                }
            },
            m_state);
    }

    void StateMachine::start_pause()
    {
        std::visit(
            [this](auto &state)
            {
                using T = std::decay_t<decltype(state)>;
                if constexpr (std::is_same_v<T, Stopped>)
                {
                    m_state = State{Started{}};
                    auto iv_state = std::get<Started>(m_state);
                    iv_state.exec_start(m_executor); //  transition from stopped to start
                }
                if constexpr (std::is_same_v<T, Paused>)
                {
                    m_state = State{Started{}};
                    auto iv_state = std::get<Started>(m_state);
                    iv_state.exec_resume(m_executor); // transition from paused to started (resume)
                }
                if constexpr (std::is_same_v<T, Started>)
                {
                    m_state = State{Paused{}};
                    auto iv_state = std::get<Paused>(m_state);
                    iv_state.exec_pause(m_executor); // transition from started to pause
                }
            },
            m_state);
    }

    void StateMachine::set_random()
    {
        std::visit(
            [&](auto &mode)
            {
                using T = std::decay_t<decltype(mode)>;
                if constexpr (std::is_same_v<T, RandomPlayingStrategy>) // if strategy was Random -> Normal
                {
                    // return to normal
                    m_playing_strategy = NormalPlayingStrategy{};
                } // if strategy was normal or Repeat -> Random
                else if constexpr (std::is_same_v<T, NormalPlayingStrategy> || std::is_same_v<T, RepeatPlayingStrategy>)
                {
                    m_playing_strategy = RandomPlayingStrategy{};
                }
            },
            m_playing_strategy);
    }

    void StateMachine::set_repeat()
    {
        std::visit(
            [&](auto &mode)
            {
                using T = std::decay_t<decltype(mode)>;
                if constexpr (std::is_same_v<T, RepeatPlayingStrategy>) // if strategy was Repeat -> Normal
                {
                    // return to normal
                    m_playing_strategy = NormalPlayingStrategy{};
                } // if strategy was normal or Random -> Repeat
                else if constexpr (std::is_same_v<T, NormalPlayingStrategy> || std::is_same_v<T, RandomPlayingStrategy>)
                {
                    m_playing_strategy = RepeatPlayingStrategy{};
                }
            },
            m_playing_strategy);
    }

    void StateMachine::next()
    { // if not Stopped -> stop
        std::visit(
            [this](auto &state)
            {
                using T = std::decay_t<decltype(state)>;
                if constexpr (!std::is_same_v<T, Stopped>)

                {
                    m_state = State{Stopped{}};
                    auto iv_state = std::get<Stopped>(m_state);
                    iv_state.exec_stop(m_executor);
                }
            },
            m_state);
        // access call the "next current strategy"  strategy
        std::visit([this](auto &strategy) { // capture 'this' explicitly
            strategy.next(this->m_executor);
        },
                   m_playing_strategy);
        // start again
        start_pause();
    }

    void StateMachine::previous()
    {
        // if not Stopped -> stop
        std::visit(
            [this](auto &state)
            {
                using T = std::decay_t<decltype(state)>;
                if constexpr (!std::is_same_v<T, Stopped>)

                {
                    m_state = State{Stopped{}};
                    auto iv_state = std::get<Stopped>(m_state);
                    iv_state.exec_stop(m_executor);
                }
            },
            m_state);
        // access call the "next current strategy"  strategy
        std::visit([this](auto &strategy) { // capture 'this' explicitly
            strategy.previous(this->m_executor);
        },
                   m_playing_strategy);
        // start again
        start_pause();
    }

}

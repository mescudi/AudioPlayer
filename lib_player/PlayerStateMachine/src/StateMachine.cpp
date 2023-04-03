#include "StateMachine.hpp"
#include "match.hpp"
#include "PlayerExecutor.hpp"
#include <variant>
#include "Logger.hpp"
namespace AudioPlayer
{

    StateMachine::StateMachine(IPlayerExecutor &executor)
        : m_executor(executor),
          m_state(State{Stopped{}}),
          m_playing_strategy(std::in_place_index<0>, NormalPlayingStrategy{}) // initialize with type 1 which is NormalPlayingStrategy
    {
    }

    void StateMachine::stop()
    {
        std::visit(
            [&](auto &state)
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
            [&](auto &state)
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
                    LOG("DEV", "From Random to Normal strategy transition");

                    m_playing_strategy = NormalPlayingStrategy{};
                } // if strategy was normal or Repeat -> Random
                else if constexpr (std::is_same_v<T, NormalPlayingStrategy> || std::is_same_v<T, RepeatPlayingStrategy>)
                {
                    LOG("DEV", "To  Random strategy transition");
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
                    LOG("DEV", "From Repeat to Normal strategy transition");
                    m_playing_strategy = NormalPlayingStrategy{};
                } // if strategy was normal or Random -> Repeat
                else if constexpr (std::is_same_v<T, NormalPlayingStrategy> || std::is_same_v<T, RandomPlayingStrategy>)
                {
                    LOG("DEV", "To  Repeat strategy transition");

                    m_playing_strategy = RepeatPlayingStrategy{};
                }
            },
            m_playing_strategy);
    }

    void StateMachine::next()
    { //[1] if not Stopped -> stop
        LOG("DEV", "");
        bool iv_was_not_stopped = false;
        std::visit(
            [&](auto &state)
            {
                using T = std::decay_t<decltype(state)>;
                if constexpr (!std::is_same_v<T, Stopped>)

                {
                    iv_was_not_stopped = true;
                    LOG("DEV", "State different from stop, transition to stop");
                    m_state = State{Stopped{}};
                    auto iv_state = std::get<Stopped>(m_state);
                    iv_state.exec_stop(m_executor);
                }
            },
            m_state);
        //[2]  access call the "next current strategy"  strategy
        LOG("DEV", "Execute adequate next strategy");
        std::visit([&](auto &strategy)
                   { strategy.next(m_executor); },
                   m_playing_strategy);
        //[3] start again
        if (iv_was_not_stopped)
        {
            LOG("DEV", "Was not stopped start again");
            start_pause();
        }
    }

    void StateMachine::previous()
    {
        bool iv_was_not_stopped = false;
        std::visit(
            [&](auto &state)
            {
                using T = std::decay_t<decltype(state)>;
                if constexpr (!std::is_same_v<T, Stopped>)

                {
                    LOG("DEV", "State different from stop, transition to stop");
                    iv_was_not_stopped = true;
                    m_state = State{Stopped{}};
                    auto iv_state = std::get<Stopped>(m_state);
                    iv_state.exec_stop(m_executor);
                }
            },
            m_state);
        //[2]  access call the "next current strategy"  strategy
        LOG("DEV", "Execute adequate next strategy");
        std::visit([&](auto &strategy)
                   { strategy.previous(m_executor); },
                   m_playing_strategy);
        if (iv_was_not_stopped)
        {
            LOG("DEV", "Was not stopped start again");
            start_pause();
        }
    }

    void StateMachine::remove_track(uint32_t mv_track_number)
    {
        LOG("DEV", "");

        if (m_executor.get_current_track_number().has_value()) // if playlist has tracks
        {
            LOG("DEV", "track number has value");
            uint32_t iv_nb_of_current_track_in_playlist = m_executor.get_current_track_number().value();
            if (mv_track_number == iv_nb_of_current_track_in_playlist)
            { // if the current track is being remove,
                LOG("DEV", "Remove same track number (" + std::to_string(iv_nb_of_current_track_in_playlist) + ") as current track");

                std::visit(
                    [&](auto &state)
                    {
                        using T = std::decay_t<decltype(state)>;

                        if constexpr (std::is_same_v<T, Stopped>)
                        { // if current index is about to get deleted, but it is stopped just do the work
                            LOG("DEV", "State stop, remove track");

                            m_executor.remove_track(mv_track_number);
                        }
                        if constexpr (!std::is_same_v<T, Stopped>)
                        { // if something was playing or stopped, stop before, do the work and then start again
                            LOG("DEV", "State not stop, remove stop, remove track and start");

                            stop();
                            m_executor.remove_track(mv_track_number);
                            start_pause();
                        }
                    },
                    m_state);
            }
            else
            {
                m_executor.remove_track(mv_track_number); // if the current track is not remove just remove the track of index mv_track_number
            }
        }
        else
        {
            LOG("DEV", "Current track number has value");
        }
    }
}

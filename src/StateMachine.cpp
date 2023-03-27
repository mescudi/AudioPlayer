#include "StateMachine.hpp"
#include "match.hpp"

namespace AudioPlayer
{

    StateMachine::StateMachine(IPlayerExecutor &executor, IPlayerContext &mv_context) : m_executor(executor), m_context(mv_context), m_state(Stopped(executor))
    {
    }

    void StateMachine::stop()
    {
        std::visit(
            [&](auto &state)
            {
                using T = std::decay_t<decltype(state)>;
                if constexpr (std::is_same_v<T, Started>)
                {
                    m_state = Stopped{m_executor}; // pas trop sur de celle là
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
                if constexpr (std::is_same_v<T, Stopped> || std::is_same_v<T, Paused>)
                {
                    if (m_context.is_there_track_to_play())
                        m_state = Started{m_executor};
                }
                else if constexpr (std::is_same_v<T, Started>)
                {
                    m_state = Paused{m_executor};
                }
            },
            m_state);
    }

}

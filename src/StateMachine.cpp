#include "StateMachine.hpp"
#include "match.hpp"

namespace AudioPlayer
{

    StateMachine::StateMachine(IPlayerExecutor &executor) : m_executor(executor), m_state(Stopped(executor))
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

    void StateMachine::start()
    {
        std::visit(
            [&](auto &state)
            {
                using T = std::decay_t<decltype(state)>;
                if constexpr (std::is_same_v<T, Stopped> || std::is_same_v<T, Paused>)
                {
                    m_state = Started{m_executor};
                }
            },
            m_state);
    }

    void StateMachine::pause()
    {
        std::visit(
            [&](auto &state)
            {
                using T = std::decay_t<decltype(state)>;
                if constexpr (std::is_same_v<T, Started>)
                {
                    m_state = Paused{m_executor};
                }
            },
            m_state);
    }

}

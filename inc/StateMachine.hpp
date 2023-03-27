#ifndef STATE_MACHINE_HPP // include guard
#define STATE_MACHINE_HPP
#include <variant>
#include "IPlayerExecutor.hpp"
#include "IPlayerContext.hpp"

namespace AudioPlayer
{

    struct Stopped // TODO à sortir
    {
        Stopped(IPlayerExecutor &executor)
        {
            executor.stop();
        }
    };

    struct Started
    {
        Started(IPlayerExecutor &executor)
        {
            executor.start();
        }
    };

    struct Paused
    {
        Paused(IPlayerExecutor &executor)
        {
            executor.pause();
        }
    };

    using State = std::variant<
        Started,
        Stopped,
        Paused>;

    class StateMachine
    {
    public:
        StateMachine(IPlayerExecutor &mv_player_executor, IPlayerContext &mv_context);
        void stop();
        void start_pause();

    private:
        State m_state;
        IPlayerExecutor &m_executor;
        IPlayerContext &m_context;
    };
}
#endif
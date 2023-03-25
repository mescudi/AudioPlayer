#ifndef STATE_MACHINE_HPP // include guard
#define STATE_MACHINE_HPP
#include <variant>
namespace AudioPlayer
{
    struct Stopped
    {
        Stopped(){

        };
    };
    struct Started
    { // TODO imagine some data related to state compteur
    };
    struct Paused
    {
    };

    using State = std::variant<
        Started,
        Stopped,
        Paused>;

    class StateMachine
    {
    public:
        void stop();

    private:
        State m_state;
    };
}
#endif
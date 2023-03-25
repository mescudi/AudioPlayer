#include "StateMachine.hpp"
#include "match.hpp"

namespace AudioPlayer
{
    void StateMachine::stop()
    {
        std::visit(
            [&](const auto &iv_state)
            {
                using T = std::decay_t<decltype(iv_state)>;
                if constexpr (std::is_same_v<T, Started>)
                {
                    //
                    m_state = Stopped{}; // ici on fait le traitement de rentree dans l'etat
                }
            },
            m_state);
    };
}

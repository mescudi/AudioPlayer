#include "Output.hpp"
namespace AudioPlayer
{

    Output::Output(const IPlayerContext &mv_player_context, const IOutputWriter &mv_output_writer)
        : m_player_context(mv_player_context),
          m_output_writer(mv_output_writer)

    {
    }

    void Output::display_message(const std::string &mv_message) const
    {
        m_output_writer.display_message(mv_message);
    }

    void Output::display_started() const
    {
        display_message("Playing " + m_player_context.get_current_track_name());
    }
    void Output::display_stopped() const
    {
        display_message(m_player_context.get_current_track_name() + "Player Stopped ");
    }
    void Output::display_paused() const
    {
        display_message(m_player_context.get_current_track_name() + "Player Paused ");
    }

    void Output::display_resumed() const
    {
        display_message(m_player_context.get_current_track_name() + "Player Resumed ");
    }

    void Output::display_repeat() const
    {
        display_message(" Repeat Mode (Next and Previous tracks are the current one");
    }

    void Output::display_random() const
    {
        display_message(" Random Mode Next and Previous tracks are the random");
    }
}

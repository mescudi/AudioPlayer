#include "Output.hpp"
namespace AudioPlayer
{

    Output::Output(const PlayList &mv_playlist, const IOutputWriter &mv_output_writer)
        : m_playlist(mv_playlist),
          m_output_writer(mv_output_writer)

    {
    }

    void Output::display_message(const std::string &mv_message) const
    {
        m_output_writer.display_message(mv_message);
    }

    void Output::display_started() const
    {
        if (m_playlist.get_current_track_name() == "")
        {
            display_message("No current track to play");
        }
        else
        {
            display_message("Playing " + m_playlist.get_current_track_name());
        }
    }
    void Output::display_stopped() const
    {
        if (m_playlist.get_current_track_name() == "")
        {
            display_message("No current track to stop");
        }
        else
        {
            display_message(m_playlist.get_current_track_name() + " Stopped ");
        }
    }
    void Output::display_paused() const
    {
        if (m_playlist.get_current_track_name() == "")
        {
            display_message("No current track to pause");
        }
        else
        {
            display_message(m_playlist.get_current_track_name() + " Paused ");
        }
    }

    void Output::display_resumed() const
    {
        if (m_playlist.get_current_track_name() == "")
        {
            display_message("No current track to resume");
        }
        else
        {
            display_message(m_playlist.get_current_track_name() + " Resumed ");
        }
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

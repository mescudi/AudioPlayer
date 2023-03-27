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
    // void Output::display_track() const
    // {
    //     // calculer le numéro
    //     // const auto &iv_track_data =
    //     // std::string iv_string =
    //     //     "Track " +
    //     //     "Duration: " +
    //     //     Track 1(2)01_intro.music Duration : 03 : 00 Title : Introduction
    //     //                                                             Codec : MP3

    //     // std::string iv_string = "Track Name : " + m_player_context.get_current_track_name() + "Track Title " +
    //     //                         +"Duration " +
    //     //                         +"Track " + m_player_context.
    // }
    // void Output::display_added_track(const std::string &mv_track) const
    // {
    //     display_message("Added " + mv_track);
    // }
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

    void Output::display_repeat() const
    {
        display_message(" Repeat Mode (at end of track, repeat)");
    }

    void Output::display_random() const
    {
        display_message(" Random Mode (affect next previous commands)");
    }
    // void Output::display_resume() const
    // {
    //     display_message(m_player_context.get_current_track_name() + "Resumed ");
    // }
    // void Output::display_playlist(const std::vector<std::string> &mv_playlist) const
    // {
    // }

}

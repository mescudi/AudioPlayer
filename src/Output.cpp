#include "Output.hpp"
namespace AudioPlayer
{

    Output::Output(const IPlayerContext &mv_player_context) : m_player_context(mv_player_context)

    {
    }

    void Output::display_message(const std::string &mv_message) const
    {
        std::cout << mv_message << std::endl;
    }
    void Output::display_file_data() const
    {
        // calculer le numéro
        // const auto &iv_track_data =
        // std::string iv_string =
        //     "Track " +
        //     "Duration: " +
        //     Track 1(2)01_intro.music Duration : 03 : 00 Title : Introduction
        //                                                             Codec : MP3
    }
    void Output::display_added_track(const std::string &mv_track) const
    {
        display_message("Added " + mv_track);
    }
    void Output::display_started() const
    {
        display_message("Playing " + m_player_context.get_current_track_name());
    }
    void Output::display_stopped() const
    {
        display_message(m_player_context.get_current_track_name() + "Stopped ");
    }

    void Output::display_resume() const
    {
        display_message(m_player_context.get_current_track_name() + "Resumed ");
    }
}

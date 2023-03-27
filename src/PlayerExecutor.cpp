#include "PlayerExecutor.hpp"
#include "Output.hpp"
#include "Time.hpp"
#include "Logger.hpp"

namespace AudioPlayer
{

    PlayerExecutor::PlayerExecutor(IPlayerContext &mv_context, const SystemFiles::IConfigSystemFiles &mv_system_conf, IOutput &mv_output)
        : m_context(mv_context), m_system_conf(mv_system_conf), m_playlist(), m_output(mv_output)
    {
    }

    void PlayerExecutor::start()
    {
        // TODO start thread
        m_output.display_started();
    }
    void PlayerExecutor::stop()
    {
        m_output.display_stopped();
    }
    void PlayerExecutor::pause()
    {
        m_output.display_paused();
    }
    void PlayerExecutor::resume() {}
    void PlayerExecutor::next()
    {
    }
    void PlayerExecutor::previous()
    {
    }

    void PlayerExecutor::add_track_to_playlist(const std::string &mv_string)
    {
        if (mv_string == "")
        {
            m_output.display_message("No track name, try add track \'name\'");
            return;
        }
        const auto iv_map = m_system_conf.getFileSystemMap();
        auto iv_it = iv_map.find(mv_string);
        if (iv_it != iv_map.end())
        {
            auto iv_capture_play_list_was_empty = m_playlist.is_empty();
            m_playlist.add_track(mv_string);

            m_output.display_message("Track " + mv_string + " added to playlist");
            if (iv_capture_play_list_was_empty)
            {
                m_context.set_current_track_name(mv_string); // index is already 0
                m_output.display_message("Current track of playlist is now " + mv_string);
            }
        }
        else
        {
            m_output.display_message("Track name " + mv_string + " does not correspond to any file system track");
        }
    }

    void PlayerExecutor::remove_track(uint32_t mv_index)
    {
        m_playlist.remove_track(mv_index);
    }
    void PlayerExecutor::remove_duplicates()
    {

        m_playlist.remove_duplicates();
    }
    void PlayerExecutor::random()
    {
        m_context.set_playing_mode(PlayingMode::Random);
        m_output.display_random();
    }
    void PlayerExecutor::repeat()
    {
        m_context.set_playing_mode(PlayingMode::Repeat);
        m_output.display_repeat();
    }
    void PlayerExecutor::show_track()
    {
        if (m_playlist.is_empty())
        {
            m_output.display_message("No track in playlist");
        }
        else
        {
            auto iv_track_name = m_context.get_current_track_name();
            auto iv_track_number = m_context.get_current_track_index() + 1;

            uint32_t iv_size_playlist = m_playlist.get_number_of_elements();
            // LOG("DEV", std::to_string(iv_size_playlist));

            auto iv_conf_map = m_system_conf.getFileSystemMap(); // stocker la copie temporaire dans une variable locale
            auto iv_track_info = iv_conf_map[iv_track_name];
            std::string iv_track_info_string = "Info on " + iv_track_name + " " + std::to_string(iv_track_number) + "(" + std::to_string(iv_size_playlist) + ")" + "\n - Codec : " + iv_track_info.m_codec + "\n - Title : " + iv_track_info.m_title + "\n - Duration : " + iv_track_info.m_duration;
            m_output.display_message(iv_track_info_string);
        }
    }
    void PlayerExecutor::show_playlist()
    { // TODO : display listening mode

        if (m_playlist.is_empty())
        {
            m_output.display_message("No track in playlist");
        }
        else
        { // Display Mode display time
            std::string iv_track_info_string = "Info on playlist : \n - Names : ";
            std::vector<std::string> iv_durations;
            for (const auto &track_name : m_playlist.get_playlist())
            {
                iv_track_info_string += "\n   - " + track_name;
                iv_durations.push_back(m_system_conf.getFileSystemMap()[track_name].m_duration); // for all tracks in playlist search for their durations
            }
            std::string iv_total_duration = "\n - Total Duration ";
            try
            {
                // TODO optimize parse 2 times
                std::string iv_duration_totale = Time::total_duration_string(iv_durations);
                /**
                 * count() returns a type _Rep that can be different from
                 *  the integer type you are using. Indeed, _Rep is an alias
                 *  for the underlying data type of the duration, which can
                 *  vary depending on the precision of the duration (for example,
                 *  for std::chrono::seconds, _Rep is an alias for long long
                 */
                iv_total_duration += iv_duration_totale;
            }
            catch (const std::exception &e)
            {
                m_output.display_message(e.what());
                iv_total_duration += "error";
            }
            iv_track_info_string += iv_total_duration;
            m_output.display_message(iv_track_info_string);
        }
    }
}

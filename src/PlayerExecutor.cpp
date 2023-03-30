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
    void PlayerExecutor::resume()
    {
        // m_output.display_resumed();
    }

    // Add track to playlist method
    void PlayerExecutor::add_track_to_playlist(const std::string &mv_string)
    {
        // If no track name is provided, display message and return
        if (mv_string == "")
        {
            m_output.display_message("No track name, try add track \'name\'");
            return;
        }

        // Get file system map from system configuration
        const auto iv_map = m_system_conf.getFileSystemMap();

        // Find track with given name in file system map
        auto iv_it = iv_map.find(mv_string);
        if (iv_it != iv_map.end())
        {
            // If track is found, add it to playlist
            auto iv_capture_play_list_was_empty = m_playlist.is_empty();
            m_playlist.add_track(mv_string);

            // Display message indicating track was added to playlist
            m_output.display_message("Track " + mv_string + " added to playlist");

            // If the playlist was empty before the track was added, set current track name to the added track
            if (iv_capture_play_list_was_empty)
            {
                m_context.set_current_track_name(mv_string); // index is already 0
                m_output.display_message("Current track of playlist is now " + mv_string);
            }
        }
        else
        {
            // If track is not found in file system map, display message
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

    void PlayerExecutor::show_track()
    {
        if (m_playlist.is_empty())
        {
            m_output.display_message("No track in playlist");
        }
        else
        {
            auto iv_track_name = m_context.get_current_track_name();
            auto iv_track_number = m_context.get_current_track_index() + 1; // first index is 1 for a end user

            uint32_t iv_size_playlist = m_playlist.get_number_of_elements();
            // LOG("DEV", std::to_string(iv_size_playlist));

            auto iv_conf_map = m_system_conf.getFileSystemMap();
            auto iv_track_info = iv_conf_map[iv_track_name]; // get the info in the conf of the current track
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
                // use time methode to get all the durations summed, can throw if not in format of the filesystem metadata
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
                m_output.display_message(e.what()); // duration will be display in error if throwed
                iv_total_duration += "error";
            }
            iv_track_info_string += iv_total_duration; // add the total duration string to the string total string that will be displayed
            m_output.display_message(iv_track_info_string);
        }
    }

    void PlayerExecutor::set_previous_track()
    {
    }
    void PlayerExecutor::set_next_track()
    {
    }
    void PlayerExecutor::set_random_track()
    {
        m_output.display_random();
    }
    void PlayerExecutor::set_same_track()
    {
        m_output.display_repeat();
    }

}

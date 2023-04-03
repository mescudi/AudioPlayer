#include "PlayerExecutor.hpp"
#include "Output.hpp"
#include "Time.hpp"
#include "Logger.hpp"

namespace AudioPlayer
{

    PlayerExecutor::PlayerExecutor(PlayList &mv_playlist, const SystemFiles::IConfigSystemFiles &mv_system_conf, IOutput &mv_output)
        : m_system_conf(mv_system_conf), m_output(mv_output), m_playlist(mv_playlist)
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
        m_output.display_resumed();
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
            m_playlist.add_track(mv_string);

            // Display message indicating track was added to playlist
            m_output.display_message("Track " + mv_string + " added to playlist");
        }
        else
        {
            // If track is not found in file system map, display message
            m_output.display_message("Track name " + mv_string + " does not correspond to any file system track");
        }
    }
    void PlayerExecutor::remove_track(uint32_t mv_number)
    {
        try
        {
            std::string iv_track_name_to_remove = "";
            m_playlist.remove_track(mv_number - 1, iv_track_name_to_remove);
            std::string iv_ouput_str = "Track  " + std::to_string(mv_number) + " : " + iv_track_name_to_remove + " removed";
            if (m_playlist.is_empty())
            {
                iv_ouput_str += ", no current track";
            }
            else
            {
                iv_ouput_str += ", current track is now " + m_playlist.get_current_track_name();
            }
            m_output.display_message(iv_ouput_str);
        }
        catch (const std::out_of_range iv_e)
        {
            m_output.display_message("No track numbered " + std::to_string(mv_number));
        }
    }
    void PlayerExecutor::remove_duplicates()
    {
        try
        {
            m_playlist.remove_duplicates();
            m_output.display_message("duplicates Removed");
            show_playlist();
        }

        catch (const std::out_of_range iv_e)
        {
            m_output.display_message("No track to remove ");
        }
    }
    void PlayerExecutor::show_track()
    {
        if (m_playlist.is_empty())
        {
            m_output.display_message("No track in playlist");
        }
        else
        {
            auto iv_track_name = m_playlist.get_current_track_name();
            auto iv_track_number = m_playlist.get_current_track_number().value(); // first index is 1 for a end user

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
            for (const auto &track : m_playlist.get_playlist())
            {
                iv_track_info_string += "\n   - " + track.m_track_name;
                iv_durations.push_back(m_system_conf.getFileSystemMap()[track.m_track_name].m_duration); // for all tracks in playlist search for their durations
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
        LOG("DEV", "");
        try
        {
            std::string iv_string = "";
            m_playlist.set_previous_and_return(iv_string);
            m_output.display_message("Previous track is :" + iv_string);
        }
        catch (const std::exception &iv_e)
        {
            std::string iv_string = std::string("Error : ") + iv_e.what() + std::string(",no new track played : ");
            m_output.display_message(iv_string);
        }
    }
    void PlayerExecutor::set_next_track()
    {
        LOG("DEV", "");
        try
        {
            std::string iv_string = "";
            m_playlist.set_next_and_return(iv_string);
            m_output.display_message("Next track is :" + iv_string);
        }
        catch (const std::exception &iv_e)
        {
            std::string iv_string = std::string("Error : ") + iv_e.what() + std::string(",no new track played : ");
            m_output.display_message(iv_string);
        }
    }
    void PlayerExecutor::set_random_track()
    {
        LOG("DEV", "");
        try
        {
            m_output.display_random();

            std::string iv_string = "";
            m_playlist.set_and_return_random_track(iv_string);
            m_output.display_message("Next track is :" + iv_string);
        }
        catch (const std::exception &iv_e)
        {
            std::string iv_string = std::string("Error : ") + iv_e.what() + std::string(",no new track played : ");
            m_output.display_message(iv_string);
        }
    }
    void PlayerExecutor::set_same_track()
    {
        LOG("DEV", "");
        m_output.display_repeat();
    }
    std::optional<uint32_t> PlayerExecutor::get_current_track_number() const
    {
        return m_playlist.get_current_track_number();
    }
    void PlayerExecutor::add_all_system_tracks_to_playlist()
    {
        std::string iv_display = "\nTracks added :\n";
        for (const auto iv_it : m_system_conf.getFileSystemMap())
        {
            m_playlist.add_track(iv_it.first);
            iv_display += "\n [" + iv_it.first + "]";
        }

        m_output.display_message(iv_display);
    }
}

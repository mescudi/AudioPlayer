#include "PlayerExecutor.hpp"
#include "Output.hpp"

namespace AudioPlayer
{

    PlayerExecutor::PlayerExecutor(IPlayerContext &mv_context, const SystemFiles::IConfigSystemFiles &mv_system_conf)
        : m_context(mv_context), m_system_conf(m_system_conf), m_playlist()
    {
        m_output = std::make_shared<Output>(mv_context);
    }

    void PlayerExecutor::start()
    {
        // TODO start thread
        m_output->display_started();
    }
    void PlayerExecutor::stop()
    {
        m_output->display_stopped();
    }
    void PlayerExecutor::pause()
    {
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
        const auto &iv_map = m_system_conf.getFileSystemMap();
        auto iv_it = iv_map.find(mv_string);
        if (iv_it != iv_map.end())
        {
            m_playlist.add_track(mv_string);
            // m_context.set_current_track_index(std::distance(iv_map.begin(), iv_it));
            m_output->display_started();
        }
        else
        {
            // error
            // m_context.set_current_track_index(-1);
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
        m_output->display_random();
    }
    void PlayerExecutor::repeat()
    {
        m_context.set_playing_mode(PlayingMode::Repeat);
        m_output->display_repeat();
    }
    void PlayerExecutor::show_track() {}
    void PlayerExecutor::show_playlist()
    { // TODO : display listening mode
      // duration
      // for (auto iv_elem : m_playlist.get_playlist())
      // {

        //      })
    }
}
#include "PlayerExecutor.hpp"
#include "Output.hpp"

namespace AudioPlayer
{

    PlayerExecutor::PlayerExecutor(IPlayerContext &mv_context, const SystemFiles::IConfigSystemFiles &mv_system_conf, PlayList &mv_playlist)
        : m_context(mv_context), m_system_conf(m_system_conf), m_playlist(mv_playlist)
    {
        m_output = std::make_unique<Output>(mv_context);
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
        auto iv_it = m_system_conf.getFileSystemMap().find(mv_string);
        if (iv_it != m_system_conf.getFileSystemMap().end())
        {
            // exists in conf
            m_playlist.add_track(mv_string);
            m_output->display_started();
        }
        else
        {
            // error
        }
    }
    void PlayerExecutor::remove_track(uint32_t) {}
    void PlayerExecutor::remove_duplicates() {}
    void PlayerExecutor::random() {}
    void PlayerExecutor::repeat() {}
    void PlayerExecutor::show_track() {}
    void PlayerExecutor::show_playlist() {}

}
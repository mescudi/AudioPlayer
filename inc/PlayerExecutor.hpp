#ifndef PLAYER_EXECUTOR_HPP // include guard
#define PLAYER_EXECUTOR_HPP
#include "IPlayerExecutor.hpp"
#include "IPlayerContext.hpp"
#include "IPlayerManager.hpp"

#include "PlayList.hpp"
#include "StateMachine.hpp"
#include "IOutput.hpp"

#include "ConfigSystemFiles.hpp"
namespace AudioPlayer
{
    class PlayerExecutor : public IPlayerExecutor
    {
    public:
        PlayerExecutor(IPlayerContext &, const SystemFiles::IConfigSystemFiles &, IOutput &);
        void add_track_to_playlist(const std::string &mv_string) override;
        void remove_track(uint32_t) override;
        void remove_duplicates() override;

        void start() override;
        void stop() override;
        void pause() override;
        void resume() override;
        void next() override;
        void previous() override;

        void random() override;
        void repeat() override;
        void show_track() override;
        void show_playlist() override;

    private:
        IPlayerContext &m_context;
        const SystemFiles::IConfigSystemFiles &m_system_conf;
        IOutput &m_output;
        PlayList m_playlist;
    };
}
#endif
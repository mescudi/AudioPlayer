#ifndef OUTPUT_HPP // include guard
#define OUTPUT_HPP
#include "IOutput.hpp"
#include "IPlayerContext.hpp"
#include "IOutputWriter.hpp"

#include <vector>

namespace AudioPlayer
{
    class Output : public IOutput
    {

    public:
        Output(const IPlayerContext &, const IOutputWriter &);

        void display_message(const std::string &mv_message) const override;
        // void display_track() const override;
        // void display_added_track(const std::string &mv_track) const override;
        void display_started() const override;
        void display_paused() const override;
        void display_stopped() const override;

        // void display_resume() const override;
        // void display_playlist(const std::vector<std::string> &) const override;
        void display_repeat() const override;
        void display_random() const override;

    private:
        const IPlayerContext &m_player_context;
        const IOutputWriter &m_output_writer;
    };
}

#endif
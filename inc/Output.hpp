#ifndef OUTPUT_HPP // include guard
#define OUTPUT_HPP
#include "IOutput.hpp"
#include "IPlayerContext.hpp"

namespace AudioPlayer
{
    class Output : public IOutput
    {

    public:
        Output(const IPlayerContext &);
        ~Output();

        void display_message(const std::string &mv_message) const override;
        void display_file_data() const override;
        void display_added_track(const std::string &mv_track) const override;
        void display_started() const override;
        void display_stopped() const override;
        void display_resume() const override;

    private:
        const IPlayerContext &m_player_context;
    };
}

#endif
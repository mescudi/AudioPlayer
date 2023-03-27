#include "PlayList.hpp"
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <unordered_set>

namespace AudioPlayer
{

    PlayList::PlayList()
    {
    }
    void PlayList::add_track(const std::string &mv_string)
    {
        m_tracks.push_back(mv_string);
    }

    bool PlayList::is_empty() const
    {
        return m_tracks.empty();
    }
    uint32_t PlayList::get_number_of_elements() const
    {
        return m_tracks.size();
    }

    void PlayList::remove_track(uint32_t mv_index)
    {

        if (mv_index < 0 || mv_index >= m_tracks.size())
        {
            // Invalid Index
            return;
        }
        m_tracks.erase(m_tracks.begin() + mv_index);
    }

    void PlayList::remove_duplicates()
    {
        std::unordered_set<std::string> iv_seen; // to stock unique elements
        std::vector<std::string> iv_result;      // to stock unique elements in original order

        for (const auto &iv_element : m_tracks)
        {
            // add element if it hasn't been seen before
            if (iv_seen.insert(iv_element).second)
            {
                iv_result.push_back(iv_element);
            }
        }
        m_tracks = std::move(iv_result); // Rempl
    }
    void PlayList::pick_random_track(std::string &mv_track_name) const
    {
        std::vector<std::string> out;
        std::sample(
            m_tracks.begin(),
            m_tracks.end(),
            std::back_inserter(out),
            1, // 1 element
            std::mt19937{std::random_device{}()});
        mv_track_name = out.front();
    }

    void PlayList::get_index_of_track(const std::string &mv_track_name, uint32_t &index) const
    {
        // auto iv_it = m_tracks.find(mv_track_name);
    }
    const std::vector<std::string> &PlayList::get_playlist() const
    {
        return m_tracks;
    }

}
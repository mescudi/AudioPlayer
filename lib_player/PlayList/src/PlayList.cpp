#include "PlayList.hpp"
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <unordered_set>
#include "Logger.hpp"
#include <string>

namespace AudioPlayer
{

    PlayList::PlayList() : m_current_track_index(std::nullopt)
    {
    }
    void PlayList::add_track(const std::string &mv_string)
    {
        m_tracks.push_back(Track{mv_string});
        if (!m_current_track_index.has_value())
        {
            m_current_track_index = 0;
        }
    }

    bool PlayList::is_empty() const
    {
        return m_tracks.empty();
    }
    uint32_t PlayList::get_number_of_elements() const
    {
        return m_tracks.size();
    }

    void PlayList::set_next_and_return(std::string &mv_string)
    {
        if (m_tracks.empty())
        {
            throw std::out_of_range("Empty vector.");
        }
        if (m_current_track_index == m_tracks.size() - 1) // if current is last go to begin of vector
        {
            m_current_track_index = 0;
            mv_string = m_tracks.front().m_track_name; // return first element
        }
        else
        {
            uint32_t iv_index = m_current_track_index.value() + 1;
            m_current_track_index = iv_index;
            mv_string = m_tracks[m_current_track_index.value()].m_track_name; // else return next element
        }
    }
    void PlayList::set_previous_and_return(std::string &mv_string)
    {
        if (m_tracks.empty())
        {
            throw std::out_of_range("Empty vector.");
        }
        if (m_current_track_index == 0) // if current is first go to last
        {
            m_current_track_index = m_tracks.size() - 1;
            mv_string = m_tracks.back().m_track_name; // return first element
        }
        else
        {
            uint32_t iv_index = m_current_track_index.value() - 1;
            m_current_track_index = iv_index;
            mv_string = m_tracks[m_current_track_index.value()].m_track_name; // else return next element
        }
    }

    void PlayList::remove_track(uint32_t mv_index, std::string &mv_track_name)
    {
        LOG("DEV", "Track of Index : " + std::to_string(mv_index) + " asked to be removed");

        if (mv_index >= m_tracks.size()) // check if index is invalid
        {
            // Invalid Index
            LOG("DEV", "Invalid Index");

            throw std::out_of_range("Invalid index.");
        }

        mv_track_name = m_tracks.at(mv_index).m_track_name; // get the name of the track at the given index
        m_tracks.erase(m_tracks.begin() + mv_index);        // remove the track from the vector and get the updated iterator

        if (m_tracks.empty()) // If there are no tracks left in the playlist
        {
            LOG("DEV", "Tracks vector now empty");

            m_current_track_index = std::nullopt; // Set current track index to nullopt
        }
        else if (mv_index < m_current_track_index.value()) // The removed track was before the current track
        {
            LOG("DEV", "index inferior to current index");

            uint32_t iv_int = m_current_track_index.value() - 1; // index is the previous one
            m_current_track_index = iv_int;
        }
        else if (mv_index == m_current_track_index.value()) // The removed track is the current track
        {
            LOG("DEV", "Remove same track number (" + std::to_string(mv_index) + ") as current track");

            if (m_current_track_index.value() == m_tracks.size()) // The removed track is the last track
            {
                LOG("DEV", " Track to delete is same  current Track which is last element");
                m_current_track_index = m_tracks.size() - 1; // index is the new last one
            }
        }

        if (m_current_track_index.has_value())
        {
            std::string iv_string = " Index is now " + std::to_string(m_current_track_index.value());
            LOG("DEV", iv_string);
        }
    }

    void PlayList::remove_duplicates()
    {

        if (m_tracks.empty())
        {
            throw std::out_of_range("Le vecteur est vide.");
        }
        // unordered set to store unique tracks
        std::unordered_set<Track, TrackHash> track_set;

        // get the index of the current track, it it exist
        auto current_track = m_current_track_index.value_or(-1);
        // Initialize an iterator to the beginning of the track vector
        auto it = m_tracks.begin();
        while (it != m_tracks.end())
        {
            // Check if the current track is not the current index
            if (it - m_tracks.begin() != current_track)
            {
                // Check if the current track can be inserted into the track set
                if (track_set.insert(*it).second)
                {
                    // If it can, increment the iterator
                    ++it;
                }
                else
                {
                    it = m_tracks.erase(it);
                }
            }
            else
            {
                // If it is the current index, just increment the iterator
                ++it;
            }
        }

        // Check if the current track needs to be updated
        if (current_track >= 0 && current_track <= m_tracks.size() - 1)
        {
            // Find the new current track based on its name
            auto current_track_name = m_tracks[current_track].m_track_name;
            // Find the range of duplicates for the current track

            auto duplicates_begin = std::find_if(m_tracks.begin(), m_tracks.end(), [&](const Track &track)
                                                 { return track.m_track_name == current_track_name && &track != &m_tracks[current_track]; });
            auto duplicates_end = std::find_if_not(duplicates_begin, m_tracks.end(), [&](const Track &track)
                                                   { return track.m_track_name == current_track_name && &track != &m_tracks[current_track]; });
            // Erase the duplicates from the track vector

            m_tracks.erase(duplicates_begin, duplicates_end);
        }

        // Update the current track index if necessary
        if (current_track >= 0 && current_track <= m_tracks.size() - 1 && m_tracks[current_track].m_track_name != track_set.begin()->m_track_name)
        {
            // Find the new current track based on its name
            auto new_current_track = std::find_if(m_tracks.begin(), m_tracks.end(), [&](const Track &track)
                                                  { return track.m_track_name == m_tracks[current_track].m_track_name; });
            if (new_current_track != m_tracks.end())
            {
                // Set the new current track index to the position of the found track in the vector
                m_current_track_index = std::distance(m_tracks.begin(), new_current_track);
            }
            else
            { // Set the current track index to null
                m_current_track_index = std::nullopt;
            }
        }
    }

    void PlayList::set_and_return_random_track(std::string &mv_track_name)
    {
        // Vérifie que le vecteur n'est pas vide
        if (m_tracks.empty())
        {
            throw std::out_of_range("Le vecteur est vide.");
        }

        // Initialise le générateur de nombres aléatoires
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, m_tracks.size() - 1);

        // Génère un index aléatoire dans la plage des indices valides du vecteur
        m_current_track_index = dis(gen);

        // Retourne la valeur correspondante à l'index aléatoire
        mv_track_name = m_tracks[m_current_track_index.value()].m_track_name;
    }

    const std::vector<Track> &PlayList::get_playlist() const
    {
        return m_tracks;
    }

    std::optional<uint32_t> PlayList::get_current_track_number() const
    {
        if (m_current_track_index.has_value())
        {
            auto iv_int = m_current_track_index.value() + 1;
            std::optional<uint32_t> iv_int1 = iv_int;
            return iv_int1;
        }
        else
        {
            return m_current_track_index; // nullopt
        }
    }

    std::string PlayList::get_current_track_name() const
    {
        if (m_current_track_index.has_value())
        {
            auto iv_int = m_current_track_index.value();

            return m_tracks[iv_int].m_track_name;
        }
        else
        {
            return "";
        }
    }

    bool PlayList::is_there_track_to_play() const
    {
        return !m_tracks.empty();
    }
}
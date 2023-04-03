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
        /* This method uses the std::unique function from the C++ standard library,
         * which returns an iterator pointing to the first element of a sequence without duplicates.
         * Then, the elements between this iterator and the end of the vector are removed using the erase method.
         * The operator== function is also defined to compare two objects of type Track based on
         * their track name m_track_name. This function is used by the std::unique function to compare the elements of the vector. */
        std::vector<Track>::iterator new_end = std::unique(m_tracks.begin(), m_tracks.end());
        m_tracks.erase(new_end, m_tracks.end());
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

    bool operator==(const Track &lhs, const Track &rhs)
    {
        return lhs.m_track_name == rhs.m_track_name;
    }
}
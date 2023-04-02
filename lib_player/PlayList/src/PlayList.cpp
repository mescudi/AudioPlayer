#include "PlayList.hpp"
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <unordered_set>

namespace AudioPlayer
{

    PlayList::PlayList() : m_current_track_index(0)
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

    void PlayList::set_next_and_return(std::string &mv_string)
    {
        if (m_tracks.empty())
        {
            throw std::out_of_range("Empty vector.");
        }
        if (m_current_track_index == m_tracks.size() - 1) // if current is last go to begin of vector
        {
            m_current_track_index = 0;
            mv_string = m_tracks.front(); // return first element
        }
        else
        {
            m_current_track_index++;
            mv_string = m_tracks[m_current_track_index]; // else return next element
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
            mv_string = m_tracks.back(); // return first element
        }
        else
        {
            m_current_track_index--;
            mv_string = m_tracks[m_current_track_index]; // else return decrement
        }
    }

    void PlayList::remove_track(uint32_t mv_index, std ::string &mv_track_name)
    {

        if (mv_index < 0 || mv_index >= m_tracks.size()) // check if index is invalid
        {
            // Invalid Index
            throw std::out_of_range("Invalid index.");
        }

        mv_track_name = m_tracks.at(mv_index);                   // get the name of the track at the given index
        auto iter = m_tracks.erase(m_tracks.begin() + mv_index); // remove the track from the vector and get the updated iterator
        // If the removed track is before the current track, decrement the current index
        if (mv_index < m_current_track_index)
        {
            m_current_track_index--;
        }
        // If the current track was removed, update the current index to the next track if possible
        else if (mv_index == m_current_track_index)
        {
            if (iter != m_tracks.end()) // check if there is a next track
            {
                m_current_track_index = std::distance(m_tracks.begin(), iter);
            }
            else // otherwise, set the current index to the previous track
            {
                m_current_track_index--;
            }
        }
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
        mv_track_name = m_tracks[m_current_track_index];
    }

    void PlayList::get_index_of_track(const std::string &mv_track_name, uint32_t &index) const
    {
        // auto iv_it = m_tracks.find(mv_track_name);
    }
    const std::vector<std::string> &PlayList::get_playlist() const
    {
        return m_tracks;
    }

    uint32_t PlayList::get_current_track_index() const
    {
        return m_current_track_index;
    }
}
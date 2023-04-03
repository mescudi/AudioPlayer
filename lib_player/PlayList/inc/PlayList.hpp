#ifndef PLAYLIST_HPP // include guard
#define PLAYLIST_HPP

#include <vector>
#include <iostream>
#include <optional>
#include "Track.hpp"

namespace AudioPlayer
{
    class PlayList
    {
    public:
        PlayList();
        /**
         * @brief Adds a new track to the playlist.
         * @param mv_string The name of the track to add.
         */
        void add_track(const std::string &mv_string);

        /**
         * @brief Removes a track from the playlist.
         * @param mv_index The index of the track to remove.
         * @param mv_track_name name of the track removed.
         */
        void remove_track(uint32_t mv_index, std::string &mv_track_name);

        /**
         * @brief Removes duplicate tracks from the playlist.
         *
         * The function iterates through the original vector and adds each element to the set
         * if it hasn't already been seen. The insert method of the set returns a pair containing
         * an iterator to the inserted element and a boolean indicating whether the insertion took
         * place (i.e., whether the element was not already present). If the element was inserted
         * into the set, the function also adds it to the result vector.
         *
         * Finally, the function replaces the original vector with the result vector,
         * which contains only the unique elements in the original order.
         *
         * Note that this method uses a set to store the unique elements, which ensures that each
         * element will be present only once. However, the set does not preserve the original order
         * of the elements, which is why we also use a vector to store the elements in the original order.
         */
        void remove_duplicates();

        /**
         * @brief Picks a random track from the playlist.
         * @param mv_track_name A reference to a string that will contain the name of the picked track.
         */
        void pick_random_track(std::string &mv_track_name) const;

        /**
         * @brief Gets a const reference to the vector of tracks in the playlist.
         * @return A const reference to the vector of tracks in the playlist.
         */
        const std::vector<Track> &get_playlist() const;

        /**
         * @brief Checks whether the playlist is empty.
         * @return True if the playlist is empty, false otherwise.
         */
        bool is_empty() const;

        /**
         * @brief Gets the number of elements in the playlist.
         * @return The number of elements in the playlist.
         */
        uint32_t get_number_of_elements() const;

        /**
         * @brief change the current track to the next in the
         *  playlist and return the string in reference of the function parameter of the new track
         */
        void set_next_and_return(std::string &);

        /**
         * @brief change the current track to the previous in the
         *  playlist and return the string in reference of the function parameter of the new track
         */
        void set_previous_and_return(std::string &);

        /**
         * @brief change the current track to a random one in the
         *  playlist and return the string in reference of the function parameter of the new track
         */
        void set_and_return_random_track(std::string &);

        /**
         * @brief Returns the index of the current audio track.
         * @return The index of the current audio track.
         */
        std::optional<uint32_t> get_current_track_number() const;

        /**
         * @brief Returns the name of the current track
         * @return The name of the track
         */
        std::string get_current_track_name() const;

        /**
         * @brief Return true if the playlist is not empty else false
         * @return the assertion whether there is a track or not
         */
        bool is_there_track_to_play() const;

    private:
        std::vector<Track> m_tracks;                   ///< The vector of tracks in the playlist.
        std::optional<uint32_t> m_current_track_index; ///< The index of the current audio trackhas no value when m_tracks is empty
    };

}

#endif
#ifndef PLAYLIST_HPP // include guard
#define PLAYLIST_HPP

#include <vector>
#include <iostream>

namespace AudioPlayer
{
    class PlayList
    {
    public:
        PlayList();
        void add_track(const std::string &mv_string);
        void remove_track(uint32_t mv_index);

        /**
         * the function iterates through the original vector and adds each element
         *  to the set if it hasn't already been seen. The insert method of the set
         *  returns a pair containing an iterator to the inserted element and a boolean
         * indicating whether the insertion took place (i.e., whether the element was not already present).
         * If the element was inserted into the set, the function also adds it to the result vector.

        Finally, the function replaces the original vector with the result vector,
         which contains only the unique elements in the original order.

        Note that this method uses a set to store the unique elements,
         which ensures that each element will be present only once.
         However, the set does not preserve the original order of the elements,
         which is why we also use a vector to store the elements in the original order.
        */
        void remove_duplicates();
        void pick_random_track(std::string &mv_track_name) const;
        void get_index_of_track(const std::string &mv_track_name, uint32_t &index) const;
        const std::vector<std::string> &get_playlist() const;
        bool is_empty() const;
        uint32_t get_number_of_elements() const;

    private:
        std::vector<std::string> m_tracks;
    };
}

#endif
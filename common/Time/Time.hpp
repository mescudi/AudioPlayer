#ifndef TIME_HPP // include guard
#define TIME_HPP

#include <chrono>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
namespace Time
{
    /**

    @brief Parses a string representing a duration (hh:mm:ss) and returns the duration in seconds.
    @param duration_str The string representing the duration in format hh:mm:ss.
    @return std::chrono::seconds The duration in seconds.
    @throw std::invalid_argument If the string is not in the expected format (hh:mm:ss).
    */
    static std::chrono::seconds duration_from_string(const std::string &duration_str)
    {
        std::istringstream iss(duration_str);

        int hours = 0, minutes = 0, seconds = 0;
        char c;

        // Verifies that the string contains exactly two delimiters ":" and that each part is a valid integer number
        if (std::count(duration_str.begin(), duration_str.end(), ':') != 2 ||
            !(iss >> hours >> c >> minutes >> c >> seconds) ||
            iss.get() != EOF)
        {
            throw std::invalid_argument("Chain not in format XX:XX:XX");
        }

        // Converts the duration into seconds
        return std::chrono::hours(hours) + std::chrono::minutes(minutes) + std::chrono::seconds(seconds);
    }

    /**

    @brief Computes the total duration from a vector of strings representing durations (hh:mm:ss).
    @param durations A vector of strings representing the durations in format hh:mm:ss.
    @return std::string The total duration in format hh:mm:ss.
    @throw std::invalid_argument If any of the strings is not in the expected format (hh:mm:ss).
    */
    static std::string total_duration_string(const std::vector<std::string> &durations)
    {
        std::chrono::seconds total_seconds = std::chrono::seconds(0);

        // Iterates through all the strings and adds their respective durations
        for (const auto &duration_str : durations)
        {
            try
            {
                std::chrono::seconds duration = duration_from_string(duration_str);
                total_seconds += duration;
            }
            catch (const std::exception &e)
            {
                // Raises the exception to be caught by the caller
                throw e;
            }
        }

        // Formats the duration to a string in the format hh:mm:ss
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(2) << std::chrono::duration_cast<std::chrono::hours>(total_seconds).count() << ":";
        ss << std::setfill('0') << std::setw(2) << std::chrono::duration_cast<std::chrono::minutes>(total_seconds % std::chrono::hours(1)).count() << ":";
        ss << std::setfill('0') << std::setw(2) << std::chrono::duration_cast<std::chrono::seconds>(total_seconds % std::chrono::minutes(1)).count();

        return ss.str();
    }
}
#endif
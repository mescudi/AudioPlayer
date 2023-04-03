#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <variant>
#include <memory>
#include <vector>

namespace AudioPlayer
{
    /**
     * @brief template class which will provide the access to the string name
     */
    template <typename T>
    class Command
    {
    public:
        static std::string name()
        {
            /*
             This implementation uses a lambda function with a capture-less closure to compute
             the name of the type only once and it doesn't need to capture any external variables,
             therefore it can be converted to a function pointer,
              which can be stored in a static const member variable.
              The std::string type is used to store the name, and the find_last_of function
               is used to extract only the name of the class without any namespace qualifiers.
                This implementation work with C++17.
             */
            static const std::string name = []
            {
                const char *raw_name = typeid(T).name();
                std::string name = raw_name;
                size_t pos = name.find_last_of("::");
                if (pos != std::string::npos)
                {
                    name.erase(0, pos + 1);
                }
                return name;
            }();
            return name;
        }
    };

/**
 * @brief macro coupled with the template class to set the name string trait to commands
 */
#define DEFINE_COMMAND(commandName)                 \
    class commandName : public Command<commandName> \
    {                                               \
    public:                                         \
        using Command<commandName>::Command;        \
    };

    /* definition of all command class,
        it will be used as the string to be interpreted by the Command processor */
    DEFINE_COMMAND(end);
    DEFINE_COMMAND(add_all_tracks);
    DEFINE_COMMAND(remove_duplicates);
    DEFINE_COMMAND(play_pause);
    DEFINE_COMMAND(stop);
    DEFINE_COMMAND(next);
    DEFINE_COMMAND(previous);
    DEFINE_COMMAND(random);
    DEFINE_COMMAND(repeat);
    DEFINE_COMMAND(show_track);
    DEFINE_COMMAND(show_playlist);

    class add_track : public Command<add_track>
    {
    public:
        add_track(const std::string &mv_track_name) : Command<add_track>(), m_track_name(mv_track_name) {}
        std::string m_track_name;
    };

    class remove_track : public Command<remove_track>
    {
    public:
        remove_track(uint32_t mv_track_number) : Command<remove_track>(), m_track_number(mv_track_number) {}
        uint32_t m_track_number;
    };

    /**
     * Variant type which will be used to interpret Commands
     */
    using CommandVariant = std::variant<
        std::nullptr_t,
        std::shared_ptr<const add_track>,
        std::shared_ptr<const add_all_tracks>,
        std::shared_ptr<const remove_track>,
        std::shared_ptr<const remove_duplicates>,
        std::shared_ptr<const play_pause>,
        std::shared_ptr<const stop>,
        std::shared_ptr<const next>,
        std::shared_ptr<const previous>,
        std::shared_ptr<const random>,
        std::shared_ptr<const end>,
        std::shared_ptr<const repeat>,
        std::shared_ptr<const show_track>,
        std::shared_ptr<const show_playlist>>;

    /**
     * @brief of all the names of the commands
     */
    static const std::vector<std::string> &getCommandNames()
    {
        static const std::vector<std::string> names = {
            Command<add_track>::name(),
            Command<add_all_tracks>::name(),
            Command<remove_track>::name(),
            Command<remove_duplicates>::name(),
            Command<play_pause>::name(),
            Command<stop>::name(),
            Command<next>::name(),
            Command<previous>::name(),
            Command<random>::name(),
            Command<end>::name(),
            Command<repeat>::name(),
            Command<show_track>::name(),
            Command<show_playlist>::name()};
        return names;
    }

}
#endif

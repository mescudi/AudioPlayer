#ifndef MATCH_HPP // include guard
#define MATCH_HPP
#include <utility>
#include <variant>

namespace match // TODO lib
{
    /**
     * @brief Allows visiting a std::variant using a lambda function, with less verbose syntax.
     *
     * This function simplifies the syntax of visiting a std::variant object by allowing the use of lambda functions,
     * without the need to define a separate struct or class with operator() overloaded for each type in the variant.
     *
     * Example usage:
     *
     * @code{.cpp}
     * variant<int,float> myVar{2.5f};
     * match(myVar,
     *     [](int i) { // handle int value },
     *     [](float f) { // handle float value }
     * );
     * @endcode
     *
     * This is equivalent to:
     *
     * @code{.cpp}
     * variant<int,float> myVar{2.5f};
     * struct Visitor {
     *     void operator()(int i) { // handle int value }
     *     void operator()(float f) { // handle float value }
     * };
     * visitor(Visitor{}, myVar);
     * @endcode
     *
     * @tparam Variant   A std::variant object.
     * @tparam Matchers  A list of lambda functions that will be called to handle each variant type.
     * @param variant    A std::variant object.
     * @param matchers   A list of lambda functions, one for each possible type in the variant.
     * @return The result of calling the matching lambda function on the variant object.
     */
    namespace detail
    {

        template <class... Ts> // proposed to be in standard lib
        struct overloaded : Ts...
        {
            using Ts::operator()...;
        };

        template <class... Ts>
        overloaded(Ts...) -> overloaded<Ts...>;

    } // namespace detail

    template <typename Variant, typename... Matchers>
    auto match(Variant &&variant, Matchers &&...matchers)
    {
        return std::visit(
            detail::overloaded{std::forward<Matchers>(matchers)...},
            std::forward<Variant>(variant));
    }
}

#endif

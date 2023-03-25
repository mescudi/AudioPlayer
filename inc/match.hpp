#ifndef MATCH_HPP // include guard
#define MATCH_HPP
#include <utility>
#include <variant>

namespace match // TODO lib
{
    // std visit page applied  std to a variant
    /***/
    // allows
    /**--------------------------------
     * variant<int,float> myVar{2.5f};
     * visit(overloaded{
     * [](int i ){}
     * [](float  f ){}
     * },myVar);
     * --------------------------------
     * instead of
     * --------------------------------
     * variant<int,float> myVar{2.5f};
     * struct Visitor
     * {
     * void operator()(int i ) {}
     * void operator()(float f) {}
     * };
     * visitor(Visitor{},myVar);
     * --------------------------------
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

    /**
     * used to avoid the , myVar at the end   visitor(Visitor{},myVar); so that it is at the beginning just to be reader friendly
     * so you can write
     *
     * variant<int,float,...> myVar{2.5f};
     * match(var{
     * [](int i ){}
     * [](float  f ){}
     * });
     *
     * */
    template <typename Variant, typename... Matchers>
    auto match(Variant &&variant, Matchers &&...matchers)
    {
        return std::visit(
            detail::overloaded{std::forward<Matchers>(matchers)...},
            std::forward<Variant>(variant));
    }
}

#endif
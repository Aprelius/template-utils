#pragma once

#include <tuple>
#include <type_traits>

namespace Utilities {

    template<typename Container,
        size_t Index = 0,
        size_t LastIndex = std::tuple_size<Container>::value - 1U>
    struct TupleIterator
    {
        typedef typename std::tuple_element<Index, Container>::type Element;

        template<typename Fn>
        static void Iterate(Fn&& fn, Container& container)
        {
            fn(std::get<Index>(container));
            TupleIterator<Container, Index + 1, LastIndex>::Iterate(
                std::forward<Fn>(fn), container);
        }
    };

    template<typename Container, size_t LastIndex>
    struct TupleIterator<Container, LastIndex, LastIndex>
    {
        typedef typename std::tuple_element<LastIndex, Container>::type Element;

        template<typename Fn>
        static void Iterate(Fn&& fn, Container& container)
        {
            fn(std::get<LastIndex>(container));
        }
    };

    struct TupleUtils
    {
        template<typename Fn,
            typename ...Types,
            typename Container = std::tuple<Types...>>
        static void ForEach(Fn&& fn, Container& tuple)
        {
            TupleIterator<Container>::Iterate(std::forward<Fn>(fn), tuple);
        }
    };

}  // namespace Utilities

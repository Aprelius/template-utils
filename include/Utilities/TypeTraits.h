#pragma once

#include <type_traits>

namespace Utilities {

    template<bool...> struct bool_pack;
    template<bool... bs>
    using AllTrue = std::is_same<bool_pack<bs..., true>, bool_pack<true, bs...>>;

    template<class R, class... Ts>
    using AreAllConvertible = AllTrue<std::is_convertible<Ts, R>::value...>;

}  // namespace Utilities

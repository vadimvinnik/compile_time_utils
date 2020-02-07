#include "compile_time_utils.h"
#include <iostream>

constexpr char const* const good_names[] {
    "Odin",
    "Freya",
    "Baldr",
    "Heimdall",
};

template <typename T, T X>
constexpr T ensure_constexpr() { return X; }

int main() {
    std::cout
        << ensure_constexpr<bool, compile_time_utils::str_in("Baldr", good_names)>()
        << std::endl
        << ensure_constexpr<bool, compile_time_utils::str_in("Hoenir", good_names)>()
        << std::endl
        ;

    return 0;
}

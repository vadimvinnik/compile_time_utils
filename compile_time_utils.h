#pragma once

namespace compile_time_utils {

constexpr bool str_eq(char const* const s, char const* const t) {
    return (*s == *t)
        && (*s == 0 || str_eq(s + 1, t + 1));
}

// ps must be nullptr-terminated
constexpr bool str_in(char const* s, char const* const* ps) {
    return (*ps != nullptr)
        && (str_eq(s, *ps) || str_in(s, ps + 1));
}

} // namespace compile_time

namespace {

constexpr char const* const compile_time_utils_test_data[] {
    "one",
    "two",
    "three",
    nullptr
};

static_assert(
    compile_time_utils::str_eq("one", compile_time_utils_test_data[0]),
    "Must be recognized equal");

static_assert(
    !compile_time_utils::str_eq("one", compile_time_utils_test_data[2]),
    "Must be recognized non-equal");

static_assert(
    !compile_time_utils::str_eq("----", "---"),
    "Must be recognized non-equal");

static_assert(
    !compile_time_utils::str_eq("---", "----"),
    "Must be recognized non-equal");

static_assert(
    compile_time_utils::str_in("two", compile_time_utils_test_data),
    "Must be recognized as a member");

static_assert(
    !compile_time_utils::str_in("four", compile_time_utils_test_data),
    "Must be recognized as a non-member");

} // namespace 

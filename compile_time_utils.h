#pragma once

#include <cstdint>

namespace compile_time_utils
{

constexpr bool str_eq(char const* const s, char const* const t)
{
  return (*s == *t)
      && (*s == 0 || str_eq(s + 1, t + 1));
}

constexpr bool str_in(
    char const* const s,
    char const* const* const ps,
    char const* const* const ps_end)
{
  return (ps != ps_end)
      && (str_eq(s, *ps) || str_in(s, ps + 1, ps_end)); 
}

template <std::size_t N>
constexpr bool str_in(char const* const s, char const* const (&ps)[N])
{
  return str_in(s, &(ps[0]), &(ps[N]));
}

} // namespace compile_time

namespace {

constexpr char const* const compile_time_utils_test_data[] {
    "one",
    "two",
    "three"
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


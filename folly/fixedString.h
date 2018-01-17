//#pragma once
#include <folly/FixedString.h>
constexpr int N = 128;
constexpr folly::FixedString<N> name("jia");
constexpr folly::FixedString<N> at("@");
constexpr folly::FixedString<N> website("sina.com");
constexpr auto email = name+at+website;

void outString();

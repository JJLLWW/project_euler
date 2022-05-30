#define FMT_HEADER_ONLY
#include <fmt/core.h>
#include "euler.hpp"

// how to deal with loads of functions with very similar signatures?
int main() {
  // peuler::test_prob1();
  peuler::ull res = peuler::solve_prob1(1000, 3, 5);
  fmt::print("Got {}.", res);
}

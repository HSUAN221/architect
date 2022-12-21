// Copyright (c)
#ifndef SRC_ARCHITECT_DEFINITIONS_HPP_
#define SRC_ARCHITECT_DEFINITIONS_HPP_

// define public include headers
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include <tuple>
#include <type_traits>
#include <complex>
#include <stdexcept>
#include <limits>
#include <numeric>
#include <memory>
#include <queue>
#include <cctype>
#include <list>
#include <cassert>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <random>
#include <iomanip>


namespace architect {
using size_type = size_t;
using value_type = double;
using string_type = std::string;
std::random_device rd;
std::default_random_engine generator(rd());
}

#endif  // SRC_ARCHITECT_DEFINITIONS_HPP_

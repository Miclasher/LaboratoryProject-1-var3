#pragma once

#include <vector>
#include <string>
#include <map>

struct SimulationData {
    size_t N;
    std::vector<int> numbers;
    std::vector<int> given_frequencies;
};

struct SimulationResult {
    std::map<int, size_t> obtained_counts;
    std::vector<double> obtained_frequencies;
    double max_deviation = 0.0;
};
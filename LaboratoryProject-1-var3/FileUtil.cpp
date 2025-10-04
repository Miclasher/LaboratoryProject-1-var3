#include "FileUtil.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

template <typename T>
static std::vector<T> parseLine(const std::string& line) {
    std::vector<T> result;
    std::stringstream ss(line);
    T value;
    while (ss >> value) {
        result.push_back(value);
    }
    return result;
}

SimulationData FileUtils::readData(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + path);
    }

    SimulationData data;
    std::string line;

    if (!std::getline(file, line)) {
        throw std::runtime_error("Either file is empty or can't parse N");
    }
    try {
        data.N = std::stoull(line);
        if (data.N == 0) {
            throw std::invalid_argument("N must be positive integer");
        }
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Invalid N value " + std::string(e.what()));
    }

    if (!std::getline(file, line)) {
        throw std::runtime_error("Cannot find line with numbers");
    }
    data.numbers = parseLine<int>(line);

    if (!std::getline(file, line)) {
        throw std::runtime_error("Cannot find line with frequencies");
    }
    data.given_frequencies = parseLine<int>(line);

    if (data.numbers.empty() || data.given_frequencies.empty()) {
        throw std::runtime_error("Number and frequencies vectors can't be empty");
    }
    if (data.numbers.size() != data.given_frequencies.size()) {
        throw std::runtime_error("Number and frequencies vectors must be the same length");
    }

    return data;
}
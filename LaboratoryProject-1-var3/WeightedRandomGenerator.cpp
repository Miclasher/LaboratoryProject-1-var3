#include "WeightedRandomGenerator.h"

WeightedRandomGenerator::WeightedRandomGenerator(const std::vector<int>& numbers,
    const std::vector<int>& frequencies)
    : m_numbers(numbers), m_engine(std::random_device{}())
{
    if (numbers.empty() || frequencies.empty())
        throw std::invalid_argument("numbers and frequencies can not be empty");

    if (numbers.size() != frequencies.size())
        throw std::invalid_argument("size of numbers and frequencies can not be equal");

    for (int f : frequencies) {
        if (f <= 0)
            throw std::invalid_argument("frequencies must be positive");
    }

    m_distribution = std::discrete_distribution<>(frequencies.begin(), frequencies.end());
}

int WeightedRandomGenerator::operator()() {
    int index = m_distribution(m_engine);
    return m_numbers[index];
}
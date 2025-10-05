#include "FrequencyTester.h"
#include <numeric>
#include <stdexcept>
#include <cmath>
#include <algorithm>

FrequencyTester::FrequencyTester(const SimulationData& data)
    : m_data(data) {
    if (data.numbers.empty() || data.given_frequencies.empty()) {
        throw std::invalid_argument("Test data cannot be empty");
    }

    m_generator = std::make_unique<WeightedRandomGenerator>(data.numbers, data.given_frequencies);
}

void FrequencyTester::run() {
    for (int number : m_data.numbers) {
        m_result.obtained_counts[number] = 0;
    }

    for (size_t i = 0; i < m_data.N; ++i) {
        int generated_number = (*m_generator)();
        m_result.obtained_counts[generated_number]++;
    }

    calculateStatistics();
}

const SimulationResult& FrequencyTester::getResults() const {
    return m_result;
}

void FrequencyTester::calculateStatistics() {
    long long total_given_freq = std::accumulate(m_data.given_frequencies.begin(), m_data.given_frequencies.end(), 0LL);

    if (total_given_freq == 0) {
        throw std::runtime_error("Frequency sum cannot be zero");
    }

    m_result.obtained_frequencies.clear();
    m_result.max_deviation = 0.0;

    for (size_t i = 0; i < m_data.numbers.size(); ++i) {
        int number = m_data.numbers[i];
        int given_freq = m_data.given_frequencies[i];

        double obtained_freq = static_cast<double>(m_result.obtained_counts[number]) / m_data.N;
        double expected_freq = static_cast<double>(given_freq) / total_given_freq;

        m_result.obtained_frequencies.push_back(obtained_freq);

        double deviation = std::abs(obtained_freq - expected_freq);
        if (deviation > m_result.max_deviation) {
            m_result.max_deviation = deviation;
        }
    }
}
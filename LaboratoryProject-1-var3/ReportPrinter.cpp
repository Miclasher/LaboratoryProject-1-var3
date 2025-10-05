#include "ReportPrinter.h"
#include <iostream>
#include <iomanip>
#include <numeric>

void ReportPrinter::print(const SimulationData& data, const SimulationResult& result) {
    long long total_given_freq = std::accumulate(data.given_frequencies.begin(), data.given_frequencies.end(), 0LL);

    std::cout << "--- Input data ---\n";
    std::cout << "Number of generations (N): " << data.N << "\n\n";

    std::cout << "--- Simulation result ---\n";
    std::cout << std::left
        << std::setw(10) << "Number "
        << std::setw(22) << "Expected frequency"
        << std::setw(22) << "Obtained frequency"
        << std::setw(15) << "Count"
        << "\n";
    std::cout << std::string(55, '-') << "\n";

    std::cout << std::fixed << std::setprecision(5);

    for (size_t i = 0; i < data.numbers.size(); ++i) {
        double expected_freq = static_cast<double>(data.given_frequencies[i]) / total_given_freq;
        std::cout << std::left
            << std::setw(10) << data.numbers[i]
            << std::setw(22) << expected_freq
            << std::setw(22) << result.obtained_frequencies[i]
            << std::setw(15) << result.obtained_counts.at(data.numbers[i])
            << "\n";
    }

    std::cout << "\n" << std::string(55, '=') << "\n";
    std::cout << "Max frequency deviation: " << result.max_deviation << "\n";
    std::cout << std::string(55, '=') << "\n";
}
#pragma once

#include "DataTypes.h"
#include "WeightedRandomGenerator.h" 
#include <memory>

class FrequencyTester {
public:
    explicit FrequencyTester(const SimulationData& data);
    void run();
    const SimulationResult& getResults() const;

private:
    void calculateStatistics();

    const SimulationData& m_data;
    std::unique_ptr<WeightedRandomGenerator> m_generator;
    SimulationResult m_result;
};
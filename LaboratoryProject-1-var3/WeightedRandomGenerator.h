#pragma once

#include <vector>
#include <random>
#include <stdexcept>
#include <numeric>

class WeightedRandomGenerator
{
	std::vector<int> m_numbers;
	std::mt19937 m_engine;
	std::discrete_distribution<> m_distribution;

public:
	WeightedRandomGenerator(const std::vector<int>& numbers, const std::vector<int>& frequencies);
	int operator()();
};
#pragma once

#include "DataTypes.h"

class ReportPrinter {
public:
    static void print(const SimulationData& data, const SimulationResult& result);
};
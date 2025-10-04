#pragma once

#include "DataTypes.h"
#include <string>

class FileUtils {
public:
    static SimulationData readData(const std::string& path);
};
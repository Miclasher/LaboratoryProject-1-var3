//Compiler: MSVC
//Developers: Mykhailo Geilovych & Vladyslav Barylo

#include <iostream>
#include <stdexcept>

#include "DataTypes.h"
#include "FileUtil.h"
#include "FrequencyTester.h"
#include "ReportPrinter.h"

int main(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            std::cerr << "Error: Must provide file path argument.\n";
            std::cerr << "Usage example: " << argv[0] << " input.txt\n";
            return 1;
        }

        std::cout << "Reading from file '" << argv[1] << "'...\n";
        SimulationData data = FileUtils::readData(argv[1]);

        std::cout << "Starting simulation...\n";
        FrequencyTester tester(data);
        tester.run();
        std::cout << "Simulation finished.\n\n";

        ReportPrinter::print(data, tester.getResults());

    }
    catch (const std::exception& e) {
        std::cerr << "\nCritical error: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "\nCritical error: Unknown error" << std::endl;
        return 1;
    }

    return 0;
}
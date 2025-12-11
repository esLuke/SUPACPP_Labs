#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "FiniteFunctions.h"

int main()
{
    std::string file = "../../Data/MysteryData22212.txt";
    std::ifstream infile(file);

    if (!infile.is_open())
    {
        std::cerr << "Error: Cannot open this file: " << file << std::endl;
        return 1;
    }

    std::vector<double>data;
    double value;
    while (infile >> value)
    {
        data.push_back(value);
    }
    std::cout << "Load " << data.size() << " points from file." << std::endl;

    double xmin = -10.0;
    double xmax = 10.0;
    FiniteFunction f(xmin, xmax, "NormalisedInvXsq");

    f.plotData(data, 50, true);
    f.plotFunction();
    f.printInfo();

    return 0;
}
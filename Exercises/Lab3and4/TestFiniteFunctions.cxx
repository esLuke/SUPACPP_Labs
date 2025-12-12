#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "FiniteFunctions.h"
#include "AdvancedFunctions.h"

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
    int bins = 50;
    int sampleNum = 100000;

    std::cout << " ============ Fitting Normal Distribution ============ " << std::endl;
    NormalDistribution norm(0.0, 2.0, xmin, xmax);
    norm.plotData(data, bins, true);
    norm.plotFunction();
    norm.printInfo();

    std::cout << " ============ Fitting Cauchy-Lorentz Distribution ============ " << std::endl;
    CauchyDistribution cl(0.0, 1.8, xmin, xmax);
    cl.plotData(data, bins, true);
    cl.plotFunction();
    cl.printInfo();

    std::cout << " ============ Fitting Crystal Ball Distribution ============ " << std::endl;
    CrystalDistribution cb(0.0, 1.92, 1.5, 2.0, xmin, xmax);
    cb.plotData(data, bins, true);
    std::cout << "----->>> Start sampling ----->>> " << std::endl;
    std::cout << "Generating " << sampleNum << " metropolis samples..." << std::endl;
    std::cout << "<<<----- Finish sampling <<<-----" << std::endl;
    std::vector<double> metroData = cb.SampleMetropolis(sampleNum, 2.5, 22212);
    cb.plotData(metroData, bins, false);
    cb.plotFunction();
    cb.printInfo();

    std::cout << " ============ Fitting Incxsquared ============ " << std::endl;
    FiniteFunction f(xmin, xmax, "NormalisedInvXsq");
    f.plotData(data, bins, true);
    f.plotFunction();
    f.printInfo();

    return 0;
}
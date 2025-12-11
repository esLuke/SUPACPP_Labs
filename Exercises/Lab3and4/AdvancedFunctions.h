#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include "FiniteFunctions.h"

// Normal Distribution
class NormalDistribution: public FiniteFunction
{
    public: 
        NormalDistribution(double mu, double sigma, double x_min, double x_max);
        double callFunction(double x) override;
        void printInfo() override;
    private:
        double mu;
        double sigma;
};

// Cauchy-Lorentz Distribution
class CauchyDistribution: public FiniteFunction
{
    public:
        CauchyDistribution(double x0, double gamma, double x_min, double x_max);
        double callFunction(double x) override;
        void printInfo() override;
    private:
        double x0;
        double gamma;

};

// Crystal Ball Distriubution
class CrystalDistribution: public FiniteFunction
{
    public:
        CrystalDistribution(double x_bar, double sigma, double alpha, double n,
                            double x_min, double x_max);
        double callFunction(double x) override;
        void printInfo() override;
    private:
        double x_bar;
        double sigma;
        double alpha;
        double n;
        double A;
        double B;
};

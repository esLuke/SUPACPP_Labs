#include <istream>
#include <cmath>
#include "AdvancedFunctions.h"

/*
############################################################
1. Normal Distribution
############################################################
*/ 

NormalDistribution::NormalDistribution(double mu, double sigma, double x_min, double x_max)
    : FiniteFunction(x_min, x_max, "Normal"),
      mu(mu),
      sigma(sigma)
{
    // pass
}
double NormalDistribution::callFunction(double x)
{
    return std::exp(-0.5*std::pow((x-mu)/sigma, 2));
}
void NormalDistribution::printInfo()
{
    FiniteFunction::printInfo();
    std::cout << "Params: mu = " << mu << ", sigma = " << sigma << std::endl; 
}

/*
############################################################
2. Cauchy-Lorentz Distribution
############################################################
*/ 

CauchyDistribution::CauchyDistribution(double x0, double gamma, double x_min, double x_max)
    : FiniteFunction(x_min, x_max, "Cauchy-Lorentz"),
      x0(x0),
      gamma(gamma)
{
    // pass
}
double CauchyDistribution::callFunction(double x)
{
    return 1.0/(1.0+std::pow(((x-x0)/gamma), 2));
}
void CauchyDistribution::printInfo()
{
    FiniteFunction::printInfo();
    std::cout << "Params: x0 = " << x0 << ", gamma = " << gamma << std::endl;
}

/*
############################################################
3. Crystal Ball Distribution
############################################################
*/ 

CrystalDistribution::CrystalDistribution(double x_bar, double sigma, 
                                         double alpha, double n, double x_min, double x_max)
    : FiniteFunction(x_min, x_max, "CrystalBall"),
      x_bar(x_bar), sigma(sigma),
      alpha(alpha), n(n)
{
    double absAlpha = std::abs(alpha);
    A = std::pow(n/absAlpha, n)*std::exp(-0.5*absAlpha*absAlpha);
    B = n/absAlpha-absAlpha;
}
double CrystalDistribution::callFunction(double x)
{
    double z = -(x-x_bar)/sigma;
    if (z > -alpha)
    {
        return std::exp(-0.5*z*z);
    }
    else
    {
        return A*std::pow((B-z), -n);
    }
}
void CrystalDistribution::printInfo()
{
    FiniteFunction::printInfo();
    std::cout << "Params: x_bar = " << x_bar << ", sigma = " << sigma 
    << ", alpha = " << alpha << ", n = " << n << std::endl;
}
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include <iomanip>

int main(int argc, char *argv[]) 
{
    // take 2 args: r and sample numbers
    if (argc < 3) 
    {
        std::cerr << "Name: " << argv[0] << " <radius> <Nsamples>" << std::endl;
        return 1;
    }

    double r = std::stod(argv[1]);
    // ensure large quantity
    long long Nsamples = std::stoll(argv[2]);

    std::cout << "Calculating pi using " << Nsamples << " samples with radius " << r << "..." << std::endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-r, r);

    long long inside = 0;
    for (long long i = 0; i < Nsamples; ++i) 
    {
        double x = dist(gen);
        double y = dist(gen);
        if ((x*x + y*y) <= (r*r)) 
        {
            inside++;
        }
    }
    double pi = 4.0 * (static_cast<double>(inside) / static_cast<double>(Nsamples));

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Estimated Pi: " << pi << std::endl;
    std::cout << "Actual Pi:    " << M_PI << std::endl; // 
    std::cout << "Residual:   " << std::abs(pi - M_PI) << std::endl;

    return 0;
}
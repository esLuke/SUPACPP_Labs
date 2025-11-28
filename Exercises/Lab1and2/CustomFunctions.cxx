#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include "CustomFunctions.h"

// Instruction 1&2: load th data
std::vector<Point> DataLoader(std::string filename)
{
    std::ifstream file(filename);
    std::vector<Point> data;
    if (!file.is_open())
    {
        std::cerr <<"Error: Cannot open " << filename << std::endl;
        return data;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) 
    {
        std::stringstream ss(line);
        float x, y;
        char comma;

        if (ss >> x >> comma >> y)  //be careful the comma
        {
            data.push_back({x, y});
        }
    }
    return data;
}

// Instruction 3: print n lines
void LinesPrinter(std::vector<Point>& data, int N)
{
    if (data.empty())     // need to check
    {
        std::cout << "No data loaded.\n";
        return;
    }

    if (N > data.size())
    {
        std::cout << "N should be smaller than total data, showing the data header: \n";
        N = 5;
    }
    for (int i = 0; i < N; ++i)
    {
        std::cout << data[i].x << " " << data[i].y << std::endl; 
    }
}

// Instruction 4: calculate the magtnitude
std::vector<float> ComputeMagnitudes(std::vector<Point>& data) {
    std::vector<float> mags;
    for (int i = 0; i < data.size(); ++i) 
    {
        float mag = std::sqrt(data[i].x * data[i].x + data[i].y * data[i].y);
        mags.push_back(mag);
    }
    return mags;
}

// Instruction 5&6: fit a straight line
void FitLine(std::vector<Point>& data, float& p, float& q) {
    int N = data.size();
    float Sx = 0, Sy = 0, Sxx = 0, Sxy = 0;

    for (int i = 0; i < N; ++i) // elements for further calculate
    {
        Sx += data[i].x;
        Sy += data[i].y;
        Sxx += data[i].x * data[i].x;
        Sxy += data[i].x * data[i].y;
    }

    p = (N * Sxy - Sx * Sy) / (N * Sxx - Sx * Sx);
    q = (Sy - p * Sx) / N;
}

// Instruction 8: calculate the chi^2

std::vector<float> ErrLoader(std::string filename)
{
    std::ifstream file(filename);
    std::vector<float> sigma;

    if (!file.is_open())
    {
        std::cerr << "Error: Cannot open: " << filename << std::endl;
        return sigma;
    }

    std::string line;
    std::getline(file, line); // skip the first line

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        float x, s;
        char comma;

        if (ss >> x >> comma >> s)
        {
            sigma.push_back(s);
        }
    }

    return sigma;
}


float ChiSqNOF(std::vector<Point>& data, float p, float q, std::vector<float>& sigma) 
{
    float chi2 = 0;
    int N = data.size();
    for (int i = 0; i < N; ++i) 
    {
        float yfit = p * data[i].x + q;
        float diff = data[i].y - yfit;
        chi2 += (diff * diff) / (sigma[i] * sigma[i]);
    }
    int ndof = N - 2;
    return chi2 / ndof;
}

// Instruction 9: calculate x^y

float RecursivePow(float x, int y) // definition from equations
{
    if (y == 0) return 1;
    if (y < 0) return 1.0 / RecursivePow(x, -y);
    if (y % 2 == 0) {
        float half = RecursivePow(x, y / 2);
        return half * half;
    } else {
        return x * RecursivePow(x, y - 1);
    }
}

std::vector<float> ComputePowResults(std::vector<Point>& data)
{
    std::vector<float> results;
    for (int i = 0; i < data.size(); ++i) {
        int y_int = (int)std::round(data[i].y);
        results.push_back(RecursivePow(data[i].x, y_int)); // call another func
    }
    return results;
}


// Instruction 10: save files

void SaveFiles(std::string filename, std::vector<float>& data)
{
    std::ofstream file(filename);
    for (int i = 0; i < data.size(); ++i)
    {
        file << data[i] << std::endl;
    }
}

void SaveLineFit(float p, float q, std::string filename) 
{
    std::ofstream file(filename);
    file << "Fitted line: y = " << p << " * x + " << q << std::endl;
}

void SaveChi2(std::string filename, float chi2ndof) 
{
    std::ofstream file(filename);
    file << "chi2/ndof = " << chi2ndof << std::endl;
}
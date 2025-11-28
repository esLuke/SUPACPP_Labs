#include <string>
#include <vector>

#pragma once

struct Point
 {
    float x;
    float y;
 };
 
// Instruction 1&2: load the data
std::vector<Point> DataLoader(std::string filename);
// Instruction 3: print the data
void LinesPrinter(std::vector<Point>& Data, int N);

// Instruction 4: magnitude
std::vector<float> ComputeMagnitudes(std::vector<Point>& data);

// Instruction 5&6: fit a straightline
void FitLine(std::vector<Point>& data, float& p, float& q);

// Instruction 8: calculate the chi^2
std::vector<float> ErrLoader(std::string filename);
float ChiSqNOF(std::vector<Point>& data, float p, float q, std::vector<float>& sigma);

// Instruction 9: calculate x^y
float RecursivePow(float x, int y);
std::vector<float> ComputePowResults(std::vector<Point>& data);

// Instruction 10: save fitted line
void SaveFiles(std::string filename, std::vector<float>& data);
void SaveLineFit(float p, float q, std::string filename);
void SaveChi2(std::string filename, float chi2ndof);

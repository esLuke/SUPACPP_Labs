#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include "CustomFunctions.h"

int main()
{
    // Instruction 1&2: load the data
    std::vector<Point> data = DataLoader("input2D_float.txt");
    std::vector<float> sigma;
    float p = 0, q = 0;

    while (true)
    {
        std::cout << "Choose an option plz :)\n";
        std::cout << "1. Print N lines \n";
        std::cout << "2. Compute the magnitude \n";
        std::cout << "3. Fit Straight line \n";
        std::cout << "4. Compute ChiSquare \n";
        std::cout << "5. Compute x^y \n";
        std::cout << "6. Save all results \n";
        std::cout << "7. Exit \n";

        int opt;
        if (!(std::cin >> opt)) 
        {
            std::cin.clear(); // so the program can break
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Please enter a number between 1 and 7.\n";
            continue;  
        }
        
        if (opt == 1) // print n lines
        {
            int N;
            std::cout << "How many lines you want to print? Enter N: \n";
            std::cin >> N;
            LinesPrinter(data, N);
        }
        else if (opt == 2) // compute magnitudes
        {
            std::vector<float> mags = ComputeMagnitudes(data);
            for (int i = 0; i < mags.size(); ++i)
                std::cout << mags[i] << std::endl;

        }
        else if (opt == 3) // fit the data
        {
            FitLine(data, p , q);
            std::cout << "Fitted line: y = " << p << "* x + " << q <<std::endl;
        }

        else if (opt == 4) // compute the chi2
        {
            sigma = ErrLoader("error2D_float.txt");
            FitLine(data, p , q);
            float chinof = ChiSqNOF(data, p , q, sigma);
            std::cout << "Chi^2/NDOF = " << chinof << std::endl;
        }

        else if (opt == 5) //x^y
        {
            std::vector<float> results = ComputePowResults(data);
            for (int i = 0; i < results.size(); ++i)
                std::cout << results[i] << std::endl;
        }

        else if (opt == 6) // save all
        {
            std::vector<float> mags = ComputeMagnitudes(data);
            FitLine(data, p, q);
            sigma = ErrLoader("error2D_float.txt");
            float chinof = ChiSqNOF(data, p , q, sigma);
            std::vector<float> results = ComputePowResults(data);

            SaveFiles("magnitudes.txt", mags);
            SaveLineFit(p, q, "fittedline.txt");
            SaveChi2("Chi2_ndof.txt", chinof);
            SaveFiles("xpower2y.txt", results);
            
            std::cout << "All results saved. \n";
        }
        
        else if (opt == 7) // say gb
        {
            break;
        }

        else 
        {
            std::cout << "Invalid option, try again. \n";
        }
    }  

    return 0;
}
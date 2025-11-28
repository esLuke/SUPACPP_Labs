#include <iostream>
#include <cmath>

// create a generic function capable of calculating the magnitude of a 2D vector
float ComputeMagnitude(float x, float y)
{
    return std::sqrt(x*x+y*y);
}

int main()
{
    // it should take as input from the user two values for the components 
    float x;
    float y;
    std::cout << "Input x: ";
    std::cin >> x;
    std::cout << "Input y: ";
    std::cin >> y;
    float mag = ComputeMagnitude(x, y);
    // print to the terminal the magnitude
    std::cout << "magnitude = " << mag <<std::endl;
    return 0;
}
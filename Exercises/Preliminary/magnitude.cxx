#include <iostream>
#include <cmath>


int main()
{
    // declare two variables x and y and assign them the values 7.5 and 3.4 respectively.
    float x = 7.5;
    float y = 3.4;
    // compute the magnitude of the vector
    float mag = std::sqrt(x*x+y*y);
    // print the answer to the terminal
    std::cout << "magnitude = " << mag << std::endl;
    return 0;
}
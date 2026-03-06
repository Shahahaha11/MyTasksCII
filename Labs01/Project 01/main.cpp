#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include "vanilla_mc.h"
#include "digital_mc.h"
#include "double_digital_mc.h"
#include "power_option.h" // Problem 3 Extra
#include "quadratic_option.h" // Problem 4 Extra

// TASK :
//  Modify project01 to obtain price of:
// • European put price,
// • digital option,
// • double digital option.

// DERIVED CLASS NAMING :
// This uses monte carlo pricing engine.
// Future extention classes can have different names (eg .VanillaOptionBSClosedForm, VanillaOptionFD)
int main() {
    double spot = 95;
    double strike = 105;
    double expiry = 0.5;
    double vol = 0.3;
    double r = 0.05;
    long unsigned int numPaths = 100000;
    char optType = 'c';
    double value = 1.0;  // Q payoff for digital_option and double_digital_option
    std::srand(time(nullptr)); //nullptr to avoid future name clashes
    
    vanilla_option_mc vop(expiry, strike, spot, vol, r, numPaths, optType);
    digital_option_mc dov(value, expiry, strike, spot, vol, r, numPaths, optType);
    power_option_mc pov(expiry, strike, spot, vol,  r, numPaths, optType);// Problem 3
    quadratic_option qov(expiry, strike, spot, vol,  r, numPaths, optType); //Problem 4
    double upper (110.0);
    double lower (70.0);
    
    double_digital_option_mc ddov (value, expiry, upper, lower, spot, vol, r, numPaths);

    std::cout << "Vanilla Option Price :" << vop.pricer() << std::endl; // vanilla pricer
    std::cout << "Digital Option Price :" << dov.pricer() << std::endl; // digital option pricer
    std::cout << "Double Digital Option Price :" << ddov.pricer() << std::endl; 
    std::cout << "Quadratic Option Price :" << pov.pricer() << std::endl; 
    std::cout << "Quadratic Option Price :" << qov.pricer() << std::endl; 

    return 0;
}


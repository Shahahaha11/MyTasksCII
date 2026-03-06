#include <iostream>
#include <fstream>
#include "simple_monte_carlo.h"
#include "option.h"
#include "custom_option.h"
#include<iostream>

int main() {
    double expiry = 0.5;
	double low = 100;
	double up = 120;
	double spot = 95;
	double strike =  100;
	double vol = 0.2;
	double r = 0.06;
	unsigned long number_of_paths = 10000;
	int choice_of_custom = 1;

    Payoff* thePayoff = nullptr;

    if (choice_of_custom == 1) {
        thePayoff = new payoffCustomCall(strike) ; // Here you put whatever your operator needs to compute. Missing variable is strike
    }
    if (choice_of_custom == -1) {
        thePayoff = new payoffCustomPut(strike);
    }    
    Option opt(*thePayoff, expiry);

    double result = simple_monte_carlo(opt,spot, vol, r, number_of_paths);
    std::cout << "Option Price :" << result << std::endl;
    return 0;
}

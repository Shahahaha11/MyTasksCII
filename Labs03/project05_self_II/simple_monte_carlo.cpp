#include "simple_monte_carlo.h"
#include "random.h"
#include <iostream>
using namespace std;
double simple_monte_carlo(Option& opt,
                        double spot, 
                        double vol, 
                        double r,
                        unsigned long number_of_paths ){

double expiry = opt.get_expiry();
double variance = vol * vol* expiry;
double rootVariance = sqrt(variance);
double itoCorrection = -0.5 * variance;
double movedSpot = spot * exp( itoCorrection + r * expiry);
double thisSpot;
double runningSum = 0.0;

for(unsigned long i = 0; i < number_of_paths ; ++i){
    double thisGaussian = get_one_gaussian_by_box_muller();
    thisSpot = movedSpot * exp(rootVariance * thisGaussian);
    double thisPayoff = opt.get_option_payoff(thisSpot);
    runningSum += thisPayoff;
}
double mean = runningSum/number_of_paths;
mean *= exp(-r* expiry); 
return mean;

};

#pragma once
#include "monte_carlo_pricer.h"
#include "random1.h"
#include "testing.h"
#include<cstdlib>
#include<cmath>

// Extra : Problem 4 : In project 1 format. Your feedback will be appreciated.

class quadratic_option:  public monte_carlo_pricer{
private :
    double expiry;
    double strike;
    double spot;
    double vol;
    double r;
    unsigned long numPaths;
    char a;
public :
    //  Default constructor
    quadratic_option(): expiry(0.0) ,strike(0.0), spot(0.0) , vol(0.0), r(0.0), numPaths(0) , a('c') {}

    // Main constructor
    quadratic_option(double expiry, double strike, double spot, double vol, double r, unsigned long numPaths, char a)
    : expiry(expiry), strike(strike), spot(spot), vol(vol), r(r), numPaths(numPaths) , a(a){}


    // double pricer() {return (spot- strike)}
double pricer() const override
{
    double variance = vol * vol * expiry;
    double root_variance = sqrt(variance);
    double ito_correction = -0.5 * variance;

    double moved_spot = spot * exp(r * expiry + ito_correction);
    double running_sum = 0.0;


    for (unsigned long i = 0; i < numPaths; ++i)
    {
        double g = get_one_gaussian_by_box_muller();
        double this_spot = moved_spot * exp(root_variance * g);
// power option : payoff = max^2(St-K, 0)
        double strike2 = strike*strike;
        double this_spot2 =  this_spot * this_spot;
        if (a == 'c') {
            (this_spot >= strike) ? running_sum += this_spot2 - strike2 : running_sum += 0.0;
        } else if (a == 'p') {
             (this_spot <= strike) ? running_sum += strike2- this_spot2 : running_sum += 0.0;
        } else ASSERT(false);
    }

    double mean = running_sum / static_cast<double>(numPaths);
    return mean * exp(-r * expiry);
}
};


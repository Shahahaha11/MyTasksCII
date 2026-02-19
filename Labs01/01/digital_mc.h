#pragma once
#include "monte_carlo_pricer.h"
#include "random1.h"
#include "testing.h"
#include<cstdlib>
#include<cmath>

using namespace std;
// #include<iostream>


class digital_option_mc:  public monte_carlo_pricer{
private :
    double value;
    double expiry;
    double strike;
    double spot;
    double vol;
    double r;
    unsigned long numPaths;
    char a;

public :
    //  Default constructor
    digital_option_mc(): value(0.0),  expiry(0.0) ,strike(0.0), spot(0.0) , vol(0.0), r(0.0), numPaths(0) , a('c') {}

    // Main constructor
    digital_option_mc(double value, double expiry, double strike, double spot, double vol, double r, unsigned long numPaths, char a)
    : value(value), expiry(expiry), strike(strike), spot(spot), vol(vol), r(r), numPaths(numPaths), a(a) {}

// double pricer() {return (Q)}
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

        if (a == 'c') {
            (this_spot >= strike) ? running_sum += value : running_sum += 0.0;
        } else if (a == 'p') {
             (this_spot <= strike) ? running_sum += value : running_sum += 0.0;
        } else ASSERT(false);
        
    }
        double mean = running_sum / static_cast<double>(numPaths);
        return mean * exp(-r * expiry);
}

};


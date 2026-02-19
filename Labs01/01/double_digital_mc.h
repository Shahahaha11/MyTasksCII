#pragma once
#include "monte_carlo_pricer.h"
#include "random1.h"
#include "testing.h"
#include<cstdlib>
#include<cmath>

using namespace std;
// #include<iostream>


class double_digital_option_mc :  public monte_carlo_pricer{
private :
    double value;
    double upper;
    double lower;
    double expiry;
    double spot;
    double vol;
    double r;
    unsigned long numPaths;

public :
    //  Default constructor
    double_digital_option_mc() : value(0.0),  expiry(0.0) ,upper(0.0), lower(0.0), spot(0.0) , vol(0.0), r(0.0), numPaths(0) {}

    // Main constructor
    double_digital_option_mc(double value, double expiry, double upper, double lower, double spot, double vol, double r, unsigned long numPaths)
    : value(value), expiry(expiry), upper(upper), lower(lower), spot(spot), vol(vol), r(r), numPaths(numPaths) {}

    
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
        (this_spot <= upper || this_spot >= lower ) ? running_sum += value : running_sum += 0.0;
    }
    
        double mean = running_sum / static_cast<double>(numPaths);
        return mean * exp(-r * expiry);
}

};


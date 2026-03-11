#include "simple_mc4.h"

#include "vanilla2.h"
#include "random1.h"
using namespace std;
// The only purpose of this function is to estimate the future price in present value terms. 
// We are basically in a room where there is one spot where the one red marble will land in the final chapter.
// We are trying to peredict where the marble will end up to price the contract we have .
//  Lets see how we solve the problem.
double simple_monte_carlo4(const VanillaOption &the_option,
    double spot,
    double vol,
    double r, 
    unsigned long number_of_paths){
        double expiry = the_option.get_expiry();
        double variance = vol*vol*expiry;
        double root_variance = sqrt(variance);
        double ito_correction = -0.5 * variance;
        double moved_spot = spot * exp(r*expiry + ito_correction);
        double thisSpot;
        double running_sum = 0.0;

        for (unsigned int i = 0; i < number_of_paths; ++i){ 
            // We throw the marbles a million times . 
            // And average our wins
            double this_gaussian = get_one_gaussian_by_box_muller();
            this_spot = moved_spot * exp(root_variance * this_gaussian);
            double this_payoff = the_option.get_option_payoff(this_spot);
            

        }


    }

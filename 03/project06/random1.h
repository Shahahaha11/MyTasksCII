#ifndef RANDOM1_H
#define RANDOM1_H

// Returns one approximately standard normal random value using the summation method.
double get_one_gaussian_by_summation();

// Returns one standard normal random value using the Box-Muller method.
double get_one_gaussian_by_box_muller();
#endif

#include<iostream>
#include "option.h"
#ifndef SIMPLE_MONTE_CARLO_H
#define SIMPLE_MONTE_CARLO_H

double simple_monte_carlo(Option& opt,
                        double spot, 
                        double vol, 
                        double r,
                        unsigned long number_of_paths );


#endif
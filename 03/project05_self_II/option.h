#ifndef OPTION_H
#define OPTION_H

#include "payoff.h"

class Option {
public:
    Option(Payoff &thePayOff, double expiry);
    double get_option_payoff (double spot) const;
    double get_expiry() const;    
private:
    Payoff &thePayOff;
    double expiry;
};

#endif

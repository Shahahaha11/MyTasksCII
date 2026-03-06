#include "option.h"
#include "payoff.h"
Option::Option(Payoff &thePayOff_, double expiry_) : thePayOff(thePayOff_), expiry(expiry_){}

// KEY FUNCTION :
double Option::get_option_payoff (double spot) const{
    return thePayOff(spot);
}

double Option::get_expiry() const{
    return expiry;
}


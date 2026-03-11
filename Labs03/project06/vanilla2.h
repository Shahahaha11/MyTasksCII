#ifndef VANILLA1_H
#define VANILLA1_H
#include "payoff3.h"

class VanillaOption {
public :
    VanillaOption(Payoff &thePayOff_, double expiry);
    VanillaOption(Payoff &thePayOff_);

    VanillaOption &operator=(const VanillaOption &original); // this will let you write option1 = option2
    ~VanillaOption();

    double get_expiry() const ;
    double get_payoff(double spot) const ;

private:
    double expiry;  
    Payoff *the_payoff_ptr;
};


#endif
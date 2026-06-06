#include "vanilla2.h"
#include "payoff3.h"

VanillaOption::VanillaOption(Payoff &thePayOff_, double expiry_){
    expiry =  expiry_;
    the_payoff_ptr = thePayOff_.clone();
}

VanillaOption &VanillaOption::operator=(const VanillaOption &original){
    {
        if (this != &original)
        {
            expiry = original.expiry;
            delete the_payoff_ptr;
            the_payoff_ptr = original.the_payoff_ptr->clone();
        }
        return *this;
    }
} 
// example call :
// VanillaOption option1(payoff1, 0.5);
// VanillaOption option2(payoff2, 1.0);
// option2 = option1;

double VanillaOption::get_payoff(double spot) const {
    return (*the_payoff_ptr)(spot)

};
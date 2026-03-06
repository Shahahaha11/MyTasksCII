#pragma once
#include "payoff.h"

// payOff object will generally go in simple monte carlo where it will eventually access the strike.
class payoffCustomCall : public Payoff {
public:
    payoffCustomCall(double strike) ;
    virtual double operator() (double spot) const override;
    virtual ~payoffCustomCall() = default;
private:
    double strike_;
};

class payoffCustomPut : public Payoff{
public :
    payoffCustomPut(double strike);
    virtual double operator() (double spot) const override;
    virtual ~payoffCustomPut() = default;
private :
    double strike_;    
};
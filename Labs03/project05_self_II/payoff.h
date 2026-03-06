#ifndef PAYOFF_H
#define PAYOFF_H

class Payoff {    
public :
    Payoff(){};
    virtual  double operator()(double spot) const = 0;
    virtual ~Payoff() = default;
};


#endif



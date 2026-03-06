
#ifndef PAYOFF_CUSTOM_PUT_H
#define PAYOFF_CUSTOM_PUT_H

#include "payoff3.h"

class PayOffCustomPut : public PayOff
{
public:
	// construtor
	PayOffCustomPut(double strike_);
	// method (function)
	virtual double operator()(double spot) const;
	// destructor
	virtual ~PayOffCustomPut() {}
    
private:
	// member (attribute)
	double strike;
};

#endif

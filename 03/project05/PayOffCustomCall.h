#ifndef PAYOFF_CUSTOM_CALL_H
#define PAYOFF_CUSTOM_CALL_H

#include "payoff3.h"


class PayOffCustomCall : public PayOff
{
public:
	// construtor
	PayOffCustomCall(double strike_);
	// method (function)
	virtual double operator()(double spot) const;
	// destructor
	virtual ~PayOffCustomCall() {}

private:
	// member (attribute)
	double strike;
};

#endif


// Add to the Project05 two new subclasses: PayOCustomCall and
// PayOCustomPut inheriting after the PayO base class with the
// following payo functions:
// the CALL pays o:
// • 0 if Spot at expiry is smaller or equal than Strike
// • 1 if Spot at expiry is greater than Strike by no more than 5%
// • 2 if Spot at expiry is greater than Strike by more than 5% and less
// than 10%
// • 3 if Spot at expiry is greater than Strike bo more than 10%
// the PUT pays o:
// • 0 if Spot at expiry is greater or equal than Strike
// • 1 if Spot at expiry is smaller than Strike by no more than 5%
// • 2 if Spot at expiry is smaller than Strike by more than 5% and less
// than 10%
// • 3 if Spot at expiry is smaller than Strike bo more than 10%
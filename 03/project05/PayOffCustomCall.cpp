
#include "PayOffCustomCall.h"
#include "minmax.h"
#include <stdexcept>

PayOffCustomCall::PayOffCustomCall(double strike_) {strike = strike_;}


// definition of a function
double PayOffCustomCall::operator()(double spot) const
{
    if (spot/strike <= 1.00) return 0.0;
    else if (spot/strike <=1.05) return 1.0;
    else if (spot/strike <= 1.10 ) return 2.0;
    return 3.0;
};



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

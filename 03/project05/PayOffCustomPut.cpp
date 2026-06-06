
#include "PayOffCustomPut.h"
#include "minmax.h"
#include<stdexcept>

PayOffCustomPut::PayOffCustomPut(double strike_)
{
    strike = strike_;
}


// definition of a function
double PayOffCustomPut::operator()(double spot) const
{
    if (spot/strike >= 1.00) return 0.0;
    else if (spot/strike >= 0.95) return 1.0;
    else if (spot/strike <= 0.90) return 2.0;
    return 3.0;
};


#include "custom_option.h"

payoffCustomCall::payoffCustomCall(double strike) : strike_(strike) {}

double payoffCustomCall::operator() (double spot) const {
    if (spot/strike_ <= 1.00) return 0.00;
    if ( spot/strike_ <= 1.05) return 1.00;
    if (spot/strike_ <= 1.10) return 2.00;
    else return 3.00;
}


payoffCustomPut::payoffCustomPut(double strike) : strike_(strike) {}

double payoffCustomPut::operator() (double spot) const {
    if (spot/strike_ >= 1.00) return 0.00;
    if ( spot/strike_ >= 1.05) return 1.00;
    if (spot/strike_ >= 1.10) return 2.00;
    else return 3.00;
}


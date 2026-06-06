
#include "barrier_straddle.h"


BarrierStraddle::BarrierStraddle(const MJArray &look_at_times_,
                                       double delivery_time_,
                                       const PayOffBridge &the_payoff_)
    : PathDependent(look_at_times_),
      delivery_time(delivery_time_),
      the_payoff(the_payoff_),
      number_of_times(look_at_times_.size())
{
}

// definitions of methods
unsigned long BarrierStraddle::max_number_of_cash_flows() const
{
    return 1UL; // 1UL stands for 'one unsigned long'
}

MJArray BarrierStraddle::possible_cash_flow_times() const
{
    MJArray tmp(1UL);
    tmp[0] = delivery_time;
    return tmp;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ! this method is (partially) responsible for determining payments of the option!!
// is uses the object of the PayOffCall subclass (thePayOff), which previously took
// as argument the final price of underlying. Since we are pricing arithmetic asian call,
// this time it takes mean spot price of underlying.
unsigned long BarrierStraddle::cash_flows(const MJArray &spot_values,
                                             std::vector<CashFlow> &generated_flows) const
{
    generated_flows[0].time_index = 0UL;
    double sum = spot_values.sum();
    double mean = sum / number_of_times;
    generated_flows[0].amount = the_payoff(mean);
    
    if (spot_values.max() > 125) {generated_flows[0].amount = 0.0;}
    if (spot_values.min() < 90) {generated_flows[0].amount = 0.0;}

    return 1UL;
}

// standard method for cloning (making a copy of this object)
PathDependent *BarrierStraddle::clone() const
{
    return new BarrierStraddle(*this);
}

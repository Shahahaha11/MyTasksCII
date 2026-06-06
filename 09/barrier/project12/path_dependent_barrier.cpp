#include "path_dependent_barrier.h"
#include "payoff_bridge.h"
#include <cmath>


PathDependentBarrier::PathDependentBarrier(const MJArray &look_at_times_,double delivery_time_,
                       const PayOffBridge &the_payoff_, double barrier_, int optype_)
: PathDependent(look_at_times_), delivery_time(delivery_time_), the_payoff(the_payoff_), barrier(barrier_),
 number_of_times(look_at_times_.size()), optype(optype_)
{                                     
}

PathDependentBarrier::~PathDependentBarrier(){}

unsigned long PathDependentBarrier::max_number_of_cash_flows() const
{
    return 1UL;
}

MJArray PathDependentBarrier::possible_cash_flow_times() const
{
    MJArray tmp(1UL);
    tmp[0] = delivery_time;
    return tmp;
}

unsigned long PathDependentBarrier::cash_flows(
    const MJArray &spot_values,
    std::vector<CashFlow> &generated_flows) const
{
    bool hit = false;
    for (unsigned long i = 0; i < number_of_times; i++){
        if ((optype == 1 || optype == 2) && (spot_values[i] >= barrier)){
                hit = true;
            } 
        if ((optype == 3 || optype == 4) && spot_values[i] <= barrier){
                hit = true;
            } 
    }

    double final_spot = spot_values[number_of_times - 1];
    double amount = the_payoff(final_spot);

    if ((optype == 1) && !hit) amount = 0.0; // up in
    if ((optype == 2) && hit) amount = 0.0 ; // up out
    if ((optype == 3) && !hit) amount = 0.0; // down in
    if ((optype == 4) && hit) amount = 0.0; // down out


    generated_flows[0].time_index = 0UL;
    generated_flows[0].amount = amount;
    return 1UL;
}

PathDependent *PathDependentBarrier::clone() const
{
    return new PathDependentBarrier(*this);
}


// double delivery_time; 
// PayOffBridge the_payoff;
// unsigned long number_of_times;
// double barrier;

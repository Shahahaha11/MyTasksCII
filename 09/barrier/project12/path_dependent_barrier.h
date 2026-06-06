#ifndef PATH_DEPENDENT_BARRIER_H
#define PATH_DEPENDENT_BARRIER_H
#include "path_dependent.h"
#include "payoff_bridge.h"


class PathDependentBarrier : public PathDependent {
public:
    PathDependentBarrier();
    PathDependentBarrier(const MJArray &look_at_times_,double delivery_time_,
                       const PayOffBridge &the_payoff_, double barrier_, int optype_);

    virtual unsigned long max_number_of_cash_flows() const;
    virtual MJArray possible_cash_flow_times() const;
    virtual unsigned long cash_flows(const MJArray &spot_values,
                                     std::vector<CashFlow> &generated_flows) const;
    virtual ~PathDependentBarrier();
    virtual PathDependent *clone() const;
    // in a barrier option mostly has one barrier. 

    // scenarios:
    // If we are dealing with : 
        // up and in 
        // up and out 
        // down and in 
        // down and out

private:
    int optype ;
    double delivery_time;
    PayOffBridge the_payoff;
    unsigned long number_of_times;
    double barrier;
};


#endif



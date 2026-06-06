#ifndef STATISTICS_STD
#define STATISTICS_STD
#include "statistics_mc.h"

using namespace std;

class StatisticsSTD : public StatisticsMC {
public :
    StatisticsSTD();

    virtual void dump_one_result(double result);
    virtual vector<vector<double > > get_results_so_far() const;
    virtual StatisticsMC *clone() const;
    double get_avg_payoff() const;
    double get_std_payoff() const;
    // “We are 95% confident the true option price lies within ±0.0154 of 4.46224.”
    double get_confidence_95() const; 
    
private :
    vector<double> payoffs;

};


#endif
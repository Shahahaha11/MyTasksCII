#include "statistics_std.h"
#include <vector>
#include <cmath>
using namespace std;

StatisticsSTD::StatisticsSTD(){};

void StatisticsSTD::dump_one_result(double result){
    payoffs.push_back(result);
}

std::vector<std::vector<double>> StatisticsSTD::get_results_so_far() const{
    vector<vector<double>> Results(3);

    Results[0].resize(1);
    Results[0][0] = get_avg_payoff();
    Results[1].resize(1);
    Results[1][0] = get_std_payoff();
    Results[2].resize(1);
    Results[2][0] = get_confidence_95();
    return Results;
}
// Results[i] → picks the row
// Results[i][j] → picks the element inside that row

double StatisticsSTD::get_avg_payoff() const{
    double running_sum = 0.0;
    for(unsigned long i = 0; i < payoffs.size(); i++){
        running_sum += payoffs[i];
    }
    return running_sum/ static_cast<double>(payoffs.size());
}


double StatisticsSTD::get_std_payoff() const {
    double running_sum = 0.0;
    double avg = get_avg_payoff();
    for(unsigned long i = 0; i < payoffs.size(); i++){        
        running_sum += pow((payoffs[i] - avg), 2);
    }
    return sqrt(running_sum / static_cast<double>(payoffs.size()));
}

double StatisticsSTD::get_confidence_95() const {
    double st_dev = get_std_payoff();
    return 1.96 * st_dev /sqrt(payoffs.size());
}

StatisticsMC *StatisticsSTD::clone() const
{
    return new StatisticsSTD(*this);
}

// Now you can do this . So its a deep copy.
// StatisticsMC* the_object = new StatisticsSTD();  StatisticsMC* copy_of_the_object = the_object->clone();
// delete s; delete copy;

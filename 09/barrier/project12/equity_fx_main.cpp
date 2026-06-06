#include <iostream>
#include "park_miller.h"
#include "statistics_mc.h"
#include "convergence_table.h"
#include "antithetic.h"

// #include "path_dependent_asian.h"
// #include "path_dependent_geometric_asian.h"
// #include "path_dependent_european.h"
#include "path_dependent_barrier.h"
#include "path_dependent_lookback.h"
#include "barrier_straddle.h"
#include "exotic_bs_engine.h"

using namespace std;

int main()
{
    // We first declare variables and ask the user to provide them.
    double expiry;
    double strike;
    double spot;
    double vol;
    double r;
    double d;
    unsigned long int number_of_paths;
    unsigned long int number_of_dates;
    double barrier;
    int optype;
    short unsigned decision = 2;
    while (decision > 1)
    {
        cout << "Do you want to take default parameters (0) or provide your own (1)?\n";
        cin >> decision;
    }

    if (decision == 0)
    {
        expiry = 0.5;
        strike = 100;
        spot = 95;
        vol = 0.2;
        r = 0.06;
        d = 0.0;
        number_of_paths = 1000000;
        number_of_dates = 126;
        barrier = 110;
        optype = 2;

    }
    else
    {
        cout << "\nEnter 1 for up-in,  \n";
        cout << "\nEnter 2 for up-out,  \n";
        cout << "\nEnter 3 for down-in,  \n";
        cout << "\nEnter 4 for down-out,  \n";
        cin >> optype;
        cout << "\nEnter expiry\n";
        cin >> expiry;

        cout << "\nEnter strike\n";
        cin >> strike;

        cout << "\nEnter spot\n";
        cin >> spot;

        cout << "\nEnter volatility\n";
        cin >> vol;

        cout << "\nEnter risk-free rate\n";
        cin >> r;

        cout << "\nEnter dividend rate\n";
        cin >> d;

        cout << "\nEnter number of intervals\n";
        cin >> number_of_dates;

        cout << "\nEnter number of paths\n";
        cin >> number_of_paths;

        cout << "\nEnter barrier\n";
        cin >> barrier;

    }

    // Create an object of PayOffCall type.
    PayOffCall the_payoff1(strike);
    PayOffPut the_payoff2(strike);

    MJArray times(number_of_dates);

    for (unsigned long i = 0; i < number_of_dates; i++)
    {
        times[i] = (i + 1.0) * expiry / number_of_dates; 
    }

    ParametersConstant vol_param(vol);
    ParametersConstant r_param(r);
    ParametersConstant d_param(d);

    
    PathDependentBarrier the_option(times, expiry, the_payoff1, barrier, optype);

    StatisticsMean gathererA;

    ConvergenceTable gatherer2A(gathererA);

    RandomParkMiller generator(number_of_dates);

    AntiThetic generator1(generator);


    ExoticBSEngine the_engine1(the_option, r_param, d_param, vol_param, generator1, spot);

    the_engine1.do_simulation(gatherer2A, number_of_paths);

    vector<vector<double>> results1 = gatherer2A.get_results_so_far();

    cout << "\nFor the barrier call option : \n" ;
    for(unsigned long i = 0 ; i <  results1.size() ; i++ ) {
            cout << results1[i][0] << " ";
            // results1[i][0]  // option price
            // results1[i][1]  // number of paths
            cout << "\n";
        }
    return 0;

}


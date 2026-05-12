
#include "simple_mc8.h"
#include "park_miller.h"
#include "vanilla3.h"
#include "statistics_mc.h"
#include "convergence_table.h"
#include "conf_limits.h"
#include "antithetic.h"
#include "helpers.h"
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <Rcpp.h>
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
double MCEuropeanOptionPricer
(
    double expiry = 0.5,
    double strike = 100,
    double spot = 95,
    double vol = 0.2,
    double r = 0.06,
    unsigned long number_of_paths = 1000000,
    int seed = 0
)
{
    if (seed == 0) seed = rand();

    PayOffCall the_payoff(strike);
    VanillaOption the_option(the_payoff, expiry);
    ParametersConstant VolParam(vol);
    ParametersConstant rParam(r);
    StatisticsMean gatherer1;
    RandomParkMiller generator1(1);

    generator1.set_seed(rand());
    gatherer1.reset();
    simple_monte_carlo8(the_option,
                        spot,
                        VolParam,
                        rParam,
                        number_of_paths,
                        gatherer1,
                        generator1);
    double result = gatherer1.get_results_so_far()[0][0];

    return result;
}

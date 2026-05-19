#include <cstdlib>
#include <cmath>
#include <Rcpp.h>
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
double impurity_reduction(int father_bad, int father_good,
                          int left_bad, int left_good,
                          int right_bad, int right_good){
  auto gini = [](int good, int bad){
    double total = good + bad;
    if (total == 0) return 0.0;
    double fg = good/ total;
    double fb = bad/total;
    return 1 - fg*fg - fb*fb;
  };

  // Gini function is a good choice for impurity measure since it
  // behaves well in the domain [0,1]: it has 0 value at 0 and 1 (perfect purity),
  // and a maximum at 0,5 (perfect impurity.

  double father_total = father_good + father_bad;
  double left_total = left_good + left_bad;
  double right_total = right_good + right_bad;

  double father_I = gini(father_good, father_bad);
  double left_I = gini(left_good, left_bad);
  double right_I = gini(right_good, right_bad);

  double delta_I = father_I - ((left_total/father_total)* left_I + (right_total/father_total)* right_I);

  return delta_I;
}




#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector ewma(NumericVector y, int k){
    int n = y.size();
    NumericVector out(n, NA_REAL);
    double alpha = 2.0 / (n + 1.0);

    if (n == 0) return out;

    for (int i = 0; i < n ; i++){
        out[i] = alpha * y[i] + (1- alpha) * out[i-1];
    }
    return out;
}

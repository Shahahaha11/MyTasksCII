#include "Rcpp.h"
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector SMA(NumericVector x, int k){
    int n = x.size();
    NumericVector out(n);
    for(int i = 0;  i < n ; i++){
        if(i < k-1) out[i] = NA_REAL;
        else{
            double sum = 0.0;
            for(int j = i -k+1 ; j <= i; j++) sum += x[j];
            out[i] = sum /k;
        }
    }
    return out;
}

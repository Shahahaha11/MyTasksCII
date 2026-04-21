#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector runningSD(NumericVector data, int window_size)
{
    int n = data.size();
    NumericVector results(n, NA_REAL);

    for (int i = window_size - 1; i < n; i++)
    {
        for (j = i -window_size +1 ; j<=i ; j++)
        {
            sum += data[j];
        }

        double mean = sum / window_size;

        double sq_sum = 0.0;
        for (int j = i - window_size + 1; j <= i; j++)
        {
            double diff = data[j] - mean;
            sq_sum += diff * diff;
        }

        double std_dev = sqrt(sq_sum / (window_size - 1));
        results[i] = std_dev;
    }

    return results;
}





        double sum = 0.0;
        for (int j = i - window_size + 1; j <= i; j++)
        {
            sum += data[j];
        }

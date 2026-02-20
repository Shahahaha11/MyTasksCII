#ifndef STATS_H
#define STATS_H

#include <vector>
#include <string>

int digitSum(int n);
double clamp(double value, double low, double high);

double mean(const std::vector<double>& v);
double variance(const std::vector<double>& v);
double standardDeviation(const std::vector<double>& v);
double covariance(const std::vector<double>& x, const std::vector<double>& y);

double calculateReturns(const std::vector<double>& x,
                        std::vector<double>& returns);
double sharpeRatio(const std::vector<double>& returns, double riskFreeRate);

void writeVectorToFile(const std::vector<double>& v,
                       const std::string& filename);
std::vector<double> readVectorFromFile(const std::string& filename);

#endif

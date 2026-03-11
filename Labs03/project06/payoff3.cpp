#include<memory>
#include<algorithm>
#include "payoff3.h"
using namespace std;

double PayoffCall::operator()(double spot)  const 
{
    return max(spot - strike_, 0.0) ;
}

PayoffCall::PayoffCall(double strike_){}

Payoff* PayoffCall::clone() const 
{ // a function clone() which is inside the PayoffCall return a type Payoff*
    return new PayoffCall(*this); 
}


double PayoffPut::operator()(double spot) const 
{
    return max(strike_ - spot, 0.0);
}
PayoffPut::PayoffPut(double strike_){}

Payoff* PayoffPut::clone() const 
{
    return new PayoffPut(*this); // by default if you feed into the constructor an object of it makes a deep copy of it .
}



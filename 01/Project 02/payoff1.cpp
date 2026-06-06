// payoff1.cpp
#include "payoff1.h"
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>



Payoff::Payoff(double strike, OptionType option_type, OptionStyle option_style)
: strike_(strike), option_type_(option_type), option_style_(option_style){}


Payoff::Payoff(double value, double upper, double lower, OptionStyle option_style)
: value_(value), upper_(upper), lower_(lower), option_style_(option_style){}

double Payoff::operator()(double spot) const
{
    if (option_style_ == DoubleDigital)
    return  (spot >= lower_ && spot <= upper_) ? value_ : 0.0;

    switch (option_type_)
    {
    case Call:
        switch(option_style_){
            case Vanilla : return std::max(spot - strike_, 0.0);
            case Squared : return std::pow(std::max(spot - strike_, 0.0), 2.0 );
            case Quadratic : return std::max(strike_*strike_ - spot*spot, 0.0);
            case Digital: return (spot >= strike_) ? value_ : 0.0;
            case DoubleDigital : return value_;
        }
        break;

        case Put :
        switch(option_style_){
            case Vanilla : return std::max(strike_ - spot, 0.0);
            case Squared : return std::max(std::pow(strike_ - spot, 2.0 ), 0.0);
            case Quadratic : return std::max(spot*spot -strike_*strike_, 0.0);
            case Digital: return (strike_ >= spot) ? value_ : 0.0;
            case DoubleDigital : return value_;
        }
        break;
    default:
        throw("Unknown option type found.");
    }

};



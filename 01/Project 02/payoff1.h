// payoff1.h

#ifndef PAYOFF1_H
#define PAYOFF1_H

class Payoff
{

public:
    enum OptionType // enum : set of integer labels.
    {
        Call,
        Put
    };

    enum OptionStyle 
    {
        Vanilla,
        Squared,
        Quadratic,
        Digital,
        DoubleDigital

    };

    Payoff(double strike, OptionType option_type, OptionStyle option_style);
    Payoff(double value, double upper, double lower, OptionStyle option_style); // for DoubleDigital

    double operator()(double spot) const;

private:
    double  value_{1.0};
    double strike_{0.0};
    double lower_{0.0};
    double upper_{0.0};
    OptionStyle option_style_{Vanilla};
    OptionType  option_type_{Call};
};


#endif

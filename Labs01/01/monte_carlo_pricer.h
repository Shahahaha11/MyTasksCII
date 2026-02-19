
// BASE CLASS : 
#pragma once

class monte_carlo_pricer {
public:
    virtual double pricer() const = 0;
    virtual ~monte_carlo_pricer() {}
};

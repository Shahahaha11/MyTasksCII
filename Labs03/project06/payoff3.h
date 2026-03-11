#ifndef PAYOFF3_H
#define PAYOFF3_H
// payoff goes inside vanilla eventually.
class Payoff{
public :
    Payoff(){};
    virtual double operator()(double spot) const = 0;
    virtual ~Payoff() {}

    // Can be called a deep copy.
     // If the class has no pointer members, the default copy creates a completely independent object.
    virtual Payoff* clone() const = 0;
    
    private :
    double strike_;
    
};

class PayoffCall : public Payoff{
public :
    PayoffCall(double strike_);
    virtual double operator()(double spot) const;
    
    virtual ~PayoffCall() {}
    virtual PayoffCall* clone() const; // we use this pointer to define teh pointer of Vanilla Option
private:
    double strike_;
};

class PayoffPut : public Payoff{
public :
    PayoffPut(double strike_);
    virtual double operator()(double spot) const;
    
    virtual ~PayoffPut() {}
    virtual PayoffPut *clone() const; 
private :
    double strike_;
};

#endif
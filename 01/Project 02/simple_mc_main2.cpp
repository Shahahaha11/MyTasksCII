// simple_mc_main2.cpp

#include "simple_mc.h"
#include <iostream>
// using namespace std;

// In project02, modify the pay-off class so that it can handle
// squared power options, with the payout max2[ST − K, 0] for
// the call and max2[K − ST , 0] for the put.


int main()
{
	double expiry = 0.25;
	double strike = 110; 
	double spot = 100;
	double vol = 0.3;
	double r = 0.04;
	unsigned long number_of_paths = 10000;
	double value = 50.0;
	double upper = 110;
	double lower = 90;

	Payoff vanilla_call_payoff(strike, Payoff::Put, Payoff::Vanilla);
	Payoff squared_call_payoff(strike, Payoff::Call, Payoff::Squared);
	Payoff quadratic_call_payoff(strike, Payoff::Call, Payoff::Quadratic); // quadratic.cpp
	Payoff digital_call_payoff(strike, Payoff::Call, Payoff::Digital); 
	Payoff double_digital_call_payoff(value, upper, lower, Payoff::DoubleDigital); 

	
	std::cout << "For Option" << "\n" << "expiry = 0.25" << "\n"
				"strike = 110" << "\n" << "spot = 100" << "\n"
				"vol = 0.3" << "\n" << "r = 0.04" << "\n";
	double result_vinalla = simple_monte_carlo(vanilla_call_payoff,
											expiry,
											spot,
											vol,
											r,
											number_of_paths);

	double result_squared = simple_monte_carlo(squared_call_payoff,
										   expiry,
										   spot,
										   vol,
										   r,
										   number_of_paths);


	double result_quadratic = simple_monte_carlo(quadratic_call_payoff,
										   expiry,
										   spot,
										   vol,
										   r,
										   number_of_paths);

	double result_digital = simple_monte_carlo(quadratic_call_payoff,
											expiry,
											spot,
											vol,
											r,
											number_of_paths);

	double result_double_digital = simple_monte_carlo(quadratic_call_payoff,
										   expiry,
										   spot,
										   vol,
										   r,
										   number_of_paths);


	std::cout << "\nthe prices are:\n"
		 << result_vinalla << " for the vanilla call\n"
		 << result_squared << " for the squared option \n"
		 << result_quadratic << " for the quadratic option \n"
		 << result_digital << " for the digital option \n"
		 << result_double_digital << " for the double digital option \n";
	

	double tmp;
	std::cin >> tmp;

	return 0;
}

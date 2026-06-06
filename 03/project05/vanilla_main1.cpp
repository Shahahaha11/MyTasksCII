#include <iostream>
#include <fstream>
#include "simple_mc3.h"
#include "double_digital.h"
#include "PayOffCustomCall.h"
#include "PayOffCustomPut.h"
#include "vanilla1.h"

// THE CHAIN OF DEFINITIONS:

// Declare thePayOff of base class type equal to nullptr.
//  PayOff* thePayOff = nullptr; 

// Define thePayOff and feed strike to operator
// 	thePayOff = new PayOffCustomPut(strike); 

// Then theOption defined of type VanillaOption . With input being the actual object that thePayOff points to and expiry.
// 	VanillaOption theOption(*thePayOff, expiry); 

//theOption does inside MonteCarlo that does the simulation using random.h
// 	SimpleMonteCarlo3(theOption, ** everything else)
	
using namespace std;

int main()
{
	double expiry = 0.5;
	double low = 100;
	double up = 120;
	double spot = 95;
	double strike =  100;
	double vol = 0.2;
	double r = 0.06;
	unsigned long number_of_paths = 10000;
	int choice_of_custom = 1;

	PayOff* thePayOff = nullptr;
	// Pointer of type PayOff named thePayOff
	
	
	if (choice_of_custom == 1)
	thePayOff = new PayOffCustomCall(strike);
	else if (choice_of_custom == -1)
	thePayOff = new PayOffCustomPut(strike);
	
	
	
	// Our operator takes the spot. we always need it. 
	
	// The below two lines are all of the juice from one of the derived classes from PayOff Base.
	VanillaOption theOption(*thePayOff, expiry); // VanillaOption final class needs "the payoff object" so we dereference thePayOff. 
	
	
	
	double result = SimpleMonteCarlo3(theOption,
		spot,
		vol,
		r,
		number_of_paths);
		
		// The result printed is from one iteration.
		cout << "\nthe price is " << result << "\n";
		
		// The output.csv contains multiple such results.
		
		unsigned int nReps = 1000;
		double prices[nReps];
	for (unsigned int i = 0; i < nReps; ++i)
	{
		prices[i] = SimpleMonteCarlo3(theOption, 
			spot,
			vol,
			r,
			number_of_paths);
		}
		


		// "outFile" The  output stream is defined below. 
		std::ofstream outFile("output.csv");
		
		// Step 3: Check if file opened successfully
		if (!outFile)
		{
			std::cerr << "Error: Could not open the file for writing.\n";
			return 1; // Exit with error code
		}
		
		// Step 4: Write each element of the vector to a new line in the file
		for (double value : prices)
		{
			outFile << value << "\n";
		}
		
		// Step 5: Close the file
		outFile.close();
		
		delete thePayOff;
		std::cout << "Data successfully written to output.csv\n";
		
		return 0;
}

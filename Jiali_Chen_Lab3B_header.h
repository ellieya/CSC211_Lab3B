/*
Jiali Chen
Lab 3B - Keep on Pumping!
In Lab 3B, we revise Lab 3A to include a static data member that will keep track of the amount of gas inside the main tank, shared by two objects.
We also use static member functions in order to use and manipulate the newly added static data members.
*/


#include <iostream>
#include <iomanip> //Used for formatting $
#include <fstream> //Used for creating log
#include <windows.h> //Used for Sleep()
#include <string>

using namespace std;

class pump {
	double cpg; //cpg = Cost Per Gallon
	double session_amount;
	double session_cost;
	double total_sold_$;
	double total_sold_amt;
	static double tank; //Keeps track of amount of gas remaining in the main tank (for all objects)
	void display_amount();
		//POST: Print the amount of gas pumped
	void display_cost();
		//POST: Print the session cost
	void reset();
		//POST: Make session_amount and session_cost = 0
	void dispense_end_message();
		//POST: Print message containing session amount of gas pumped, session cost, and gratitude
	void subtract_check_refill(double);
		//POST: Subtracts requested gas amount, checks if main tank needs to be refilled, then refills as needed.
public:
	pump();
		//Initialize cpg with 3.95
	pump(double);
		//cpg is initialized with programmer's argument
	void display_cpg();
		//POST: the current cpg is displayed without a dollar sign, and with at least 2 decimal points shown
	void set_cpg(double);
		//POST: Makes cpg equal to provided argument
	void dispensing();
		//A loop that dispenses 0.1 gal of gas until the user quits.
	void dispensing(double);
		//POST: Takes the user input (maximum amount willing to pay) and dispenses gas amount equal to the user input in price value
	double return_total_sold_$();
		//POST: returns total_sold_$
	double return_total_sold_amt();
	//POST: returns total_sold_amt
	static void fill_tank(double);
		//POST: Add argument to static data member 'tank'
	static double get_tank();
		//POST: Return value of static data member 'tank'
};

/*

OUTPUTS

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Testing 0 Fuel - Screen #1
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TANK: 0

SELECT SERVICE:
(WARNING: Invalid inputs will default to free pumping full service)
Free Pumping - Dispense in 0.1 increments
Price Limit - Set the maximum price you are willing to pay

1) Full service ($3.95 per gallon) - Free Pumping
2) Full service ($3.95 per gallon) - Price Limit
3) Self service ($2.00 per gallon) - Free Pumping
4) Self service ($2.00 per gallon) - Price Limit
5) EXIT

Input: 1

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Testing 0 Fuel - Screen #2
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Tank needs to be refilled. Please wait...

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Testing 0 Fuel - Screen #3
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

DISPENSING 0.1 GAL!
Cost per gallon: $3.95
Tank: 9.90

Session Totals:
Amount of gas pumped: 0.10
Session cost: $0.40

To continue pumping gas - Press or hold ENTER.
To quit - Press any key, then press ENTER.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Testing 0 Fuel - Screen #4
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Session Totals (Final):
Amount of gas pumped: 0.10
Session cost: $0.40

THANK YOU!
Returning to service selection...

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Testing 0 Fuel - Screen #5
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TANK: 9.90

SELECT SERVICE:
(WARNING: Invalid inputs will default to free pumping full service)
Free Pumping - Dispense in 0.1 increments
Price Limit - Set the maximum price you are willing to pay

1) Full service ($3.95 per gallon) - Free Pumping
2) Full service ($3.95 per gallon) - Price Limit
3) Self service ($2.00 per gallon) - Free Pumping
4) Self service ($2.00 per gallon) - Price Limit
5) EXIT

Input: 5

Creating log...
Please enter filename: test
File has been created.
Press any key to continue . . .

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Testing 0 Fuel - Log File
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

==============================================
Log: test
==============================================

Total amount gallons sold (full-service): 0.10
Total $ gallons sold (full-service): 0.40
Total amount of gallons sold (self-service): 0.00
Total $ of gallons sold (self-service): 0.00
Gas remaining in main tank: 9.90


*/
#include "Jiali_Chen_Lab3B_header.h"

using namespace std;

//Function prototypes
void create_log(pump, pump);
	//POST: Creates log file containing gas sold & remaining gas in main tank using user-provided file name

int main() {

	int userInput;
	double priceInput;

	pump full_service;
	pump self_service(2.00);

	do {
		cout << "TANK: " << pump::get_tank() << "\n\n"
			<< "SELECT SERVICE:\n"
			<< "(WARNING: Invalid inputs will default to free pumping full service)\n"
			<< "Free Pumping - Dispense in 0.1 increments\n"
			<< "Price Limit - Set the maximum price you are willing to pay\n\n"
			<< "1) Full service ($3.95 per gallon) - Free Pumping \n"
			<< "2) Full service ($3.95 per gallon) - Price Limit \n"
			<< "3) Self service ($2.00 per gallon) - Free Pumping \n"
			<< "4) Self service ($2.00 per gallon) - Price Limit \n"
			<< "5) EXIT\n\n"
			<< "Input: ";
		cin >> userInput;
		cin.ignore(); //Used to ignore the \n input that proceeds
		cout << '\n';

		//Make full-service - free pumping if invalid input provided
		if (userInput < 1 || userInput > 5) {
			userInput = 1;
		}

		//Access object's dispensing method based on userInput
		switch (userInput) {
		case 1:
			full_service.dispensing();
			break;
		case 2:
			cout << "Enter maximum amount you are willing to pay: $";
			cin >> priceInput;
			full_service.dispensing(priceInput);
			break;
		case 3:
			self_service.dispensing();
			break;
		case 4:
			cout << "Enter maximum amount you are willing to pay: $";
			cin >> priceInput;
			self_service.dispensing(priceInput);
			break;
		}
	} while (userInput != 5); //End program when userInput == 5
		
	create_log(full_service, self_service);

	return 0;
}
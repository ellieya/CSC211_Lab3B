#include "Jiali_Chen_Lab3B_header.h"

double pump::tank = 0;

pump::pump() :cpg(3.95), session_amount(0), session_cost(0), total_sold_$(0), total_sold_amt(0) {
	// Intentionally left empty
}

pump::pump(double programInput) : cpg(programInput), session_amount(0), session_cost(0), total_sold_$(0), total_sold_amt(0) {
	// Intentionally left empty
}

void pump::dispensing() {
	do {
		system("cls");

		//Run subtract_check_refill function to receive and affect main tank data
		pump::subtract_check_refill(0.1);

		//Information for the user: Amount dispensed, cost per gallon, and tank status
		cout << "DISPENSING 0.1 GAL!\nCost per gallon: $";
		display_cpg();
		cout << "Tank: " << pump::get_tank() << endl;
		cout << '\n';


		//Increase session gas pumped & session cost
		session_amount += 0.1;
		session_cost += cpg*0.1;

		//Display current session gas pumped & session cost
		cout << "Session Totals:" << endl;
		display_amount();
		display_cost();

		//Information for the user on how to continue/quit
		cout << "\nTo continue pumping gas - Press or hold ENTER."
			<< "\nTo quit - Press any key, then press ENTER.";
		cout << '\n';

	} while (cin.get() == '\n'); //Continue loop while the user presses or holds enter

	//Add the session's amount to total sold
	total_sold_amt += session_amount;
	total_sold_$ += session_cost;

	//Display session information
	system("cls");
	dispense_end_message();
}

void pump::dispensing(double userInput) {
	system("cls");

	session_amount = userInput / cpg;
	session_cost = session_amount * cpg; //Used instead of userInput so that the amount is printed with dollar formatting

	//Run subtract_check_refill function to receive and affect main tank data
	pump::subtract_check_refill(session_amount);

	total_sold_amt += session_amount;
	total_sold_$ += session_cost;

	dispense_end_message();
}

void pump::display_amount() {
	cout << "Amount of gas pumped: " << session_amount << endl;
}

void pump::display_cost() {
	cout << "Session cost: $" << fixed << setprecision(2) << showpoint << session_cost << endl;
}

void pump::display_cpg() {
	cout << fixed << showpoint << setprecision(2) << cpg << endl;
}

void pump::set_cpg(double progInput) {
	cpg = progInput;
}

void pump::reset() {
	session_amount = 0, session_cost = 0;
}

double pump::return_total_sold_$() {
	return total_sold_$;
}

double pump::return_total_sold_amt() {
	return total_sold_amt;
}

void pump::dispense_end_message() {

	//Display final cost and message for the current session
	cout << "Session Totals (Final):" << endl;
	display_amount();
	display_cost();
	cout << "\nTHANK YOU!\nReturning to service selection...";

	//Set session gas pumped & session cost to 0 for the next customer
	reset();

	//Flush cout to allow the use of Sleep
	cout.flush();

	//Wait 7 seconds before clearing screen
	Sleep(7000);
	system("cls");
}

void pump::fill_tank(double progInput) {
	tank += progInput;
}

double pump::get_tank() {
	return tank;
}

void pump::subtract_check_refill(double reqAmt) {
	//Subtract requested gas amount
	tank -= reqAmt;

	//Check & refill if needed
	while (tank <= 0) { //While loop is used instead of if statement in case anyone requests amount that is over greater than double tank maximum
		cout << "Tank needs to be refilled. Please wait..." << endl;
		Sleep(5000);
		fill_tank(10);
		system("cls");
	}
}

void create_log(pump fs, pump ss) {
	string filename;

	cout << "Creating log...\nPlease enter filename: ";
	cin >> filename;

	ofstream fout(filename + ".txt");
	fout << setprecision(2) << fixed << showpoint 
		<< "==============================================\n"
		<< "Log: " << filename << '\n'
		<< "==============================================\n\n"
		<< "Total amount gallons sold (full-service): " << fs.return_total_sold_amt() << '\n'
		<< "Total $ gallons sold (full-service): " << fs.return_total_sold_$() << '\n'
		<< "Total amount of gallons sold (self-service): " << ss.return_total_sold_amt() << '\n'
		<< "Total $ of gallons sold (self-service): " << ss.return_total_sold_$() << '\n'
		<< "Gas remaining in main tank: " << pump::get_tank() << endl;

	cout << "File has been created." << endl;

	fout.close();
}
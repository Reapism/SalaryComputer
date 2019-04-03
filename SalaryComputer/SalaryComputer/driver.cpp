#include <iostream>
#include <string>
#include "salary.h"

void menu_salary_hourly();
void menu_salary();
void menu_hourly();

int main() {
	menu_salary_hourly();
}

void menu_salary() {
	const int MAX_RANGE = 5;

	double hourly = 0;
	int range = 0;

	std::cout.clear();

	do {
		std::cout.clear();
		std::cout << "\n\n  Please enter an hourly wage (> 0): ";
		std::cin >> hourly;	
	} while (hourly <= 0);

	do {
		std::cout.clear();
		std::cout << "\n\n  Please enter upper and lower iterations (> " << MAX_RANGE << "): ";
		std::cin >> range;
	} while (range <= MAX_RANGE);

	reapism::salary salary_instance;

	int min = hourly - range,
		max = hourly + range;

	double* the_hourly_ptr = &hourly;
	double the_salary = 0;
	double* the_salary_ptr = &the_salary;

	if (salary_instance.compute_salary(the_hourly_ptr, the_salary_ptr)) {

		for (double i = min; i < max; i++) {
			// setting the result equal to the bool itWorked.
			double* i_ptr = &i;
			bool itWorked = salary_instance.compute_salary(i_ptr, the_salary_ptr);

			if (itWorked) {
				std::cout << "Hourly: " << *i_ptr << " = $" << *the_salary_ptr << ".\n";
			} else {
				std::cout << "Failed for Hourly: " << *i_ptr << " = $" << *the_salary_ptr << ".\n";
			}
		}

		std::cout << "\n\nFinished executing. Press enter to exit.";
		std::getchar();
	}
}

void menu_hourly() {
	const int MAX_RANGE = 5;

	double salary = 0;
	int range = 0;

	std::cout.clear();

	do {
		std::cout.clear();
		std::cout << "\n\n  Please enter an hourly wage (> 0): ";
		std::cin >> salary;
	} while (salary < 1500);

	do {
		std::cout.clear();
		std::cout << "\n\n  Please enter upper and lower iterations (> " << MAX_RANGE << "): ";
		std::cin >> range;
	} while (range <= MAX_RANGE);

	reapism::salary salary_instance;

	int min = salary - range,
		max = salary + range;

	double* the_salary_ptr = &salary;
	double the_hourly = 0;
	double* the_hourly_ptr = &the_hourly;

	if (salary_instance.compute_hourly(the_salary_ptr, the_hourly_ptr)) {

		for (double i = min; i < max; i++) {
			// setting the result equal to the bool itWorked.
			*the_hourly_ptr = i;
			bool itWorked = salary_instance.compute_salary(the_hourly_ptr, the_salary_ptr);
			
			if (itWorked) {
				std::cout << "Hourly: " << *the_hourly_ptr << " = $" << *the_salary_ptr << ".\n";
			}
			else {
				std::cout << "Failed for Hourly: " << *the_hourly_ptr << " = $" << *the_salary_ptr << ".\n";
			}
		}

		std::cout << "\n\nFinished executing. Press enter to exit.";
		std::getchar();
	}
}

void menu_salary_hourly() {
	int choice = 1;

	do {
		std::cout << "Welcome to the SalaryComputer:\n";
		std::cout << "1. Compute a salary:\n";
		std::cout << "2. Compute an hourly wage:\n";
		std::cout << "============================\n";
		std::cout << "Please enter a choice: ";

		std::cin >> choice;

		switch (choice) {
		case 1: { // salary
			std::cout.clear();
			std::cout << "\n\nYou have selected salary. Please press enter to continue.";
			std::getchar();
			menu_salary();
			break;
		}

		case 2: { // hourly
			std::cout.clear();
			std::cout << "\n\nYou have selected hourly. Please press enter to continue.";
			std::getchar();
			menu_hourly();
			break;
		}

		default: {
			break;
		}

		}

	} while (choice < 0 && choice > 2);

	std::getchar();

}


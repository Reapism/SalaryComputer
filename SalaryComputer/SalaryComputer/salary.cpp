#include <string>
#include <iostream>
#include "salary.h"

reapism::salary::salary() :
	the_hourly(0),
	the_salary(0) { }

reapism::salary::salary(double the_hourly, double the_salary) {
	this->the_hourly = the_hourly;
	this->the_salary = the_salary;
}

reapism::salary::salary(const reapism::salary &copyMe) {
	this->the_hourly = copyMe.the_hourly;
	this->the_salary = copyMe.the_salary;
}

double reapism::salary::get_hourly() {
	return the_hourly;
}

double reapism::salary::get_salary() {
	return reapism::salary::the_salary;
}

void reapism::salary::set_hourly(const double* &changeMe) {
	if (*changeMe > 0) { the_hourly = *changeMe; }
}

void reapism::salary::set_salary(const double* &changeMe) {
	if (*changeMe >= 1500) { this->the_salary = *changeMe; }
}

void reapism::salary::set_hourly(const double changeMe) {
	if (changeMe > 0) { this->the_hourly = changeMe; }
}

void reapism::salary::set_salary(const double changeMe) {
	this->the_salary = changeMe;
}

bool reapism::salary::compute_hourly(double* &input, double* &output) {
	int hours_per_week = 40;
	int weeks_in_a_month = 4;
	int weeks_in_a_year = 12;

	try {
		*output = (*input) / (weeks_in_a_year / weeks_in_a_month / hours_per_week);
	}
	catch (_exception) {
		*output = 0;
		return false;
	}

	return true;
}

bool reapism::salary::compute_salary(double* &input, double* &output) {
	int hours_per_week = 40;
	int weeks_in_a_month = 4;
	int weeks_in_a_year = 12;
	
	try {
		*output = (*input) * (hours_per_week * weeks_in_a_month * weeks_in_a_year);
	}
	catch (_exception){
		*output = 0;
		return false;
	}

	return true;
}
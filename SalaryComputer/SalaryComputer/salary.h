#ifndef SALARY_H
#define SALARY_H

namespace reapism {
	class salary;
}

class reapism::salary {

private:
	double the_hourly;
	double the_salary;


public:
	// default constructor
	reapism::salary();
	// parameterized constructor
	reapism::salary(double, double);
	// copy constructor
	reapism::salary(const reapism::salary&);
	// Gets the hourly wage in this instance.
	double get_hourly();
	// Gets the salary in this instance.
	double get_salary();

	// Takes in a const double* by reference,
	// and sets the hourly wage accordingly.
	void set_hourly(const double* &);

	// Takes in a const double* by reference,
	// and sets the salary accordingly.
	void set_salary(const double* &);

	// Takes in a const double,
	// and sets the hourly accordingly.
	void set_hourly(const double);

	// Takes in a const double,
	// and sets the salary accordingly.
	void set_salary(const double);

	// Computes the salary for a given hourly wage, and
	// returns it by reference.
	bool compute_salary(double* &, double* &);

	// Computes the hourly wage for a given salary , and
	// returns it by reference.
	bool compute_hourly(double* &, double* &);
};

#endif // !SALARY_H

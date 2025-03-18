#ifndef Employee_hpp
#define Employee_hpp

#include <string>
#include "HealthPlan.hpp"

using namespace std;

class Employee
{
public:
	Employee();
	Employee(string fn, string ln, float sal);
	virtual ~Employee() { cout << "dtor\n"; }
	void SetName(string fn, string ln) { first_name = fn; last_name = ln; }
	string GetName() { return last_name + ' ' + first_name; }
	void SetSalary(float newSal) { salary = newSal; }
	float getSalary() { return salary; }
	virtual float CalculatePay() = 0; // Makes this effectively abstract
	static int GetEmployeeCount() { return employee_count; }
private:
	string first_name;
	string last_name;
	float salary;
	static int employee_count;
	HealthPlan health_plan;
};

#endif // !Employee_hpp

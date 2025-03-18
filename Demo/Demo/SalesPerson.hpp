#ifndef SalesPerson_hpp
#define SalesPerson_hpp

#include <iostream>
#include "Employee.hpp"

class SalesPerson : public Employee
{
public:
	SalesPerson(string fn, string ln, float sal, HealthPlan* health_plan = NULL);
	void SetCommission(float nc) { commission = nc; }
	void SetSales(float ns) { num_sales = ns; }
private:
	float commission;
	int num_sales;
};

#endif
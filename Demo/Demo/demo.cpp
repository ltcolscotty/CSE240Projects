#include <iostream>
#include <string>
#include <vector>
#include "Employee.hpp"
#include "HealthPlan.hpp"
#include "SalesPerson.hpp"

using namespace std;

int Employee::employee_count = 0;

int main()
{
	HealthPlan* anthem = new HealthPlan("Anthem", 1500.0, 200.0);
	SalesPerson* e1 = new SalesPerson("Jack", "Black", 35000.0);
	SalesPerson* e2 = new SalesPerson("Tom", "Jones", 25000.0);
	SalesPerson* e3 = new SalesPerson("Jan", "Smith", 28000.0, anthem);

	e3->SetCommission(0.5);
	e3->SetNumSales(1000);

	vector<Employee*> evec;
	evec.push_back(e1);
	evec.push_back(e2);
	evec.push_back(e3);

	for (int i = 0; i < evec.size(); i++)
	{
		if (evec[i]->GetName() == "Jones,Tom")
		{
			delete evec[i]; // Deletes address, does not remove it from the array
			evec.erase(evec.begin() + i); // Remove element from the vector to prevent dangling reference. Also prevents segfault
		}
	}
	for (int i = 0; i < evec.size(); i++)
		cout << evec[i]->GetName() << ' ' << evec[i]->CalculatePay() << endl;
}
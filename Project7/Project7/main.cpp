#include <iostream>
#include <vector>
#include <string>

#include "pet.hpp"
#include "cat.hpp"
#include "dog.hpp"

using namespace std;

int main() 
{
	Dog* d1 = new Dog("Bob", 65);
	Dog* d2 = new Dog("Stan", 37);
	Cat* c1 = new Cat("Tom", 12);

	vector<Pet*> pvec;

	pvec.push_back(d1);
	pvec.push_back(d2);
	pvec.push_back(c1);

	float total_fee = 0.0;

	for (int i = 0; i < pvec.size(); i++)
	{
		cout << pvec[i]->GetName() << ' ' << pvec[i]->CalculateFee() << endl;
		total_fee = total_fee + pvec[i]->CalculateFee();
	}
	cout << "total licensing fee = " << total_fee << endl;
};
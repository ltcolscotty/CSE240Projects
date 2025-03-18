#ifndef HealthPlan_hpp

#include <string>

using namespace std;

class HealthPlan
{
public:
	HealthPlan(string name, float premium, float copay);
	string getName() { return name; }
	float getPremiun() { return premium; }
	float getCopay() { return copay; }
private:
	string name;
	float premium;
	float copay;
};

#endif
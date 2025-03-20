#ifndef cat_hpp
#define cat_hpp

#include <string>
#include "pet.hpp"

class Cat : public Pet
{
public:
    Cat() : Pet("", 0) {}
    Cat(std::string name, int weight) : Pet(name, weight) {}
    float CalculateFee() { return LicensingRate * weight; }
private:
	static float LicensingRate;
};

#endif // !cat_hpp

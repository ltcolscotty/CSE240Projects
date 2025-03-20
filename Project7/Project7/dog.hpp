#ifndef dog_hpp
#define dog_hpp

#include <string>
#include "pet.hpp"

class Dog : public Pet {
public:
	Dog() : Pet("", 0) {}
	Dog(std::string n, int w) : Pet(n, w) {}
	float CalculateFee() { return LicensingRate * weight; }
private:
	static float LicensingRate;
};

#endif // !dog_hpp
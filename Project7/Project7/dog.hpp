#ifndef dog_hpp
#define dog_hpp

#include <string>
#include "pet.hpp"

class Dog : public Pet {
public:
	Dog() : Pet("", 0) {}
	Dog(std::string n, int w) : Pet(n, w) {}
protected:
	float GetLicensingRate() const override { return 2.0f; } // Using this instead of a variable because VS2022 seems to want me to jump through some hoops to use a static constant
};

#endif // !dog_hpp
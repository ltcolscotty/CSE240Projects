#ifndef cat_hpp
#define cat_hpp

#include <string>
#include "pet.hpp"

class Cat : public Pet
{
public:
    Cat() : Pet("", 0) {}
    Cat(std::string name, int weight) : Pet(name, weight) {}
protected:
    float GetLicensingRate() const override { return 1.5f; } // Using this instead of a variable because VS2022 seems to want me to jump through some hoops to use a static var and we aren't submitting a cat.cpp file
};

#endif // !cat_hpp

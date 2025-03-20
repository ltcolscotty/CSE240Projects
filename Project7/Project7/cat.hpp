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
    float GetLicensingRate() const override { return 1.5f; }
};

#endif // !cat_hpp

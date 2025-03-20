#ifndef pet_hpp
#define pet_hpp

#include <string>

class Pet {
public:
	Pet() : Pet("", 0) {}
	Pet(std::string n, int w) : name(n), weight(w) {}
	virtual ~Pet() { std::cout << "Destructor\n"; }
	std::string GetName() { return name; }
	virtual float CalculateFee() { return GetLicensingRate() * weight; }
protected:
	virtual float GetLicensingRate() const = 0;
	std::string name;
	int weight;
};

#endif // !pet_hpp

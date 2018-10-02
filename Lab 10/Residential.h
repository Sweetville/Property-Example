#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include "Property.h"

using namespace std;
//---------------------------------------------------------------------------------------------------
//create the residentail class inheriting from the property class
class Residential : public Property{
protected:
	const double residential_occupied_rate = 0.006;
	const double residential_notoccupied_rate = 0.009;
	bool occupied;

public:
	string toString();
	Residential::Residential(string, int, string, bool, double, bool);
	double calculate_taxes();
};
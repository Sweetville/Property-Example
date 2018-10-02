#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include "Property.h"

using namespace std;
//---------------------------------------------------------------------------------------------------
//create the commercial class, inheriting from the property class
class Commercial : public Property{
protected:
	bool discounted;
	double discount_rate;
	const double commercial_rental_rate = 0.012;
	const double commercial_norental_rate = 0.01;
public:
	string toString();
	Commercial(string, int, string, bool, double, bool, double);
	double calculate_taxes();
};
#include "Property.h"
#include "Commercial.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
//---------------------------------------------------------------------------------------------------
//Commercial Constructor
Commercial::Commercial(string prop_type, int IDnum, string address, bool rental, double value, bool discounted, double discount_rate)
: Property(prop_type, IDnum, address, rental, value){
	//this->IDnum = IDnum;
	//this->address = address;
	//this->rental = rental;
	//this->value = value;
	this->discounted = discounted;
	this->discount_rate = discount_rate;
}
//---------------------------------------------------------------------------------------------------
//spit out the IDnum, address, whether its rental or not, etc
string Commercial::toString(){
	stringstream ss;
	ss << "Property id: " << IDnum << " Address: " << address;
	//check to see if ti's a rental 
	//if it's rental, say so
	if (rental){
		ss << "  Rental ";
	}
	else{
		ss << "  NOT rental ";
	}
	ss << "Estimated value: " << value;
	//if it's discounted, say so
	if (discounted){
		ss << "  Discounted " << " Discount: " << discount_rate;
	}
	else{
		ss << "  NOT Discounted";

	}
	return ss.str();

}
//---------------------------------------------------------------------------------------------------
//calculate the taxes for commercial property
double Commercial::calculate_taxes(){
	double taxes_due;
	int whole = 1;
	if (rental){
		//rental, then check for discounted prices or not
		if (discounted){
			taxes_due = (whole - discount_rate) * commercial_rental_rate * value;
		}
		else{
			taxes_due = commercial_rental_rate * value;
		}
			//taxes_due = ARE THERE MORE CALCULATIONS???????????????????????
	}
	else{
		//If not rental, check for discounted prices or not
		if (discounted){
			taxes_due = (whole - discount_rate) * commercial_norental_rate * value;
		}
		else{
			taxes_due = commercial_norental_rate * value;
		}
	}
	
//	stringstream ss;
	//ss << taxes_due;
	return taxes_due;
}
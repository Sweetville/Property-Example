#include "Property.h"
#include "Residential.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
//---------------------------------------------------------------------------------------------------
//Constructor for Residential property
Residential::Residential(string prop_type, int IDnum, string address, bool rental, double value, bool occupied) 
: Property(prop_type, IDnum, address, rental, value){
	//this->IDnum = IDnum;
	//this->address = address;
	//this->rental = rental;
	//this->value = value;
	this->occupied = occupied;
}

//---------------------------------------------------------------------------------------------------
//Display the Residential property info
string Residential::toString(){
	stringstream ss;
	ss << "Property id: " << IDnum << " Address: " << address;
	//check to see if ti's a rental and display the result
	if (rental){
		ss << "  Rental  ";
	}
	else{
		ss << "  NOT rental  ";
	}
	ss << "Estimated value:  " << value;
	if (occupied){
		ss << "  Occupied";
	}
	else{
		ss << "  NOT Occupied";

	}
	return ss.str();

}
//---------------------------------------------------------------------------------------------------
double Residential::calculate_taxes(){
	double taxes_due;
		//is it rental?
		if (occupied){
			//if occupied, figure out the according rate
			taxes_due = value * residential_occupied_rate;
		}
		else{
			//if not occupied, figure out the according rate
			taxes_due = value * residential_notoccupied_rate;
		}
	
	//stringstream ss;
	//ss << taxes_due;
	return taxes_due;
}
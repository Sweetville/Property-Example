#include "Property.h"
#include "Commercial.h"
#include "Residential.h"
#include <string>

using namespace std;

//---------------------------------------------------------------------------------------------------
//get the Address for the property
string Property::get_address(){
	return address;
}
//---------------------------------------------------------------------------------------------------
int Property::id = 0;
//---------------------------------------------------------------------------------------------------
//Constructor for Property
Property::Property(string prop_type, int IDnum, string address, bool rental, double value){
	this->IDnum = IDnum;
	this->address = address;
	this->rental = rental;
	this->value = value;
	this->IDnum = id++;
	//this->prop_type = prop_type;
}
//---------------------------------------------------------------------------------------------------
/*string Property::calculate_taxes(){
	double taxes_due;
	//is it commercial?
	if (prop_type == "Commercial"){
		//is it rental?
		if (rental){
			//yes
			//DO CALCULATIONS
			taxes_due = value * commercial_rental_rate;
			//taxes_due = ARE THERE MORE CALCULATIONS???????????????????????
		}
		else{
			//It's not rental
			//DO CALCULATIONS
			taxes_due = value * commercial_norental_rate;
			//taxes_due = ARE THERE MORE CALCULATIONS????????????????????
		}
	}
	//then it's Residential
	else{
		//is it rental?
		if (rental){
			//yes
			//DO CALCULATIONS
			taxes_due = value * residential_occupied_rate;
		}
		else{
			//It's not rental
			//DO CALCULATIONS
			taxes_due = value * residential_notoccupied_rate;
		}
	}
	stringstream ss;
	ss >> taxes_due;
	return ss.str();
}*/
//---------------------------------------------------------------------------------------------------
//display the taxes with address, IDnum, value, and the calculated taxes
string Property::display_taxes(){
	//variables

	//start printing it out
	stringstream rep;
	rep << "\n** Taxes due for the property at :\t" << address;
	rep << "\n\tProperty id : \t\t\t\t\t\t" << IDnum;
	rep << "\n\tThis property has an estimated value of :\t\t" << value;
	rep << "\n\tTaxes due on this property are :\t\t\t" << calculate_taxes();
	return rep.str();
}
//---------------------------------------------------------------------------------------------------
//string Property::test(){
	//return "hi";
//}
/*void display_prop(vector<Property*> properties){

	for (int i = 0; i < properties.size(); i++){
		//if (properties[i]-> == )
		cout << properties[i]->toString();
		cout << "dog";
	}
}*/

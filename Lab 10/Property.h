#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
//---------------------------------------------------------------------------------------------------
//Create the property class
class Property{
protected:
	string address;
	bool rental;
	double value;
	int IDnum;
	static int id;
	//string prop_type;
public:
	Property(string, int, string, bool, double);
	virtual string toString() = 0;
	virtual double calculate_taxes() = 0;
	string display_taxes();
	double get_discount_rate();
	string get_address();
	//void display_prop(vector<Property*>);
};
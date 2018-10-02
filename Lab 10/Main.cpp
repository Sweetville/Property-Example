#include "Residential.h"
#include "Commercial.h"
#include "Property.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#define VECTOR_START 0
using namespace std;

//---------------------------------------------------------------------------------------------------
//Load from a file and put them into coordinated variables
void load_file(vector<Property*> &properties, bool &noerror){
	//specify variables
	string prop_type;
	int IDnum = 0;
	int value;
	string address;
	bool rental;
	bool occupied;
	bool discounted;
	double discount_rate;
	cout << "Where would you like to load the file from?: ";
	//get the file location and load it
	string file;
	cin >> file;
	//give the man some space
	ifstream fin;
	fin.open(file);

	if (!fin){
		//if it's a bad input
		noerror = false;
		return;
	}
	while (true){
 		fin >> prop_type;
		//what kind of property is it?

		if (prop_type == "Residential"){
			//take in the values for a Residential property
			stringstream ss;
			string tmp;
			getline(fin, tmp, '\n');
			ss << tmp;
			ss >> rental >> value >> occupied;
			getline(ss, address);
			//put them into Residential class pointer - push to property vector
			//check for bad values

			if (!ss){
				//if it's a bad value
				cout << "Ignoring bad RESIDENTIAL in input file: " << prop_type << " " << ss.str() << endl;
				ss.clear();
				ss.ignore(100000, '\n');
				ss.sync();
				//cout << ss.str();
			}
			else{
				//if no bad values, create the property
				Residential *p = new Residential(prop_type, IDnum, address, rental, value, occupied);
				properties.push_back(p);
			}
		}

		//it's Commercial format
		else if(prop_type == "Commercial"){
			//Take in commercial property values
			stringstream ss;
			string tmp;
			getline(fin, tmp, '\n');
			ss << tmp;
			ss >> rental >> value >> discounted >> discount_rate;
			getline(ss, address);

			//check for bad values
			if (!ss){
				//bad input
				cout << "Ignoring bad COMMERCIAL in input file: " << prop_type << " " << ss.str() << endl;
				ss.clear();
				ss.ignore(100000, '\n');
				ss.sync();
			}
			else{
				//Put them into commercial Class pointer - push to property vector
				Commercial *p = new Commercial(prop_type, IDnum, address, rental, value, discounted, discount_rate);
				properties.push_back(p);
			}
		}
		else{
			//otherwise, we don't recognize it and spit it back out
			string tmp_line;
			getline(fin, tmp_line);
			string failaddress = prop_type + " " + tmp_line;
			cout << "Ignoring unknown types of properties appearing in the input file: " << failaddress << endl;
			
			if (fin.fail()){
				fin.clear();
				fin.ignore(100000, '\n');
				fin.sync();
			}

		}
		//Make the ID value go up
	//	IDnum++;
		//Stop at the end of the file
		if (fin.eof()){
			//close the stream
			fin.close();
			return;
		}
	}

}
//---------------------------------------------------------------------------------------------------
//display the properties using the toString function
void display_prop(vector<Property*> properties){

		for (int i = VECTOR_START; i < properties.size(); i++){
		//if (properties[i]-> == )
		cout << properties[i]->toString();
		cout << endl;
	}
}
//---------------------------------------------------------------------------------------------------
//present the tax forms depending on tax or address
void shuffle(vector<Property*> &properties){
	vector<Property*> shuffled_properties;
	//ask for input to sort or not
	cout << "Would you like to sort the property before displaying? (0 for no, 1 for yes): ";
	int answer;
	const int option_yes = 1;
	const int option_no = 0;

	do{ 
		cin >> answer;

		//check for invalid answers
		if (!cin || answer > option_yes || answer < option_no){
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "Please Try again with a valid answer: ";
		}
		} while (!cin || answer > option_yes || answer < option_no);

	if (answer == option_yes){
		//if they want to sort
		//ask how to sort - payment or address
		cout << "\nWould you like to sort by tax payment or by address? (0 for payment, 1 for address): ";
		int sort_choice;
		do{
			cin >> sort_choice;
			//check for invalid input
			if (!cin || sort_choice > option_yes || sort_choice < option_no){
				cin.clear();
				cin.ignore(100000, '\n');
				cout << "Please Try again with a valid answer: ";
			}
		} while (!cin || sort_choice > option_yes || sort_choice < option_no);

		//if chose to sort by taxes, sort by taxes
		if (sort_choice == option_no){
			int smallest_index;
			int huge_number = 1000000000;
			int smallest_tax = huge_number;
			int tmp;
			while (properties.size() > VECTOR_START){
				for (tmp = VECTOR_START; tmp < properties.size(); tmp++){

					//is the current property taxes less than the outstanding smallest?
					if (properties[tmp]->calculate_taxes() < smallest_tax){
						//replace values recording the new king of the hill
						smallest_index = tmp;
						smallest_tax = properties[tmp]->calculate_taxes();
					}
			}
				//push the value into the new vector
				shuffled_properties.push_back(properties[smallest_index]);
				int last_pos = properties.size() - 1;
				//remove that property from properties
				properties[smallest_index] = properties[last_pos];
				properties.pop_back();
				smallest_tax = huge_number;
			}
		}

		else if (sort_choice == option_yes){
			//Sort by Address
			int huge_number = 1000000000;
			//int smallest_address = huge_number;
			//int tmp = VECTOR_START;
			//create a formal string to compare using the first value in the properties vector
			string str_compare = properties[VECTOR_START]->get_address();
			//while the properties vector has something in it
			while (properties.size() > VECTOR_START){
				int tmp = VECTOR_START;
				int smallest_index = VECTOR_START;
				str_compare = properties[VECTOR_START]->get_address();
				for (tmp = VECTOR_START; tmp < properties.size(); tmp++){
					//string 1 is from the current property address
					string str1 = properties[tmp]->get_address();

					//if it's the old string is smaller, replace it
					if (str1.compare(str_compare) < VECTOR_START){
						smallest_index = tmp;
						str_compare = str1;
					//	cout << str_compare << endl << smallest_index << endl << str1 << endl;
					}
				}
				//push the smallest value string and add it to the new vector and remove it from the old
				shuffled_properties.push_back(properties[smallest_index]);
				int last_pos = properties.size() - 1;
				properties[smallest_index] = properties[last_pos];
				properties.pop_back();
			}
		}
		//make the original vector right again
		properties = shuffled_properties;
		cout << "Your properties have been sorted." << endl;
		
	}
	return;
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int main(){
	vector<Property*> properties;
	bool noerror = true;
		//load the file and spit out angry vices if stuff is wrong
		load_file(properties, noerror);
		//if an error, quit
		if (noerror == false){
			cout << "INCORRECT FILE, QUITTING NOW";
			return 1;
		}
		//give the man some space
		cout << endl;
		//display the properties
		display_prop(properties);
		//display the taxes
		//tell em what we're gonna do next
		shuffle(properties);
		cout << "\n\nNOW PRINTING TAX REPORT :\t\t\t";
		//just display the taxes and stuff
		for (int i = VECTOR_START; i < properties.size(); i++){
			cout << properties[i]->display_taxes();
		}
	system("pause");
	return 0;
}

/*
 * Contact.cpp
 *
 *  Created on: 29 de Mai de 2014
 *      Author: Anaís
 */

#include "Contact.h"
#include <sstream>

Contact::Contact(){
	this->id=0;
	this->number=0;
	this->distance=0;
}

Contact::Contact(int id, string name, int num, string email, string address, string city){
	this->id=id;
	this->name=name;
	this->number=num;
	this->email=email;
	this->address=address;
	this->city=city;
	this->distance=0;
}

void Contact::setDistance(int dist){
	this->distance=dist;
}
void Contact::setName(string name){
	this->name=name;
}

void Contact::setID(int id){
	this->id=id;
}

void Contact::setNumber(int num){
	this->number=num;
}

void Contact::setEmail(string email){
	this->email=email;
}

void Contact::setAddress(string address){
	this->address=address;
}

void Contact::setCity(string city){
	this->city=city;
}

int Contact::getDistance() const{
	return distance;
}

string Contact::getName(){
	return name;
}

int Contact::getID(){
	return id;
}

int Contact::getNumber(){
	return number;
}

string Contact::getEmail(){
	return email;
}

string Contact::getAddress(){
	return address;
}

string Contact::getCity(){
	return city;
}

bool Contact::operator<(const Contact &cont1) const{
	return (this->getDistance() < cont1.getDistance());
}

void Contact::displayContact(){
	cout << this->id << ". ";
	cout << this->name << "; " << this->number << "; ";
	cout << this->email << "; " << this->address << "; " << this->city;
	cout << endl;
}

int Contact::editContactMenu(){
	stringstream str2;
	char option;
	string input;
	int intinput;
	this->displayContact();
	cout << "What do you wish to change?" << endl;
	cout << "1. Name" << endl;
	cout << "2. Number" << endl;
	cout << "3. Email" << endl;
	cout << "4. Address" << endl;
	cout << "5. City" << endl;
	cout << "6. Delete contact" << endl;
	cout << "7. Exit" << endl;
	cout << endl << "Option: ";

	cin >> option;
	switch(option){
	case '1':
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "New name: ";
		getline(cin, input);
		this->setName(input);
		break;
	case '2':
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "New number: ";
		getline(cin, input);

		str2 << input;
		str2 >> intinput;
		this->setNumber(intinput);
		break;
	case '3':
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "New email: ";
		getline(cin, input);
		this->setEmail(input);
		break;
	case '4':
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "New address: ";
		getline(cin, input);
		this->setAddress(input);
		break;
	case '5':
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "New city: ";
		getline(cin, input);
		this->setCity(input);
		break;
	case '6':
		return -1;
		break;
	case '7':
		break;
	default: break;
	}
	return 0;
}


void Contact::addContact(){
	string input;
	int intinput;
	cout << "Please insert the following information: " << endl;
	cout << endl;
	cout << "Name: ";
	getline(cin, input);
	this->setName(input);

	cout << endl;
	cout << "Number: ";
	cin.clear();
	getline(cin, input);
	stringstream str;
	str << input;
	str >> intinput;
	this->setNumber(intinput);

	cout << endl;
	cout << "Email: ";
	getline(cin, input);
	this->setEmail(input);

	cout << endl;
	cout << "Address: ";
	getline(cin,input);
	this->setAddress(input);

	cout << endl;
	cout << "City: ";
	getline(cin, input);
	this->setCity(input);

	cout << endl << "Contact added! ";

}


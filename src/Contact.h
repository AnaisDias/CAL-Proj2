/*
 * Contact.h
 *
 *  Created on: 29 de Mai de 2014
 *      Author: Anaís
 */

#ifndef CONTACT_H_
#define CONTACT_H_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class Contact{
private:
	int id;
	string name;
	int number;
	string email;
	string address;
	string city;
	int distance;


public:

	Contact();
	Contact(int id,string name, int num, string email, string address, string city);
	void setDistance(int dist);
	void setID(int id);
	void setName(string name);
	void setNumber(int num);
	void setEmail(string email);
	void setAddress(string address);
	void setCity(string city);
	int getDistance() const;
	string getName();
	int getID();
	int getNumber();
	string getEmail();
	string getAddress();
	string getCity();
	void displayContact();
	bool operator<(const Contact  &cont1) const;
	int editContactMenu();
	void addContact();


};



#endif /* CONTACT_H_ */

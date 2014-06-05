/*
 * Loading.cpp
 *
 *  Created on: 31 de Mai de 2014
 *      Author: Anaís
 */

#include "Loading.h"
#include "Contact.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>


using namespace std;

vector<Contact> loadedContacts;
vector<string> contactFilenames;

void loadContactLists(){
	cout << "Choose file for contact loading/saving..." << endl;
	contactFilenames.clear();

	ifstream fin;
	fin.open("contactsList.txt");
	if (!fin) {
		cerr << "Unable to open file containing contact lists filenames." << endl;
		exit(1);
	}

	int nLists;
	string filename;
	fin >> nLists;
	for (int i = 0; i < nLists; i++) {
		fin >> filename;
		contactFilenames.push_back(filename);
	}
}

string pickListMenu(){
	bool done;
	unsigned int input;

	do {
		done = false;

		cout << endl;
		cout << "Existing contact lists: " << endl;
		for (unsigned int i = 0; i < contactFilenames.size(); i++)
			cout << i + 1 << ". " << contactFilenames[i] << endl;

		cout << endl;

		cout << "Choose a contact list: ";
		cin >> input;
		if (1 <= input && input <= contactFilenames.size())
			done = true;
		else {
			cin.clear();
			cin.ignore(10000, '\n');

			cout << endl;
			cout << "Invalid input. Press enter. " << endl;
			cin.get();
		}
	} while (!done);

	return contactFilenames[input-1];
}

vector<Contact> loadContacts(string filename){


		ifstream fin;
		fin.open(filename.c_str());
		if (!fin) {
			cerr << "Unable to open selected contacts file." << endl;
			exit(1);
		}

		int nContacts;
		int id=1;
		string name;
		string num;
		int number;
		string email;
		string address;
		string city;
		fin >> nContacts;
		for(int i=0; i<nContacts; i++)
		{
			getline(fin, name, ',');
			getline(fin, num, ',');
			number = atoi(num.c_str());
			getline(fin, email, ',');
			getline(fin, address, ',');
			getline(fin, city);
			Contact contact = Contact(id, name, number, email, address, city);
			id++;
			loadedContacts.push_back(contact);
		}

		return loadedContacts;

}

void saveContacts(string filename){

	ofstream outf;
	outf.open(filename.c_str(), std::ofstream::out|std::ofstream::trunc);
	outf << loadedContacts.size();
	for(int i=0; i<loadedContacts.size(); i++)
	{
		outf << loadedContacts[i].getName();
		outf << ",";
		outf << loadedContacts[i].getNumber();
		outf << ",";
		outf << loadedContacts[i].getEmail();
		outf << ",";
		outf << loadedContacts[i].getAddress();
		outf << ",";
		outf << loadedContacts[i].getCity();
		outf << endl;
	}
	outf.close();

}

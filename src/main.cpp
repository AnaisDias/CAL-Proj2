/*
 * main.cpp
 *
 *  Created on: 31 de Mai de 2014
 *      Author: Anaís
 */

#pragma once

#include "Contact.h"
#include "Search.h"
#include "Loading.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

void mainMenu(){
	cout << endl;
	cout << "---------------------------------" << endl;
	cout << "         Contact Manager         " << endl;
	cout << "---------------------------------" << endl;
	cout << endl;
	cout << "1. Add contact" << endl;
	cout << "2. Search contacts" << endl;
	cout << "3. Insert contact ID to manage" << endl;
	cout << "4. Exit" << endl;
	cout << endl;

	int input;
	string stinput;
	int deleteFlag=0;
	Contact contact;
	cout << "Choose an option:" << endl;
	cout << "> ";
	cin >> input;

	switch (input) {
	case 1:
		cin.clear();
		cin.ignore(10000, '\n');
		contact.addContact();
		loadedContacts.push_back(contact);
		system("pause");
		cin.clear();
		cin.ignore(10000, '\n');
		mainMenu();
		break;
	case 2:
		cin.clear();
		cin.ignore(10000, '\n');
		searchMenu();
		system("pause");
		cin.clear();
		cin.ignore(10000, '\n');
		mainMenu();
		break;
	case 3:
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Enter contact ID to edit or 0 to exit. ";
		cin >> input;
		if(input==0){
			mainMenu();
			return;
		}
		else{
			contact=getContactByID(input);
			if(contact.getID()==0){
				cout << endl;
				cout << "Contact not found. ";
				return;
			}
			else{
				cin.clear();
				cin.ignore(10000, '\n');

				deleteFlag= contact.editContactMenu();
				if (deleteFlag==-1) deleteContactByID(input);
				else{
					cout << "Do you wish to perform other changes? y/n ";
					cin >> stinput;
					if((stinput=="y") | (stinput=="Y")) contact.editContactMenu();
				}
			}
			system("pause");
			cin.clear();
			cin.ignore(10000, '\n');
			mainMenu();
			break;
	case 4:
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Do you wish to save first? y/n";
		//save options
		cin >> stinput;
		if(stinput=="y") {
			cout << endl << endl;
			loadContactLists();
			saveContacts(pickListMenu());
		}
		break;
	default:
		cout << endl;
		cout << "Invalid input." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Press enter...";
		cin.get();
		mainMenu();
		break;
		}
	}
}

int main(){
	loadContactLists();
	loadContacts(pickListMenu());
	mainMenu();
	return 0;

}

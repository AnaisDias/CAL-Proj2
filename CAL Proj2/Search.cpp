/*
 * Search.cpp
 *
 *  Created on: 31 de Mai de 2014
 *      Author: Anaís
 */
#include "Search.h"
#include "Loading.h"
#include "Contact.h"
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <conio.h>
#include <iostream>

using namespace std;

int editDistance(string textS, string compareS){

	unsigned int i,j;
	int D[textS.length()+1][compareS.length()+1];

	for (i = 0; i <= textS.length(); i++){

		D[i][0]=i;

	}
	for (j = 0; j <= compareS.length(); j++){

		D[0][j]=j;

	}

	for(i = 1 ; i <= textS.length();i++){

		for( j = 1; j <= compareS.length(); j++){

			if(textS[i-1]== compareS[j-1])
				D[i][j] = D[i-1][j-1];

			else
				D[i][j] = 1 + min(min(D[i-1][j-1],D[i-1][j]),D[i][j-1]);
		}


	}

	return D[textS.length()][compareS.length()];

}

void performSearch(string comp){
	int num;

	num = atoi(comp.c_str());

	if (num == 0 && comp[0] != '0')
	{
		for(int i=0; i<loadedContacts.size(); i++)
		{
			compareContact(comp, loadedContacts[i]);
		}
		//not a number
	}
	else{
		for(int j=0; j<loadedContacts.size(); j++)
		{
			comparePhoneNumbers(num, loadedContacts[j]);
		}
		//is a number
	}

	sort(loadedContacts.begin(), loadedContacts.end());
}

void searchMenu(){

	Contact cont;
	int deleteFlag;
	char primaryInput;
	string input;
	string comparison="";
	int numComparison=0;
	bool loop=true;
	cout << "Which search would you like to perform? " << endl;
	cout << "1. Text search" << endl;
	cout << "2. Number search " << endl;
	cout << "Please pick an option: ";
	cin >> input;

	if(input == "1"){
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Text search: " << endl;
		while(loop){
			stringstream str;
			//cin.clear();
				primaryInput=_getch();

				if (primaryInput != '\r')


			str << primaryInput;
			string comp;
			comp=str.str();

			//str >> comp;
			comparison = comparison + comp;
			cout << primaryInput;
			/*cin.clear();
			cin.ignore(10000, '\n');*/
			system("cls");
			cout << endl << "Text search: " << comparison << endl;
			displaySearchResults(comparison);
			comp.clear();
			if(primaryInput=='\r') loop=false;
		}


	}
	else if(input == "2"){
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Number search: ";
		while(loop){
			int inputc;
			stringstream str;
			inputc=_getch()-'0';

			if (inputc != ('\r' - '0'))


			str << inputc;
			int comp;
			str >> comp;
			numComparison = numComparison*10 + comp;
			str.clear();
			str << numComparison;
			str >> comparison;
			system("cls");
			cout << endl << "Number search: " << comparison << endl;
			displaySearchResults(comparison);
			if(inputc==('\r'-'0')) loop=false;
		}
	}

	cout << "Enter contact ID to edit or 0 to exit. ";
	cin >> input;
	if(input=="0"){
		return;
	}
	else{
		int id = atoi(input.c_str());
		cont=getContactByID(id);
		if(cont.getID()==0){
			cout << endl;
			cout << "Contact not found. ";
			return;
		}
		else{
			cin.clear();
			cin.ignore(10000, '\n');

			deleteFlag= cont.editContactMenu();
			if (deleteFlag==-1) deleteContactByID(id);
			else{
			cout << "Do you wish to perform other changes? y/n ";
			cin >> input;
			if((input=="y") | (input=="Y")) cont.editContactMenu();
			}
		}
	}

}

void displaySearchResults(string comp){

	performSearch(comp);
	int size;
	if (loadedContacts.size() >7) size = 7;
	else size = loadedContacts.size();
	for(int i=0; i<size; i++){
		cout << "> ";
		loadedContacts[i].displayContact();
		cout << endl;
	}
	cout << endl;
	cout << "To conclude search, press enter. Search: " << comp;
}

Contact getContactByID(int id){
	for (int i=0; i<loadedContacts.size(); i++){
		if (loadedContacts[i].getID()==id) return loadedContacts[i];
	}
}

void deleteContactByID(int id){
	for (int i=0; i<loadedContacts.size(); i++){
			if (loadedContacts[i].getID()==id) loadedContacts.erase(loadedContacts.begin()+i);
		}
}


void compareContact(string comp, Contact &contact){
	int distance[4];
	int smallestDist=1000;

	distance[0]= editDistance(contact.getName(), comp);

	distance[1]= editDistance(contact.getEmail(), comp);

	distance[2]= editDistance(contact.getAddress(), comp);
	distance[4]= editDistance(contact.getCity(), comp);

	for (int i=0; i<4; i++)
	{
		if (distance[i] < smallestDist) smallestDist=distance[i];
	}

	contact.setDistance(smallestDist);
}

void comparePhoneNumbers(int num, Contact &contact){
	ostringstream ss;
	ss << num;
	string inputString = ss.str();

	ss << contact.getNumber();
	string compareString = ss.str();

	int distance = editDistance(inputString, compareString);

	contact.setDistance(distance);

}



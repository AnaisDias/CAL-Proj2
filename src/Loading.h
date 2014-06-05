/*
 * Loading.h
 *
 *  Created on: 31 de Mai de 2014
 *      Author: Anaís
 */

#ifndef LOADING_H_
#define LOADING_H_

#include <string>
#include <vector>
#include "Contact.h"

using namespace std;

extern vector<Contact> loadedContacts;
extern vector<string> contactFilenames;

void loadContactLists();
string pickListMenu();
vector<Contact> loadContacts(string filename);
void saveContacts(string filename);


#endif /* LOADING_H_ */

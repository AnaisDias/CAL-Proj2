/*
 * Search.h
 *
 *  Created on: 31 de Mai de 2014
 *      Author: Anaís
 */

#ifndef SEARCH_H_
#define SEARCH_H_
#include <string>
#include "Contact.h"

using namespace std;


void editDistance();

void performSearch(string comp);

void searchMenu();
void displaySearchResults(string comp);
//pesquisa tem de ser dinamica (ou seja, tem de receber um
//caracter de cada vez e atualizar sempre q recebe um novo)

Contact getContactByID(int id);
void deleteContactByID(int id);
//tem de ter interface de gestao de contactos

void compareContact(string comp, Contact &contact);

void comparePhoneNumbers(int num, Contact &contact);
#endif /* SEARCH_H_ */

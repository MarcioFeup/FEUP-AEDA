/*
 * BankOfficer.cpp
 */
#include "BankOfficer.h"


BankOfficer::BankOfficer(): id(0) {}

void BankOfficer::setName(string nm){
	name = nm;
}

string BankOfficer::getName() const{
	return name;
}

vector<Account *> BankOfficer::getAccounts() const {
	return myAccounts;
}

void BankOfficer::addAccount(Account *a) {
	myAccounts.push_back(a);
}

unsigned int BankOfficer::getID() const{
	return id;
}


// ----------------------------------------------------------------------------------------------

unsigned BankOfficer::amount = 0;

BankOfficer::BankOfficer(string name) : id(++amount), name(std::move(name)) {}

bool operator>(const BankOfficer &b1, const BankOfficer &b2) {
	bool bigger;

	if (b1.myAccounts.size() == b2.myAccounts.size())
		bigger = b1.name > b2.name;
	else
		bigger = b1.myAccounts.size() > b2.myAccounts.size();

	return bigger;
}




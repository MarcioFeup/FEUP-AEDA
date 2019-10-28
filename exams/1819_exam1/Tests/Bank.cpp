/*
 * Bank.cpp
 */

#include "Bank.h"
#include <algorithm>
#include <string>

Bank::Bank() {}

void Bank::addAccount(Account *a) {
	accounts.push_back(a);
}

void Bank::addBankOfficer(BankOfficer b) {
	bankOfficers.push_back(b);
}

vector<BankOfficer> Bank::getBankOfficers() const {
	return bankOfficers;
}

vector<Account *> Bank::getAccounts() const {
	return accounts;
}


// ----------------------------------------------------------------------------------------------

bool accountLessThan(Account *ac1, Account *ac2) {
	if (ac1->getBalance() == ac2->getBalance())
		return ac1->getCodIBAN() < ac2->getCodIBAN();

	return (ac1->getBalance() < ac2->getBalance());
}

double Bank::getWithdraw(string cod1) const {
	std::list<Account *> clientAccounts = getAccounts(cod1);
	double value = 0;

	for (Account *account : clientAccounts)
		value += account->getWithdraw();

	return value;
}

vector<Account *> Bank::removeBankOfficer(string name) {
	vector<Account *> res;

	for (auto it = bankOfficers.begin(); it != bankOfficers.end() && !bankOfficers.empty(); ++it) {
		if ((*it).getName() == name) {
			for (Account *account : (*it).getAccounts())
				res.push_back(account);

			it = bankOfficers.erase(it);
		}
	}

	return res;
}

const BankOfficer &Bank::addAccountToBankOfficer(Account *ac, string name) {
	BankOfficer *bo = getBankOfficer(name);

	if (bo == nullptr)
		throw NoBankOfficerException(name);

	bo->addAccount(ac);
	return *bo;
}

void Bank::sortAccounts() {
	std::sort(accounts.begin(), accounts.end(), accountLessThan);
}

std::list<Account *> Bank::getAccounts(const string &codH) const {
	std::list<Account *> clientAccounts;

	for (Account *account : accounts)
		if (account->getCodH() == codH)
			clientAccounts.push_back(account);

	return clientAccounts;
}

BankOfficer *Bank::getBankOfficer(const string &name) {
	for (BankOfficer &bankOfficer : bankOfficers)
		if (bankOfficer.getName() == name)
			return &bankOfficer;

	return nullptr;
}

NoBankOfficerException::NoBankOfficerException(const std::string &name, const std::string &message) : std::logic_error(name + ": " + message), name(name), message(message) {}

const std::string &NoBankOfficerException::getName() const {
	return name;
}


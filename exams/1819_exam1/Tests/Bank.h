/*
 * Bank.h
 */

#ifndef SRC_BANK_H_
#define SRC_BANK_H_

#include "Account.h"
#include <vector>
#include <list>
#include <stdexcept>

#include "BankOfficer.h"


class Bank {
	vector<Account *> accounts;
	vector<BankOfficer> bankOfficers;
public:
	Bank();
	void addAccount(Account *a);
	void addBankOfficer(BankOfficer b);
	vector<BankOfficer> getBankOfficers() const;
	vector<Account *> getAccounts() const;

	//-------
	double getWithdraw(string cod1) const;
	vector<Account *> removeBankOfficer(string name);
	const BankOfficer& addAccountToBankOfficer(Account *ac, string name);
	void sortAccounts();

  private:
	std::list<Account *> getAccounts(const string &codH) const;
	BankOfficer *getBankOfficer(const string &name);
};

class NoBankOfficerException : public std::logic_error {

  public:
	NoBankOfficerException(const std::string &name, const std::string &message = "The bank officer doest not exist.");
	const std::string &getName() const;

  private:
	const std::string name;
	const std::string message;
};

template <class T>
unsigned int numberDifferent(const std::vector<T> &v1) {
	unsigned qt = 0;

	for (int i = 0; i < v1.size(); ++i) {
		int j = i - 1;
		for (; j >= 0; --j)
			if (v1[i] == v1[j]) break;

		if (j < 0)
			qt++;
	}

	return qt;
}

#endif /* SRC_BANK_H_ */

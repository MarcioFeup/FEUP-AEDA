//
// Created by Márcio on 9/28/19.
//
#include <fstream>

#include "market.h"
#include "../exception/file/fileException.h"
#include "../exception/market/market.h"

using namespace std;

void Market::start(const string &fileName) {
	ifstream in;
	in.open(fileName);

	if (!in.is_open())
		throw NonExistentFileException("File \"" + fileName + "\" does not exist.");

	string line;
	while(getline(in, line)) {
		if (line == "cliente" || line == "fornecedor")
			readParticipant(&in);
		else if (line == "produto")
			readProduct(&in);
		else if (line == "produtoCons")
			readConserve(&in);
		else
			throw InputException(line + " is not accepted as a type.");
	}

	in.close();
}

Participant *Market::lowestPrice(int productId, int quantity) const {
	// TODO: implement.
	return nullptr;
}

void Market::sale() { /* TODO: implement. */ }

void Market::readParticipant(std::ifstream *ifstream) { /* TODO: implement. */ }

void Market::readProduct(std::ifstream *ifstream) { /* TODO: implement. */ }

void Market::readConserve(std::ifstream *ifstream) { /* TODO: implement. */ }

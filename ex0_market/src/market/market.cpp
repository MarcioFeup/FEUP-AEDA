//
// Created by Márcio on 9/28/19.
//
#include <fstream>
#include <algorithm>

#include "market.h"
#include "../exception/file/fileException.h"
#include "../exception/market/business.h"

using namespace std;

ProductManager::~ProductManager() {
	for (auto &p : products)
		delete p;
	products.clear();
}

const Product &ProductManager::getProduct(int productId) const {
	Product *res = NULL;

	for (Product *p : products)
		if (p->getId() == productId)
			res = p;

	if (res == NULL) {
		//TODO: throw future exception.
	}

	return *res;
}

bool ProductManager::addProduct(Product product) {
	if (productExists(product.getId()))
		return false;

	products.push_back(new Product(product));
	return true;
}

bool ProductManager::productExists(int productId) const {
	for (Product *p : products)
		if (p->getId() == productId)
			return true;

	return false;
}

const Participant &ParticipantManager::getParticipant(int id) {
	auto i = participants.begin();
	for (i = participants.begin(); i != participants.end(); ++i)
		if (i->getId() == id)
			return *i;

	return *i;
}

bool ParticipantManager::hasParticipant(int id) {
	for (Participant &participant : participants)
		if (participant.getId() == id)
			return true;
	return false;
}

const std::vector<Participant> ParticipantManager::getParticipants() const {
	return std::vector<Participant>();
}

void Market::start(const string &fileName) {
	ifstream in;
	in.open(fileName);

	if (!in.is_open())
		throw NonExistentFileException("File \"" + fileName + "\" does not exist.");

	string line;
	while (getline(in, line)) {
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

const Participant *Market::lowestPrice(int productId, int quantity) const {
	// TODO: complete.
	return nullptr;
}

void Market::sale() { /* TODO: implement. */ }

void Market::readParticipant(std::ifstream *ifstream) {
	string participantId;
	getline(*ifstream, participantId);

	int id = stoi(participantId);

	if (!this->participantManager.hasParticipant(id))
		throw NonExistentParticipantException("The participant with id " + participantId + " does not exist.");
	Participant participant = this->participantManager.getParticipant(id);

	// TODO: read product.
	// TODO: read quantity.
	// TODO: read price.
}

void Market::readProduct(std::ifstream *ifstream) { /* TODO: implement. */ }

void Market::readConserve(std::ifstream *ifstream) { /* TODO: implement. */ }

const ParticipantManager &Market::getParticipantManager() const {
	return participantManager;
}

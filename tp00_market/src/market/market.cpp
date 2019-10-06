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

Product *ProductManager::getProduct(int productId) {
	for (Product *p : products)
		if (p->getId() == productId)
			return p;

	return NULL;
}

bool ProductManager::addProduct(Product product) {
	if (hasProduct(product.getId()))
		return false;

	products.push_back(new Product(product));
	return true;
}

bool ProductManager::hasProduct(int productId) const {
	for (Product *p : products)
		if (p->getId() == productId)
			return true;

	return false;
}

const Seller *ParticipantManager::lowestPrice(int productId, int quantity) {
	Seller *bestSeller = nullptr;
	float lowestPrice = std::numeric_limits<float>::max(), price;

	for (Seller &seller : sellers) {
		if (seller.hasProduct(productId, quantity)) {
			price = seller.getProduct(productId, quantity).getPrice();

			if (price < lowestPrice) {
				lowestPrice = price;
				bestSeller = &seller;
			}
		}
	}

	return bestSeller;
}

void ParticipantManager::sale() {
	for (Seller &seller : sellers)
		seller.discount();
}

const Participant *ParticipantManager::getParticipant(int id) {
	for (Client &client : clients)
		if (client.getId() == id)
			return &client;

	for (Seller &seller : sellers)
		if (seller.getId() == id)
			return &seller;

	return NULL;
}

bool ParticipantManager::hasParticipant(int id) {
	for (Client &client : clients)
		if (client.getId() == id)
			return true;

	for (Seller &seller : sellers)
		if (seller.getId() == id)
			return true;

	return false;
}

void Market::start(const string &fileName) {
	ifstream in;
	in.open(fileName);

	if (!in.is_open())
		throw NonExistentFileException(fileName);

	string line;
	while (getline(in, line)) {
		if (line == "cliente" || line == "fornecedor")
			readParticipant(in);
		else if (line == "produto")
			readProduct(in);
		else if (line == "produtoCons")
			readConserve(in);
		else
			throw InputException(fileName, line + " is not accepted as a type.");
	}

	in.close();
}

void Market::readParticipant(std::ifstream &ifstream) {
	string element;
	// reads participant.
	getline(ifstream, element);
	int participantId = stoi(element);
	if (!this->participantManager.hasParticipant(participantId))
		throw NonExistentParticipantException(participantId);
	Participant participant = *this->participantManager.getParticipant(participantId);

	// reads product.
	getline(ifstream, element);
	int productId = stoi(element);
	if (!this->productManager.hasProduct(productId))
		throw UnavailableProductException(productId, "The product does not exist.");
	Product *product = this->productManager.getProduct(productId);

	// TODO: read quantity.

	// TODO: read price.
}

void Market::readProduct(std::ifstream &ifstream) { /* TODO: implement. */ }

void Market::readConserve(std::ifstream &ifstream) { /* TODO: implement. */ }

const ParticipantManager &Market::getParticipantManager() const {
	return participantManager;
}

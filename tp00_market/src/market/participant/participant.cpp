//
// Created by marcio on 9/28/19.
//

#include "participant.h"

Participant::Participant(int id) : id(id) {}

void Participant::addProduct(MarketableProduct marketableProduct) {
	associatedProducts.push_back(marketableProduct);
}

bool Participant::hasProduct(int productId, int quantity) const {
	for (MarketableProduct product : associatedProducts)
		if (product.getProduct()->getId() == productId && product.getQuantity() >= quantity)
			return true;

	return false;
}

const MarketableProduct &Participant::getProduct(int productId, int quantity) const {
	for (auto i = associatedProducts.begin(); i < associatedProducts.end(); ++i)
		if (i->getProduct()->getId() == productId && i->getQuantity() >= quantity)
			return *i;

	return associatedProducts[0];
}

const int Participant::getId() const {
	return id;
}

Client::Client(int id) : Participant(id) {}

Seller::Seller(int id) : Participant(id) {}

void Seller::discount() {
	for (MarketableProduct product : associatedProducts)
		product.applyDiscount();
}

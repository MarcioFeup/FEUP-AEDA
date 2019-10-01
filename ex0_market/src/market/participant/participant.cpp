//
// Created by marcio on 9/28/19.
//

#include "participant.h"

Participant::Participant(State state, int id) : state(state), id(id) {}

void Participant::addProduct(MarketableProduct marketableProduct) {
	associatedProducts.push_back(marketableProduct);
}

bool Participant::isSeller() const {
	return this->state == SELLER;
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

	return associatedProducts[0]; // TODO: what to return?
}

const int Participant::getId() const {
	return id;
}

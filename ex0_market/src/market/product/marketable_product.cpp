//
// Created by marcio on 9/28/19.
//

#include "marketable_product.h"

MarketableProduct::MarketableProduct(Product *product, int quantity, float price) : product(product),
																					quantity(quantity), price(price) {}

const Product *MarketableProduct::getProduct() const {
	return product;
}

int MarketableProduct::getQuantity() const {
	return quantity;
}

float MarketableProduct::getPrice() const {
	return price;
}

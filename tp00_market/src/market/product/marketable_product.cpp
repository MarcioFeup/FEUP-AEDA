#include "marketable_product.h"

MarketableProduct::MarketableProduct(Product *product, int quantity, float price) : product(product),
																					quantity(quantity), price(price) {}

void MarketableProduct::applyDiscount() {
	this->price -= ((float) this->product->getDiscountPercentage() / 100) * this->price;
}

const Product *MarketableProduct::getProduct() const {
	return product;
}

int MarketableProduct::getQuantity() const {
	return quantity;
}

float MarketableProduct::getPrice() const {
	return price;
}

#include "product.h"

int Product::getId() const {
	return id;
}

Product::Product(int id) : id(id) {}

float Product::getDiscountPercentage() const {
	return DISCOUNT_PERCENTAGE;
}

Conserve::Conserve(int id, float idealTemp, int shelfLife) : Product(id), idealTemp(idealTemp), shelfLife(shelfLife) {}

float Conserve::getDiscountPercentage() const {
	if (shelfLife <= MAX_DISCOUNTABLE_SHELF_LIFE)
		return MAX_DISCOUNTABLE_SHELF_LIFE;
	else
		return DISCOUNT_PERCENTAGE;
}

//
// Created by marcio on 9/28/19.
//

#include "product.h"

const int Product::getId() const {
	return id;
}

Product::Product(int id) : id(id) {}

Conserve::Conserve(int id, float idealTemp, int shelfLife) : Product(id), idealTemp(idealTemp), shelfLife(shelfLife) {}

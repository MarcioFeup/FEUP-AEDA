//
// Created by marcio on 9/28/19.
//

#ifndef AEDAEX0_MARKETABLE_PRODUCT_H
#define AEDAEX0_MARKETABLE_PRODUCT_H


#include "product.h"

/*!
 * Represents the formal definition of a marketable product.
 *
 * @author Márcio Duarte
 */
class MarketableProduct {

  private:
	/*!
	 * The product to market.
	 */
	const Product product;

	/*!
	 * The quantity of products.
	 */
	int quantity;

	/*!
	 * The full price of the marketable product.
	 */
	float price;

};


#endif //AEDAEX0_MARKETABLE_PRODUCT_H

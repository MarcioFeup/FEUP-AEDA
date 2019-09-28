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

  public:
	/*!
	 * Marketable product constructor, providing its product, quantity and price.
	 *
	 * @param product the product
	 * @param quantity the quantity
	 * @param price the price
	 */
	MarketableProduct(Product *product, int quantity, float price);

	/*!
	 * Gets the product.
	 *
	 * @return the product
	 */
	const Product *getProduct() const;

	/*!
	 * Gets the quantity.
	 *
	 * @return the quantity
	 */
	int getQuantity() const;

	/*!
	 * Gets the price.
	 *
	 * @return the price
	 */
	float getPrice() const;

  private:
	/*!
	 * The pointer to the product of the market.
	 */
	const Product *product;

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

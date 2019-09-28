//
// Created by marcio on 9/28/19.
//

#ifndef AEDAEX0_PRODUCT_H
#define AEDAEX0_PRODUCT_H

/*!
 * Represents a raw product.
 *
 * @author Márcio Duarte
 */
class Product {

  private:
	/*!
	 * The ID of the product.
	 */
	const int id;
};

/*!
 * Represents a product with exceptional requirements.
 *
 * @author Márcio Duarte
 */
class Conserve : public Product {

  private:
	/*!
	 * The ideal temperature to conserve the product.
	 */
	float idealTemp;

	/*!
	 * The shelf life of the product, in days.
	 */
	int shelfLife;
};

#endif //AEDAEX0_PRODUCT_H

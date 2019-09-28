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

  public:

	/*!
	 * The constructor of product that takes it ID.
	 *
	 * @param id the ID
	 */
	Product(int id);

	/*!
	 * Gets the ID of the product.
	 *
	 * @return the ID
	 */
	const int getId() const;

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

  public:
	/*!
	 * Constructor of conserve that gets its ID, ideal temperature and shelf life in days.
	 *
	 * @param id the ID
	 * @param idealTemp the ideal temperature
	 * @param shelfLife the shelf life in days
	 */
	Conserve(int id, float idealTemp, int shelfLife);

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

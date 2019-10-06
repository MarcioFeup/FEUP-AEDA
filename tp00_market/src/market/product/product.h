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
	 * Gets the percentage to discount on sale on the product.
	 *
	 * @return the percentage
	 */
	virtual float getDiscountPercentage() const;

	/*!
	 * Gets the ID of the product.
	 *
	 * @return the ID
	 */
	int getId() const;

  protected:

	/*!
	 * Percentage to discount on sale.
	 */
	static constexpr float DISCOUNT_PERCENTAGE = 2;

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

	/*!
	 * Gets the percentage to discount on sale on the product.
	 *
	 * @return the percentage
	 */
	float getDiscountPercentage() const override;

  protected:

	/*!
	 * The maximum shelf life in which the product receives a better discount.
	 */
	static constexpr int MAX_DISCOUNTABLE_SHELF_LIFE = 20;

	/*!
	 * Percentage of a great discount on sale.
	 */
	static constexpr float GREAT_DISCOUNT_PERCENTAGE = 5;

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

#ifndef AEDAEX0_PARTICIPANT_H
#define AEDAEX0_PARTICIPANT_H

#include <vector>

#include "../product/marketable_product.h"

/*!
 * Defines someone that is interested in marketing.
 *
 * @author Márcio Duarte
 */
class Participant {

  public:
	/*!
	 * Participant constructor, provides its state and ID.
	 *
	 * @param state the state
	 * @param id the id
	 */
	Participant(int id);

	/*!
	 * Adds a marketable product to the list.
	 *
	 * @param marketableProduct the marketable product
	 */
	void addProduct(MarketableProduct marketableProduct);

	/*!
	 * Gets if the participant has a certain product in its list.
	 *
	 * @param productId the ID of the product
	 * @param quantity the quantity of the product
	 * @return true if the participant has the product, false otherwise
	 */
	bool hasProduct(int productId, int quantity) const;

	/*!
	 * Gets the ID of the participant.
	 *
	 * @return the ID
	 */
	const int getId() const;

	/*!
	 * Gets a product given its ID and quantity.
	 * Should only be used after the verification of hasProduct(int, int). Otherwise, unexpected behavior is expected.
	 *
	 * @param productId the product ID
	 * @param quantity the quantity
	 * @return the marketable product
	 */
	virtual const MarketableProduct &getProduct(int productId, int quantity) const;

  protected:

	/*!
	 * Set of products of interest.
	 */
	std::vector<MarketableProduct> associatedProducts;

  private:

	/*!
	 * Unique code of the participant.
	 */
	const int id;
};

/*!
 * Represents a participant that buys products.
 *
 * @author Márcio Duarte
 */
class Client : public Participant {

  public:
	/*!
	 * Constructs a new client given its ID.
	 *
	 * @param id the ID
	 */
	Client(int id);
};

/*!
 * Represents a participant that sells products.
 *
 * @author Márcio Duarte
 */
class Seller : public Participant {

  public:
	/*!
	 * Constructs a new seller given its ID.
	 *
	 * @param id the ID
	 */
	Seller(int id);

	/*!
	 * Applies a discount to all their associated products.
	 */
	void discount();
};

#endif //AEDAEX0_PARTICIPANT_H

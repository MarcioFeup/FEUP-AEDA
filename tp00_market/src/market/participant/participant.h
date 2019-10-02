//
// Created by marcio on 9/28/19.
//

#ifndef AEDAEX0_PARTICIPANT_H
#define AEDAEX0_PARTICIPANT_H

#include <vector>

#include "../product/marketable_product.h"

/*!
 * Represents the position of a participant in the market
 */
enum State {
	CLIENT, SELLER
};

/*!
 * Defines someone that is interested in marketing.
 */
class Participant {

  public:
	/*!
	 * Participant constructor, provides its state and ID.
	 *
	 * @param state the state
	 * @param id the id
	 */
	Participant(State state, int id);

	/*!
	 * Adds a marketable product to the list.
	 *
	 * @param marketableProduct the marketable product
	 */
	void addProduct(MarketableProduct marketableProduct);

	/*!
	 * Gets if the participant is a seller.
	 *
	 * @return true if the participant is a seller, false otherwise
	 */
	bool isSeller() const;

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
	const MarketableProduct &getProduct(int productId, int quantity) const;

  private:
	/*!
	 * Unique code of the participant.
	 */
	const int id;

	/*!
	 * Defines what the participant is up to in the market.
	 */
	State state;

	/*!
	 * Set of products of interest.
	 */
	std::vector<MarketableProduct> associatedProducts;
};


#endif //AEDAEX0_PARTICIPANT_H

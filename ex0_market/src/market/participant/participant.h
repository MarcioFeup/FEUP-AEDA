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
	CLIENT, PROVIDER
};

/*!
 * Defines someone that is interested in marketing.
 */
class Participant {

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

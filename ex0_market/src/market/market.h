//
// Created by Márcio on 9/28/19.
//
#ifndef AEDAEX0_MARKET_H
#define AEDAEX0_MARKET_H

#include <string>
#include <vector>

#include "participant/participant.h"
#include "product/product.h"
#include "../exception/market/market.h"

/*!
 * Manages all the products, providing access to a list of them.
 *
 * @author Márcio Duarte
 */
class ProductManager {

  private:
	/*!
	 * The list of products.
	 */
	std::vector<Product*> products;
};

/*!
 * Represents the essence of the system.
 * Sellers sell products to clients, these operations are all processed inside a market,
 *
 * @author Márcio Duarte
 */
class Market {

  public:
	/*!
	 * Reads the file "fileName" and fills the information about products and participants in the market.
	 *
	 * @param fileName the name of the file to read
	 */
	void start(const std::string &fileName);

	/*!
	 * Gets the participant who sells a given product for the lowest price.
	 *
	 * @param productId the ID of the product
	 * @param quantity the minimum quantity required
	 * @return the participant
	 */
	Participant *lowestPrice(int productId, int quantity) const;

	/*!
	 * Defines new sale prices for all marketable products.
	 */
	void sale();

  private:
	/**
	 * The manager of products
	 */
	ProductManager productManager;

	/*!
	 * The list of active participants.
	 */
	std::vector<Participant> participants;

	/*!
	 * Reads a single participant from the ifstream.
	 *
	 * @param ifstream the ifstream
	 */
	void readParticipant(std::ifstream *ifstream);

	/*!
	 * Reads a single product from the ifstream.
	 *
	 * @param ifstream the ifstream
	 */
	void readProduct(std::ifstream *ifstream);

	/*!
	 * Reads a single conserve from the ifstream.
	 *
	 * @param ifstream the ifstream
	 */
	void readConserve(std::ifstream *ifstream);

};


#endif //AEDAEX0_MARKET_H

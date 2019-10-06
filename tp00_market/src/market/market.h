//
// Created by Márcio on 9/28/19.
//
#ifndef AEDAEX0_MARKET_H
#define AEDAEX0_MARKET_H

#include <string>
#include <vector>

#include "participant/participant.h"
#include "product/product.h"
#include "../exception/market/business.h"

/*!
 * Manages all the products, providing access to a list of them.
 *
 * @author Márcio Duarte
 */
class ProductManager {

  public:

	/*!
	 * Destructor of the product manager.
	 * Clears the entire vector.
	 */
	~ProductManager();

	/*!
	 * Adds a product to the list.
	 *
	 * @param product the product to add
	 * @return true if the product was successfully added, false if it already exists
	 */
	bool addProduct(Product product);

	/*!
	 * Verifies if a product exists by its ID.
	 *
	 * @param productId the ID
	 * @return true if it exists, false otherwise
	 */
	bool hasProduct(int productId) const;

	/*!
	 * Gets a product by its ID.
	 * Returns null if such product does not exist, safe use with hasProduct method.
	 *
	 * @param productId the product's ID
	 * @return the reference to the product
	 */
	Product *getProduct(int productId);

  private:

	/*!
	 * The list of products.
	 */
	std::vector<Product *> products;
};

/*!
 * Manages the participants, providing access to lists of clients and sellers.
 *
 * @author Márcio Duarte
 */
class ParticipantManager {

  public:
	/*!
	* Gets the seller who sells a given product for the lowest price.
	 *
	 * @param productId the ID of the product
	 * @param quantity the minimum quantity required
	 * @return the seller
	 */
	const Seller *lowestPrice(int productId, int quantity);

	/*!
	 * Defines new sale prices for all marketable products.
	 */
	void sale();


	/*!
	 * Verifies if a participant with a given ID exists.
	 *
	 * @param id the ID
	 * @return true if the participant exists, false otherwise
	 */
	bool hasParticipant(int id);

	/*!
	 * Gets a participant by its ID.
	 * If the participant is not found, will return null, so one should use this function in pair with
	 * "hasParticipant(int)".
	 *
	 * @param id the ID
	 * @return the correspondent participant
	 */
	const Participant *getParticipant(int id);

  private:
	/*!
	 * The list of clients.
	 */
	std::vector<Client> clients;

	/*!
	 * The list of sellers.
	 */
	std::vector<Seller> sellers;
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
	 * Gets the manager of participants, immutable.
	 *
	 * @return the manager of participants
	 */
	const ParticipantManager &getParticipantManager() const;

  private:
	/**
	 * The manager of products.
	 */
	ProductManager productManager;

	/*!
	 * The manager of participants.
	 */
	ParticipantManager participantManager;

	/*!
	 * Reads a single participant from the ifstream.
	 *
	 * @param ifstream the ifstream
	 */
	void readParticipant(std::ifstream &ifstream);

	/*!
	 * Reads a single product from the ifstream.
	 *
	 * @param ifstream the ifstream
	 */
	void readProduct(std::ifstream &ifstream);

	/*!
	 * Reads a single conserve from the ifstream.
	 *
	 * @param ifstream the ifstream
	 */
	void readConserve(std::ifstream &ifstream);

};


#endif //AEDAEX0_MARKET_H

#include <list>
#include "REAgency.h"

REAgency::REAgency() : catalogItems(PropertyTypeItem("", "", "", 0)) {
	//do nothing!
}

REAgency::REAgency(vector<Property *> properties) : catalogItems(PropertyTypeItem("", "", "", 0)) {
	this->properties = properties;
}

void REAgency::addProperty(Property *property) {
	this->properties.push_back(property);
}

void REAgency::addProperties(vector<Property *> properties) {
	this->properties = properties;
}

vector<Property *> REAgency::getProperties() const {
	return this->properties;
}

PropertyTypeItem REAgency::getTypeItem(string address, string postalCode, string typology) {
	PropertyTypeItem itemNotFound("", "", "", 0);
	BSTItrIn<PropertyTypeItem> it(catalogItems);
	while (!it.isAtEnd()) {
		if (it.retrieve().getAddress() == address && it.retrieve().getPostalCode() == postalCode &&
			it.retrieve().getTypology() == typology) {
			PropertyTypeItem pti(it.retrieve().getAddress(), it.retrieve().getPostalCode(), it.retrieve().getTypology(),
								 0);
			pti.setItems(it.retrieve().getItems());
			return pti;
		}
		it.advance();
	}
	return itemNotFound;
}

void REAgency::addTypeItem(Property *property) {
	PropertyTypeItem itemNotFound("", "", "", 0);
	PropertyTypeItem pti(property->getAddress(), property->getPostalCode(), property->getTypology(),
						 property->getPrice());
	PropertyTypeItem ptiX = catalogItems.find(pti);
	if (ptiX == itemNotFound) {
		pti.addItems(property);
		this->catalogItems.insert(pti);
	} else {
		this->catalogItems.remove(ptiX);
		ptiX.addItems(property);
		this->catalogItems.insert(ptiX);
	}
	properties.push_back(property);
}

BST<PropertyTypeItem> REAgency::getTypeItems() const {
	return this->catalogItems;
}

vector<ClientRecord> REAgency::getClientRecords() const {
	vector<ClientRecord> records;
	HashTabClientRecord::const_iterator it1 = this->listingRecords.begin();
	HashTabClientRecord::const_iterator it2 = this->listingRecords.end();
	for (; it1 != it2; it1++) {
		records.push_back(*it1);
	}
	return records;
}

void REAgency::setClientRecords(vector<ClientRecord> &crs) {
	for (unsigned int i = 0; i < crs.size(); i++) {
		listingRecords.insert(crs[i]);
	}

}

priority_queue<Client> REAgency::getClientProfiles() const {
	return clientProfiles;
}

void REAgency::setClientProfiles(priority_queue<Client> &profiles) {
	clientProfiles = profiles;
}

void REAgency::generateCatalog() {
	PropertyTypeItem notFound(PropertyTypeItem("", "", "", 0));

	for (Property *property : properties) {
		PropertyTypeItem item(property->getAddress(), property->getPostalCode(), property->getTypology(),
							  property->getPrice());
		PropertyTypeItem addedItem = catalogItems.find(item);
		if (addedItem == notFound) {
			item.addItems(property);
			catalogItems.insert(item);
		} else {
			catalogItems.remove(addedItem);
			addedItem.addItems(property);
			catalogItems.insert(addedItem);
		}
	}
}

vector<Property *> REAgency::getAvailableProperties(Property *property) const {
	vector<Property *> temp;

	for (Property *p : properties) {
		if (p->getAddress() == property->getAddress() && p->getPostalCode() == property->getPostalCode() &&
			p->getTypology() == property->getTypology() && std::get<0>(p->getReservation()) == nullptr) {
			temp.push_back(p);
		}
	}


	return temp;
}

bool REAgency::reservePropertyFromCatalog(Property *property, Client *client, int percentage) {
	PropertyTypeItem tmp(property->getAddress(), property->getPostalCode(), property->getTypology(),
						 property->getPrice());
	PropertyTypeItem notFound("", "", "", 0);

	PropertyTypeItem pti = catalogItems.find(tmp);

	if (pti == notFound) {
		return false;
	}
	else {
		for (Property *p : pti.getItems()) {
			if (std::get<0>(p->getReservation()) == nullptr) {

				int price = p->getPrice() - (float) percentage / 100.0 * p->getPrice();
				p->setReservation(make_tuple(client, price));
				client->addVisiting(p->getAddress(), p->getPostalCode(), p->getTypology(), to_string(price));
				return true;
			}
		}
	}

	return false;
}

//
// TODO: Part II  - Hash Table
//
void REAgency::addClientRecord(Client *client) {
	listingRecords.insert(client);
}

void REAgency::deleteClients() {
	for (auto it = listingRecords.begin(); it != listingRecords.end(); ++it)
		if ((*it).getClientPointer()->getVisitedProperties().empty())
			it = listingRecords.erase(it);
}

//
// TODO: Part III - Priority Queue
//
void REAgency::addBestClientProfiles(const vector<Client> candidates, int min) {
	for (const Client &candidate : candidates) {
		float ratio = (float) this->getReservationCount(candidate) / candidate.getVisitedProperties().size();

		if (ratio > min)
			clientProfiles.push(candidate);
	}

}

vector<Property *> REAgency::suggestProperties() {
	vector<Property *> tempProperties;
	std::list<Client> tmp;

	while (!clientProfiles.empty()) {
		Client client = clientProfiles.top();
		clientProfiles.pop();
		tmp.push_back(client);

		string postalCode = get<3>(client.getVisiting());
		if (postalCode != "")
			tempProperties.push_back(getClosestProperty(stoi(postalCode)));
	}

	for (Client &client : tmp)
		clientProfiles.push(client);

	return tempProperties;
}

unsigned REAgency::getReservationCount(Client client) const {
	unsigned count = 0;

	for (Property *property : properties)
		if (get<0>(property->getReservation())->getEMail() == client.getEMail())
			count ++;

	return count;
}

Property *REAgency::getClosestProperty(int postalCode) {
	int closestDistance = -1;
	Property *closest = nullptr;

	for (Property *property : properties) {
		int distance = abs(stoi(property->getPostalCode()) - postalCode);
		if (distance < closestDistance || !closest) {
			closestDistance = distance;
			closest = property;
		}
	}

	return closest;
}

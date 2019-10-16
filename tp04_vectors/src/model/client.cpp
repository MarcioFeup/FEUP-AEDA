#include "client.h"

#include <utility>
#include <iostream>

Client::Client(std::string name) : name(std::move(name)) {
	present = false;
	frequency = 0;
}

void Client::increaseFrequency() {
	this->frequency++;
}

std::string Client::getName() const {
	return name;
}

bool Client::isPresent() const {
	return present;
}

unsigned int Client::getFrequency() const {
	return frequency;
}

void Client::setPresent(bool present) {
	Client::present = present;
}

bool Client::operator==(const Client &another_client) const {
	return this->name == another_client.name;
}

bool operator<(const Client &client, const Client &anotherClient) {
	return client.frequency < anotherClient.frequency;
}

std::ostream &operator<<(std::ostream &os, const Client &client) {
	os << client.name << ", ";
	if (!client.present) os << "não ";
	os << "presente, entrou " << client.frequency << " vezes.";

	return os;
}

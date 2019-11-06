#include <random>
#include "client.h"

Client::Client() {
	this->qt_gifts = rand() % 5 + 1;
}

unsigned int Client::getQtGifts() const {
	return qt_gifts;
}

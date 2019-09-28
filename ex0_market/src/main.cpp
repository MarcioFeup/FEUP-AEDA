#include <iostream>
#include <exception>
#include "market/market.h"
#include "exception/file/fileException.h"

int main() {
	Market market;
	try {
		market.start("ola");
	} catch (FileException &f) {
		std::cerr << f.what() << std::endl;
	}
}
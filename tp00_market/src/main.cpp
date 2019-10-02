#include <iostream>
#include <exception>
#include "market/market.h"
#include "exception/file/fileException.h"

int main() {

	std::vector<int> ve{1, 2, 3, 4};

	auto i = ve.begin();
	for (i = ve.begin(); i != ve.end(); ++i)
		if (*i == 5)
			std::cout << *i << std::endl;

	std::cout << "aaaaa " << *i << std::endl;
}
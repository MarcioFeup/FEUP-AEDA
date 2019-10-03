#include <string>

#define recent (year > recentYear)

using namespace std;

namespace config {

	const string taxableFuel = "gasoline";
	const int recentYear = 1995;

	float calcTax(const string &fuelType, int displacement, int year) {
		float tax;

		if (fuelType == taxableFuel) {
			if (displacement <= 1000)
				tax = recent ? 14.56 : 8.10;
			else if (displacement <= 1300)
				tax = recent ? 29.06 : 14.56;
			else if (displacement <= 1750)
				tax = recent ? 45.15 : 22.65;
			else if (displacement <= 2600)
				tax = recent ? 113.98 : 54.89;
			else if (displacement <= 3500)
				tax = recent ? 181.17 : 87.13;
			else
				tax = recent ? 320.89 : 148.37;
		} else {
			if (displacement <= 1500)
				tax = recent ? 14.56 : 8.10;
			else if (displacement <= 2000)
				tax = recent ? 29.06 : 14.56;
			else if (displacement <= 3000)
				tax = recent ? 45.15 : 22.65;
			else
				tax = recent ? 113.98 : 54.89;
		}

		return tax;
	}

}

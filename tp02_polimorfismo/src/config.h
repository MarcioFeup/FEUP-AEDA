#include <string>

#define recent (year > recentYear)

using namespace std;

namespace config {

	const string taxableFuel = "gasolina";
	const int recentYear = 1995;

	float calcTax(const string &fuel, int cil, int year) {
		float tax;

		if (fuel == taxableFuel) {
			if (cil <= 1000)
				tax = recent ? 14.56 : 8.10;
			else if (cil <= 1300)
				tax = recent ? 29.06 : 14.56;
			else if (cil <= 1750)
				tax = recent ? 45.15 : 22.65;
			else if (cil <= 2600)
				tax = recent ? 113.98 : 54.89;
			else if (cil <= 3500)
				tax = recent ? 181.17 : 87.13;
			else
				tax = recent ? 320.89 : 148.37;
		} else {
			if (cil <= 1500)
				tax = recent ? 14.56 : 8.10;
			else if (cil <= 2000)
				tax = recent ? 29.06 : 14.56;
			else if (cil <= 3000)
				tax = recent ? 45.15 : 22.65;
			else
				tax = recent ? 113.98 : 54.89;
		}

		return tax;
	}

}

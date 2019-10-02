#include "veiculo.h"
#include "config.h"
#include <iostream>

using namespace std;

Veiculo::Veiculo(string mc, int m, int a) : marca(mc), mes(m), ano(a) {}

int Veiculo::info() const {
	cout << "marca: " << marca << endl <<
		 "mes: " << mes << endl <<
		 "ano: " << ano << endl;

	return 3;
}

bool Veiculo::operator<(const Veiculo &v) const {
	return (this->ano == v.ano) ? this->mes < v.mes : this->ano < v.ano;
}

int Veiculo::getAno() const {
	return ano;
}

string Veiculo::getMarca() const {
	return marca;
}

Motorizado::Motorizado(string mc, int m, int a, string c, int cil) : Veiculo(mc, m, a), combustivel(c),
																	 cilindrada(cil) {}

int Motorizado::info() const {
	int n = Veiculo::info();

	cout << "combustivel: " << combustivel << endl <<
		 "cilindrada: " << cilindrada << endl;

	return n + 2;
}

string Motorizado::getCombustivel() const {
	return combustivel;
}

float Motorizado::calcImposto() const {
	return config::calcTax(combustivel, cilindrada, ano);
}

Automovel::Automovel(string mc, int m, int a, string c, int cil) : Motorizado(mc, m, a, c, cil) {}

int Automovel::info() const {
	return Motorizado::info();
}

Camiao::Camiao(string mc, int m, int a, string c, int cil, int cm) : Motorizado(mc, m, a, c, cil), carga_maxima(cm) {}

int Camiao::info() const {
	int n = Motorizado::info();

	cout << "carga máxima: " << carga_maxima << endl;
	return n + 1;
}

Bicicleta::Bicicleta(string mc, int m, int a, string t) : Veiculo(mc, m, a), tipo(t) {}

int Bicicleta::info() const {
	int n = Veiculo::info();

	cout << "tipo: " << tipo << endl;
	return n + 1;
}

float Bicicleta::calcImposto() const {
	return 0; // no fuel.
}

#include "frota.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void Frota::adicionaVeiculo(Veiculo *v1) {
	this->veiculos.push_back(v1);
}

int Frota::numVeiculos() const {
	return this->veiculos.size();
}

int Frota::menorAno() const {
	if (numVeiculos() < 1)
		return 0;

	int ano = veiculos[0]->getAno();
	for (int i = 1; i < numVeiculos(); ++i)
		if (veiculos[i]->getAno() < ano)
			ano = veiculos[i]->getAno();

	return ano;
}

float Frota::totalImposto() const {
	float total = 0;

	for (auto vehicle : veiculos)
		total += vehicle->calcImposto();

	return total;
}

vector<Veiculo *> Frota::operator()(int anoM) const {
	vector<Veiculo *> res;

	for (Veiculo *v : veiculos)
		if (v->getAno() == anoM)
			res.push_back(v);

	return res;
}

ostream &operator<<(ostream &o, const Frota &f) {
	for (auto veiculo : f.veiculos)
		veiculo->info();

	return o;
}


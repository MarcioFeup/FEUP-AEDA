#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <time.h>
#include <string>
#include <algorithm>
#include "Kart.h"

using namespace std;

//To help build better array
string itos(int i) {
	stringstream s;
	s << i;
	return s.str();
}

void CGrupo::criaGrupo() {
	float cilindradas[4] = {134, 250, 450, 600};
	bool avariados[3] = {true, false, false};

	srand(1);   //Criar Pistas e Karts de Teste
	for (int i = 1; i <= 50; i++) {
		vector<CKart> frota;
		for (int j = 1; j <= 50; j++) {
			frota.push_back(CKart(avariados[rand() % 3],
								  ("KART - " + itos(i)) + itos(j), (i - 1) * 50 + j, cilindradas[(rand() % 4)]));
		}
		adicionaPista(CPista("Pista - " + itos(i), frota));
	}
}


vector<CKart> CPista::getKartsAvariados() {
	vector<CKart> aux;
	for (vector<CKart>::iterator it = frotaKartsPista.begin(); it != frotaKartsPista.end(); ++it) {
		if ((it)->getAvariado()) aux.push_back((*it));
	}
	return aux;
}

//Exercicio 1 a)
vector<CKart> CGrupo::ordenaKarts() {
	vector<CKart> all_karts;

	for (CPista &c_pista : pistasG)
		for (const CKart &c_kart : c_pista.getFrotaActual())
			all_karts.push_back(c_kart);

	std::sort(all_karts.begin(), all_karts.end(), [](CKart &a, CKart &b) {
		return a.getNumero() < b.getNumero();
	});

	return all_karts;
}

//Exercicio 1 b)
// TODO incorrect
int CGrupo::numAvariados(int cilind) {
	int res = 0;

	for (CPista &c_pista : pistasG)
		for (CKart &c_kart : c_pista.getKartsAvariados())
			if (c_kart.getCilindrada() == cilind)
				res ++;

	return res;
}

//Exercicio 1 c)
// TODO incorrect
bool CPista::prepararCorrida(int numeroKarts, int cilind) {
	int qt = 0;
	for (auto & kart : frotaKartsPista) {
		if (kart.getCilindrada() == cilind && !kart.getAvariado()) {
			kartsLinhaPartida.push(kart);
			++qt;

			if (qt >= numeroKarts)
				return true;
		}
	}
	return false;
}

//Exercicio 1 d)
// TODO incorrect
int CPista::inicioCorrida() {
	while (!kartsLinhaPartida.empty()) {
		CKart &kart = kartsLinhaPartida.front();
		kartsLinhaPartida.pop();
		kartsEmProva.push_back(kart);
	}

	return kartsEmProva.size();
}


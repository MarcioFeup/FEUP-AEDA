#ifndef VEICULO_H_
#define VEICULO_H_

#include <string>

using namespace std;

class Veiculo {

  public:
	Veiculo(string mc, int m, int a);
	virtual ~Veiculo() = default;

	virtual int info() const;

	virtual float calcImposto() const = 0;
	bool operator<(const Veiculo &v) const;

	int getAno() const;

	string getMarca() const;

  protected:
	string marca;
	int mes, ano;
};

class Motorizado : public Veiculo {

	string combustivel;
	int cilindrada;

  public:
	Motorizado(string mc, int m, int a, string c, int cil);

	virtual ~Motorizado() {};

	virtual int info() const;

	float calcImposto() const;

	string getCombustivel() const;
};

class Automovel : public Motorizado {

  public:
	Automovel(string mc, int m, int a, string c, int cil);

	~Automovel() {}

	int info() const;
};


class Camiao : public Motorizado {

	int carga_maxima;

  public:
	Camiao(string mc, int m, int a, string c, int cil, int cm);

	~Camiao() {}

	int info() const;
};


class Bicicleta : public Veiculo {

	string tipo;

  public:
	Bicicleta(string mc, int m, int a, string t);

	~Bicicleta() {}

	int info() const;

	float calcImposto() const;
};


#endif /* VEICULO_H_ */

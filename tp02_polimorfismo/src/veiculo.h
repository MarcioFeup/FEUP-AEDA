#ifndef VEICULO_H_
#define VEICULO_H_

#include <string>

using namespace std;

class Veiculo {

  protected:
	string marca;
	int mes, ano;

  public:
	Veiculo(string mc, int m, int a);

	int a();

	virtual ~Veiculo() {};

	virtual int info() const {return 0;};
	virtual float calcImposto() const = 0;

	bool operator<(const Veiculo &v) const;

	int getAno() const;
	string getMarca() const;
};

class Motorizado : public Veiculo {

	string combustivel;
	int cilindrada;

  public:
	Motorizado(string mc, int m, int a, string c, int cil);

	virtual ~Motorizado() {};

	virtual int info() const {return 0;};

	float calcImposto() const {return 0;}

	string getCombustivel() const;
};

class Automovel : public Motorizado {

  public:
	Automovel(string mc, int m, int a, string c, int cil);

	~Automovel() {}

	int info() const {return 0;};
};


class Camiao : public Motorizado {

	int carga_maxima;

  public:
	Camiao(string mc, int m, int a, string c, int cil, int cm);

	~Camiao() {}

	int info() const {return 0;};
};


class Bicicleta : public Veiculo {

	string tipo;

  public:
	Bicicleta(string mc, int m, int a, string t);

	~Bicicleta() {}

	int info() const {return 0;};
	float calcImposto() const {return 0;};
};


#endif /* VEICULO_H_ */

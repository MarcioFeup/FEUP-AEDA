// CSimpleList - Implementacao Simples de Lista Ligada
#include <iostream>
#include <string>

using namespace std;

class CNode {
private:
	int d_data;
	CNode *d_next;
public:
	CNode(int data, CNode *next) {
		d_data = data;
		d_next = next;
	}

	void setData(int data) { d_data = data; }

	void setNext(CNode *next) { d_next = next; }

	int data() const { return d_data; }

	CNode *next() const { return d_next; }

	void print() const { cout << d_data << " "; }
};

class CSimpleList {
private:
	CNode *first;
public:
	CSimpleList() { first = 0; }

	~CSimpleList() {
		CNode *aux = first;
		CNode *cur;
		while (aux != 0) {
			cur = aux;
			aux = aux->next();
			delete cur;
		}
	}

	bool empty() const { return (first == 0); }

	string toStr() const {
		stringstream oss;
		CNode *aux = first;
		while (aux != 0) {
			oss << aux->data() << " ";
			aux = aux->next();
		}
		return oss.str();
	}

	void print() const {
		CNode *aux = first;
		cout << "List: ";
		while (aux != 0) {
			aux->print();
			aux = aux->next();
		}
		cout << endl;
	}

	CNode *find(int elem) {
		CNode *aux = first;
		while (aux != 0 && aux->data() != elem) aux = aux->next();
		if (aux != 0) return aux;
		else {
			cerr << "Elem is not in list\n";
			return 0;
		}
	}

	void insert_head(int elem) {
		CNode *res = new CNode(elem, first);
		first = res;
	}

	void insert_end(int elem) {
		CNode *node, *aux;
		node = new CNode(elem, 0);
		aux = first;
		if (aux == 0) first = node;
		else {
			while (aux->next() != 0) aux = aux->next();
			aux->setNext(node);
		}
	}

	void insert_sort(int elem) {
		CNode *prev, *node, *aux;
		node = new CNode(elem, 0);
		prev = 0;
		aux = first;
		while (aux != 0 && aux->data() < elem) {
			prev = aux;
			aux = aux->next();
		}
		node->setNext(aux);
		if (prev == NULL) first = node; else prev->setNext(node);
	}

	// TODO fix for lst size > this size
	void intercalar(const CSimpleList &lst) //Grupo 2 c)
	{
		CNode *a_first = this->first;
		CNode *a_next = a_first->next();

		CNode *it = lst.first;
		CNode *oz;

		while (it != 0 && a_next != 0) {
			oz = new CNode(it->data(), a_next);

			a_first->setNext(oz);

			a_first = a_next;
			a_next = a_first->next();

			it = it->next();
		}

		while (it != 0) {
			oz = new CNode(it->data(), 0);
			a_first->setNext(oz);

			a_first = oz;

			it = it->next();
		}
	}

	int zipar() //Grupo 2 d)
	{
		if (this->empty())
			return 0;

		int qt = 0;

		CNode *current = this->first;
		CNode *next = current->next();
		while (next != 0) {

			if (current->data() == next->data()) {
				current->setNext(next->next());
				qt++;
			} else {
				current = next;
			}

			next = current->next();
		};

		return qt;
	}
}; 


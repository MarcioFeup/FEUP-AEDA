#include "vet.h"
#include "animal.h"
#include <sstream>
#include <utility>

using namespace std;

Vet::Vet(string name, long id) : name(std::move(name)), id(id) {}

string Vet::info() const {
	string info;
	return info.append(name).append(", ").append(to_string(id));
}

string Vet::getName() const {
	return name;
}




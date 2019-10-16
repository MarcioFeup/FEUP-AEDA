#ifndef AEDA1920_FP04_CLIENT_H
#define AEDA1920_FP04_CLIENT_H

#include <string>

class Client {

  public:
	Client(std::string name);
	void increaseFrequency();
	std::string getName() const;
	bool isPresent() const;
	unsigned int getFrequency() const;
	void setPresent(bool present);
	bool operator==(const Client &another_client) const;

	friend bool operator<(const Client &client, const Client &anotherClient);
	friend std::ostream &operator<<(std::ostream &os, const Client &pl);

  private:
	std::string name;
	bool present;
	unsigned int frequency;
};


#endif //AEDA1920_FP04_CLIENT_H

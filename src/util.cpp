#include <iostream>

std::string getGreeting() {
	return "Salutations, from libwtclient.";
}

void printGreeting() {
	std::cout << getGreeting() << std::endl;
}

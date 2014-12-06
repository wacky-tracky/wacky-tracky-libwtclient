#include <iostream>
#include <wtSession.hpp>

int main() {
	std::cout << std::hex << hashPassword("hello") << std::endl;
}

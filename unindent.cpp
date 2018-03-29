#include "funcs.hpp"
#include <iostream>
#include <iterator>
#include <string>

int main() {
	// Don't ask, this is how we read a whole stream in C++
	std::string input_file(std::istreambuf_iterator<char>(std::cin), {});

	std::cout << dedent(input_file);
}

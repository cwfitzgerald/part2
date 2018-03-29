#include "funcs.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <thread>

int main() {
	// Don't ask, this is how we read a whole stream in C++
	std::string input_file(std::istreambuf_iterator<char>(std::cin), {});

	std::cout << redent(dedent(input_file));
}

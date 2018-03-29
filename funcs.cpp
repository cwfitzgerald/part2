#include "funcs.hpp"
#include <cctype>

std::string dedent(std::string line) {
	std::string ret;
	bool newline = true;
	for (char c : line) {
		if (newline && std::isspace(c) != 0) {
		}
		else if (c == '\n') {
			newline = true;
			ret.push_back(c);
		}
		else {
			newline = false;
			ret.push_back(c);
		}
	}
	return ret;
}

std::string redent(std::string line) {
	std::string ret;
	bool newline = true;
	std::intmax_t depth = 0;
	for (char c : line) {
		if (newline) {
			if (c == '}') {
				std::fill_n(std::back_inserter(ret), std::max(depth - 1, std::intmax_t(0)), '\t');
			}
			else {
				std::fill_n(std::back_inserter(ret), std::max(depth, std::intmax_t(0)), '\t');
			}

			newline = false;
		}
		else if (c == '\n') {
			newline = true;
		}
		else {
			newline = false;
		}

		if (c == '{') {
			depth++;
		}
		else if (c == '}') {
			depth--;
		}
		ret.push_back(c);
	}
	return ret;
}

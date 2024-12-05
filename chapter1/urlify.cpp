#include <string>
#include <assert.h>

/*
 * Replace space with %20
 * */
std::string urlify(std::string str) {
	std::string result;

	for (char& ch : str) {
		if (ch == ' ') {
			result.push_back('%');
			result.push_back('2');
			result.push_back('0');
		} else {
			result.push_back(ch);
		}
	}

	return result;
}

int main() {
	assert(urlify("Mr. John Smith") == "Mr.%20John%20Smith");

	return 0;
}

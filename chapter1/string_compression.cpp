#include <string>
#include <assert.h>

std::string compress(std::string str) {
	std::string compressed;
	int count = 0;

	for (int i = 0; i < str.length(); i++) {
		count++;

		if (i+1 >= str.length() || str.at(i) != str.at(i+1)) {
			compressed.push_back(str.at(i));
			compressed.push_back('0' + count);
			count = 0;
		}
	}

	return compressed.length() < str.length() ? compressed : str;
}

int main() {
	assert(compress("aabbbccccddddd") == "a2b3c4d5");
	assert(compress("abcdefg") == "abcdefg");
	
	return 0;
}

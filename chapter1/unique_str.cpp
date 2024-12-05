#include <string>
#include <assert.h>
#include <algorithm>

bool is_unique_string(std::string str) {
	if (str.length() > 256) {
		return false;
	}

	bool charset[256];
	std::fill_n(charset, 256, false); 

	for (char& ch : str) {
		bool val = charset[int(ch)];
		if (val) {
			return false;
		} else {
			charset[int(ch)] = true;
		}
	}

	return true;
}

int main() {
	assert(is_unique_string("abba") == false);
	assert(is_unique_string("abcd") == true);
	//TODO: add more test cases

	return 0;
}

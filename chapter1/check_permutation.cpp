#include <assert.h>
#include <string>
#include <algorithm>

bool permutation(std::string str1, std::string str2) {
	if (str1.length() != str2.length()) {
		return false;
	}

	std::sort(str1.begin(), str1.end());
	std::sort(str2.begin(), str2.end());

	return str1 == str2;
}

int main() {
	assert(permutation("abba", "abbc") == false);
	assert(permutation("abcd", "cdba") == true);
	assert(permutation("abcd", "cdbae") == false);

	return 0;
}

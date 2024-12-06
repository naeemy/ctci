#include <string>
#include <assert.h>
#include <map>

bool is_permutation_of_palindrome(std::string str) {
	std::map<char, bool> chars;
	int odd_count = 0;

	for (char& ch: str) {
		if (chars[ch]) {
			odd_count++;
		} else {
			chars[ch] = true;
		}
	}

	return odd_count > 1;
}

int main() {
	assert(is_permutation_of_palindrome("abc") == false);
	assert(is_permutation_of_palindrome("tactcoa") == true);
	assert(is_permutation_of_palindrome("aabbc") == true);

	return 0;
}

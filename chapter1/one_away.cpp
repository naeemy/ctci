#include <string>
#include <assert.h>

bool one_edit_replace(std::string first, std::string second) {
	bool found = false;
	for (int i = 0; i < first.length(); i++) {
		if (first[i] != second[i]) {
			if (found) {
				return false;
			} else {
				found = true;
			}
		}
	}

	return true;
}

bool one_edit_insert(std::string first, std::string second) {
	int index1 = 0;
	int index2 = 0;

	while (index1 < first.length() && index2 < second.length()) {
		if (first.at(index1) != second.at(index2)) {
			if (index1 != index2) {
				return false;
			}

			index2++;
		} else {
			index1++;
			index2++;
		}
	}

	return true;
}

bool one_edit_away(std::string first, std::string second) {
	if (first.length() == second.length()) {
		return one_edit_replace(first, second);
	} else if (first.length() + 1 == second.length()) {
		return one_edit_insert(first, second);
	} else if (first.length() - 1 == second.length()) {
		return one_edit_insert(first, second);
	} 

	return false;
}

int main() {
	assert(one_edit_away("bale", "pale") == true);
	assert(one_edit_away("bale", "pali") == false);
	assert(one_edit_away("apple", "appe") == true);
	assert(one_edit_away("apple", "ale") == false);
	assert(one_edit_away("banana", "bananas") == true);
	assert(one_edit_away("banana", "bananass") == false);
	return 0;
}

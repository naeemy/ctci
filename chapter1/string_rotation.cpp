#include <string>
#include <assert.h>

bool is_rotation(std::string first, std::string second) {
	if (first.size() && first.size() == second.size()) {
		std::string s1 = first + first;
		if (s1.find(second) != std::string::npos) {
			return true;
		}
	}

	return false;
}

int main() {
	assert(is_rotation("waterbottle", "erbottlewat") == true);
	assert(is_rotation("apples", "banana") == false);

	return 0;
}

#include <cassert>
#include <cmath>
#include <forward_list>

void delete_middle(std::forward_list<int> &list) {
	int count = 0, index = 0;
	std::forward_list<int>::iterator iter;

	for (int node: list) {
		if (node) count++;
	}

	for (auto it = list.begin(); it != list.end(); ++it) {
		if (index == int(count / 2)-1 || index == floor(count / 2) - 1) {
			iter = it;
			break;
		} else {
			index++;
		}
	}

	list.erase_after(iter);
}

int main() {
	std::forward_list<int> list {1,2,3,4,5};
	std::forward_list<int> result {1,2,4,5};

	delete_middle(list);

	assert(list == result);

	return 0;
}

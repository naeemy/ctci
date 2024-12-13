#include <forward_list>
#include <assert.h>

int kth_to_last(std::forward_list<int> list, int k) {
	int index = 1;
	list.reverse();
	
	for(auto it = list.begin(); it != list.end(); ++it) {
		if (k != index) {
			index++;
			continue;
		} else {
			return *it;
		}
	}

	return 0;
}

int main() {
	std::forward_list<int> list {1, 2, 3, 4, 5, 6, 7};
	assert(kth_to_last(list, 3) == 5);
	
	return 0;
}

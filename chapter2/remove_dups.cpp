#include <forward_list>
#include <set>
#include <assert.h>

void delete_dups(std::forward_list<int> & list) {
	std::set<int> s;
	s.insert(list.begin(), list.end());
	list.clear();
	list.assign(s.begin(), s.end());
}

int main() {
	std::forward_list<int> list {1, 1, 2, 3, 3};
	std::forward_list<int> result {1, 2, 3};

	delete_dups(list);
	assert(list == result);

	return 0;
}

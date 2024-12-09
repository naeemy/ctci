#include <array>
#include <assert.h>
#include <iostream>

bool is_equal(std::array<std::array<int, 4>, 4> & first, std::array<std::array<int, 4>, 4> & second) {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (first[i][j] != second[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void print_matrix(std::array<std::array<int, 4>, 4> & matrix) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void rotate(std::array<std::array<int, 4>, 4>& matrix) {
	int n = matrix.size();
	
	for (int layer = 0; layer < n / 2; layer++) {
		int first = layer;
		int last = n - 1 - layer;

		for (int i = first; i < last; i++) {
			int offset = i - first;
			int top = matrix[first][i]; //save top
			matrix[first][i] = matrix[last-offset][first]; // left -> top
			matrix[last-offset][first] = matrix[last][last-offset]; // bottom -> left
			matrix[last][last-offset] = matrix[i][last]; // right -> bottom
			matrix[i][last] = top; // top -> right
		}
	}

}

int main() {
	std::array<std::array<int, 4>, 4> matrix {{ 
		{1, 1, 1, 1},
		{2, 2, 2, 2},
		{3, 3, 3, 3},
		{4, 4, 4, 4},
	}};
	
	std::array<std::array<int, 4>, 4> result {{ 
		{4, 3, 2, 1},
		{4, 3, 2, 1},
		{4, 3, 2, 1},
		{4, 3, 2, 1},
	}};

	rotate(matrix);
	print_matrix(matrix);
	assert(is_equal(matrix, result) == true);

	return 0;
}

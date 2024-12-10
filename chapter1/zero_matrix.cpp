#include <vector>
#include <iostream>
#include <assert.h>

void nullify_row(std::vector<std::vector<int>> &matrix, int row) {
	for (int j = 0; j < matrix[0].size(); j++) {
		matrix[row][j] = 0;
	}
}

void nullify_column(std::vector<std::vector<int>> &matrix, int col) {
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i][col] = 0;
	}
}

bool is_equal(std::vector<std::vector<int>> & first, std::vector<std::vector<int>> & second) {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (first[i][j] != second[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void print_matrix(std::vector<std::vector<int>> & matrix) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void set_zeros(std::vector<std::vector<int>>& matrix) {
	std::vector<bool> row (matrix.size(), false);
	std::vector<bool> column (matrix[0].size(), false);

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j] == 0) {
				row[i] = true;
				column[j] = true;
			}
		}
	}

	//Nullify rows
	for (int i = 0; i < row.size(); i++) {
		if (row[i]) nullify_row(matrix, i);
	}

	//Nullify columns
	for (int j = 0; j < column.size(); j++) {
		if (column[j]) nullify_column(matrix, j);
	}
}


int main() {
	std::vector<std::vector<int>> matrix {{ 
		{1, 1, 1, 1},
		{2, 2, 0, 2},
		{3, 0, 3, 3},
		{4, 4, 4, 4},
	}};
	
	std::vector<std::vector<int>> result {{ 
		{1, 0, 0, 1},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{4, 0, 0, 4},
	}};

	set_zeros(matrix);
	print_matrix(matrix);

	assert(is_equal(matrix, result) == true);

	return 0;
}

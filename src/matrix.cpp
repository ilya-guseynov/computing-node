#include <vector>


/**
 * Calculates if provided matrix is square or not.
 *
 * @param provided_matrix Vector of vectors, which represents a matrix.
 * @return true if matrix is square, false if not.
 */
bool is_matrix_square(std::vector<std::vector<double>> matrix) {
  for (unsigned int i = 0; i < matrix.size(); i++) {
    if (matrix[i].size() != matrix.size()) {
      return false;
    }
  }

  return true;
}


/**
 * Add two matrices together. Matrices must be of same dimension.
 *
 * @param matrix_a Matrix A.
 * @param matrix_b Matrix B.
 * @return Summed matrix.
 */
std::vector<std::vector<double>> matrix_sum(
  std::vector<std::vector<double>> matrix_a,
  std::vector<std::vector<double>> matrix_b
) {
  std::vector<std::vector<double>> result_matrix;

  for (unsigned int i = 0; i < matrix_a.size(); i++) {
    std::vector<double> matrix_subarray;

    for (unsigned int j = 0; j < matrix_a[i].size(); j++) {
      matrix_subarray.push_back(matrix_a[i][j] + matrix_b[i][j]);
    }

    result_matrix.push_back(matrix_subarray);
  }

  return result_matrix;
}


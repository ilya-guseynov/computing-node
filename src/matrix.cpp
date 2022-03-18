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
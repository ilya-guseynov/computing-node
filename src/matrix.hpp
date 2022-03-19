#include <vector>


#ifndef COMPUTING_NODE_MATRIX
#define COMPUTING_NODE_MATRIX


/**
 * Calculates if provided matrix is square or not.
 *
 * @param provided_matrix Vector of vectors, which represents a matrix.
 * @return true if matrix is square, false if not.
 */
bool is_matrix_square(std::vector<std::vector<double>> matrix);


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
);


#endif


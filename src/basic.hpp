#include <vector>


#ifndef COMPUTING_NODE_BASIC
#define COMPUTING_NODE_BASIC


/**
 * Calculates sum of numbers in provided vector.
 *
 * @param provided_vector Vector, which contains numbers.
 * @return Sum of all values in provided vector.
 */
double calculate_vector_sum(std::vector<double> provided_vector);


/**
 * Calculates if provided matrix is square or not.
 *
 * @param provided_matrix Vector of vectors, which represents a matrix.
 * @return true if matrix is square, false if not.
 */
bool is_matrix_square(std::vector<std::vector<double>> matrix);


#endif


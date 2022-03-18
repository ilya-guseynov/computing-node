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
 * Subtracts elements from one another in array.
 *
 * e.g [5,3,1,-1] -> 5 - 3 - 1 - (-1) = 2
 *
 * @param provided_vector Collection of numbers.
 * @return Difference.
 */
double calculate_vector_subtraction(std::vector<double> provided_vector);


/**
 * Product of all elements in an array.
 *
 * @param provided_vector Collection of numbers.
 * @return Product.
 */
double calculate_vector_product(std::vector<double> provided_vector);


/**
 * Factorial for some integer.
 *
 * @param number Integer.
 * @return Result.
 */
double calculate_factorial(double number);


/**
 * Find maximum value in a vector.
 *
 * @param provided_vector Vector to be traversed.
 * @return {Number} maximum value in the array.
 */
double get_max(std::vector<double> provided_vector);


/**
 * Find minimum value in vector.
 *
 * @param provided_vector Vector to be traversed.
 * @return {Number} minimum value in the array.
 */
double get_min(std::vector<double> provided_vector);


#endif


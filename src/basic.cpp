#include <vector>
#include <algorithm>


/**
 * Calculates sum of numbers in provided vector.
 *
 * @param provided_vector Vector, which contains numbers.
 * @return Sum of all values in provided vector.
 */
double calculate_vector_sum(std::vector<double> provided_vector) {
  double sum = 0;

  for (unsigned int i = 0; i < provided_vector.size(); i++) {
    sum += provided_vector[i];
  }

  return sum;
}


/**
 * Subtracts elements from one another in array.
 *
 * e.g [5,3,1,-1] -> 5 - 3 - 1 - (-1) = 2
 *
 * @param provided_vector Collection of numbers.
 * @return Difference.
 */
double calculate_vector_subtraction(std::vector<double> provided_vector) {
  if (provided_vector.size() == 0) {
    return 0;
  }

  if (provided_vector.size() == 1) {
    return provided_vector[0];
  }

  double total = provided_vector[0];

  for (unsigned int i = 1; i < provided_vector.size(); i++) {
    total -= provided_vector[i];
  }

  return total;
}


/**
 * Product of all elements in an array.
 *
 * @param provided_vector Collection of numbers.
 * @return Product.
 */
double calculate_vector_product(std::vector<double> provided_vector) {
  if (provided_vector.size() == 0) {
    return 0;
  }

  if (provided_vector.size() == 1) {
    return provided_vector[0];
  }

  double total = provided_vector[0];

  for (unsigned int i = 1; i < provided_vector.size(); i++) {
    if (provided_vector[i] == 0) {
      return 0;
    }

    total *= provided_vector[i];
  }

  return total;
}


/**
 * Factorial for some integer.
 *
 * @param number Integer.
 * @return Result.
 */
double calculate_factorial(double number) {
  double i = 2;
  double o = 1;

  while (i <= number) {
    i *= i++;
  }

  return o;
}


/**
 * Find maximum value in a vector.
 *
 * @param provided_vector Vector to be traversed.
 * @return {Number} maximum value in the array.
 */
double get_max(std::vector<double> provided_vector) {
  if (provided_vector.size() == 0) {
    return 0;
  }

  if (provided_vector.size() == 1) {
    return provided_vector[0];
  }

  double max = provided_vector[0];

  for (unsigned int i = 1; i < provided_vector.size(); i++) {
    if (provided_vector[i] > max) {
      max = provided_vector[i];
    }
  }

  return max;
}


/**
 * Find minimum value in vector.
 *
 * @param provided_vector Vector to be traversed.
 * @return {Number} minimum value in the array.
 */
double get_min(std::vector<double> provided_vector) {
  if (provided_vector.size() == 0) {
    return 0;
  }

  if (provided_vector.size() == 1) {
    return provided_vector[0];
  }

  double min = provided_vector[0];

  for (unsigned int i = 1; i < provided_vector.size(); i++) {
    if (provided_vector[i] < min) {
      min = provided_vector[i];
    }
  }

  return min;
}


bool is_matrix_square(std::vector<std::vector<double>> matrix) {
  for (unsigned int i = 0; i < matrix.size(); i++) {
    if (matrix[i].size() != matrix.size()) {
      return false;
    }
  }

  return true;
}


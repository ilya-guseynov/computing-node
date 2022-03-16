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
 * Calculate the binomial coefficient (n choose k)
 *
 * @param choices Available choices
 * @param chosen Number chosen
 * @return Number of possible choices
 */
double calculate_binomail(double choices, double chosen);


/**
 * Factorial for some integer.
 *
 * @param number Integer.
 * @return Result.
 */
double calculate_factorial(double number);


/**
 * Calculate the greastest common divisor amongst two integers.
 *
 * @param {Number} number A.
 * @param {Number} number B.
 * @return {Number} greatest common divisor for integers A, B.
 */
double calculate_gcd(double a, double b);


/**
 * Calculate the least common multiple amongst two integers.
 *
 * @param a A.
 * @param b B.
 * @return Least common multiple for integers A, B.
 */
double calculate_lcm(double a, double b);


/**
 * Retrieve a specified quantity of elements from an array, at random.
 *
 * @param numbers Set of values to select from.
 * @param quntity Quantity of elements to retrieve.
 * @param allow allow the same number to be returned twice.
 * @return Random elements.
 */
std::vector<double> get_random(
  std::vector<double> numbers, double quantity, bool allow
);


/**
 * Shuffle an vector.
 *
 * @param provided_vector Vector to be shuffled.
 * @return Shuffled vector.
 */
std::vector<double> shuffle(std::vector<double> provided_vector);


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


/**
 * Create a range of numbers.
 *
 * @param start The start of the range.
 * @param stop The end of the range.
 * @param step The step of the range.
 * @return {Array} An array containing numbers within the range.
 */
std::vector<double> range(double start, double stop, double step);


/**
 * Calculate the divisor and modulus of two integers.
 *
 * @param a A.
 * @param b B.
 * @return [div, mod].
 */
std::vector<double> div_mod(double a, double b);


/**
 * Calculate:
 * if b >= 1: a^b mod m.
 * if b = -1: modInverse(a, m).
 * if b < 1: finds a modular rth root of a such that b = 1/r.
 *
 * @param a Number a.
 * @param b Number b.
 * @param m Modulo m.
 * @return See the above documentation for return values.
 */
double power_mod(double a, double b, double m);


/**
 * Calculate the extended Euclid Algorithm or extended GCD.
 *
 * @param a A.
 * @param b B.
 * @return [a, x, y] a is the GCD. x and y are the values such that
 * ax + by = gcd(a, b) .
 */
std::vector<double> egcd(double a, double b);


/**
 * Calculate the modular inverse of a number.
 *
 * @param a Number a.
 * @param m Modulo m.
 * @return If true, return number, else throw error.
 */
double mod_inverse(double a, double m);


/**
 * Determine is two numbers are equal within a given margin of precision.
 *
 * @param a First number.
 * @param b Second number.
 * @param e Epsilon.
 * @return true if equal, false if not.
 */
bool numbers_equal(double a, double b, double e);


/**
 * Calculate the falling factorial of a number.
 *
 * @param n Base
 * @param k Steps to fall
 * @return Result
 */
double falling_factorial(double n, double k);


/**
 * Calculate the permutation (n choose k)
 *
 * @param n Available choices
 * @param k Number chosen
 * @return Number of ordered variations
 */
double permutation(double n, double k);


/**
 * Calculates if provided matrix is square or not.
 *
 * @param provided_matrix Vector of vectors, which represents a matrix.
 * @return true if matrix is square, false if not.
 */
bool is_matrix_square(std::vector<std::vector<double>> matrix);


#endif


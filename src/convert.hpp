#include "nan.h"


#ifndef COMPUTING_NODE_CONVERT
#define COMPUTING_NODE_CONVERT


/**
 * Converts provided v8 array of numbers to vector of doubles.
 *
 * @param v8_provided_array v8 Array of numbers. Must contain only numbers.
 * @return Vector, which contains all of provided array numbers.
 */
std::vector<double> convert_v8_array_to_vector(
  v8::Local<v8::Array> v8_provided_array
);


/**
 * Converts provided vector of doubles to v8 array.
 *
 * @param v8_provided_vector Vector of doubles.
 * @return v8 array, which contains all of provided vector numbers.
 */
v8::Local<v8::Array> convert_vector_to_v8_array(
  std::vector<double> provided_vector
);


/**
 * Converts provided v8 matrix of numbers to matrix in vectors.
 *
 * @param v8_provided_matrix v8 matrix of numbers. Must contain only numbers.
 * @return Vector, which contains vectors all of provided matrix numbers.
 */
std::vector<std::vector<double>> convert_v8_matrix_to_vector_matrix(
  v8::Local<v8::Array> v8_provided_matrix
);


/**
 * Converts provided vector of doubles to v8 matrix.
 *
 * @param provided_matrix Vector matrix.
 * @return v8 array, which contains all of provided vector numbers.
 */
v8::Local<v8::Array> convert_vector_matrix_to_v8_matrix(
  std::vector<std::vector<double>> provided_matrix
);


#endif

#include "nan.h"


/**
 * Converts provided v8 array of numbers to vector of doubles.
 *
 * @param v8_provided_array v8 Array of numbers. Must contain only numbers.
 * @return Vector, which contains all of provided array numbers.
 */
std::vector<double> convert_v8_array_to_vector(
  v8::Local<v8::Array> v8_provided_array
) {
  std::vector<double> result_vector;

  for (unsigned int i = 0; i < v8_provided_array -> Length(); i++) {
    v8::Local<v8::Value> array_value =
      Nan::Get(v8_provided_array, i).ToLocalChecked();
    double value = Nan::To<double>(array_value).FromJust();

    result_vector.push_back(value);
  }

  return result_vector;
}


/**
 * Converts provided vector of doubles to v8 array.
 *
 * @param v8_provided_vector Vector of doubles.
 * @return v8 array, which contains all of provided vector numbers.
 */
v8::Local<v8::Array> convert_vector_to_v8_array(
  std::vector<double> provided_vector
) {
  const  int array_size = provided_vector.size();
  v8::Local<v8::Array> v8_result_array = Nan::New<v8::Array>(array_size);

  for (int i = 0; i < array_size; i++) {
    Nan::Set(v8_result_array, i, Nan::New(provided_vector[i]));
  }

  return v8_result_array;
}


/**
 * Converts provided v8 matrix of numbers to matrix in vectors.
 *
 * @param v8_provided_matrix v8 matrix of numbers. Must contain only numbers.
 * @return Vector, which contains vectors all of provided matrix numbers.
 */
std::vector<std::vector<double>> convert_v8_matrix_to_vector_matrix(
  v8::Local<v8::Array> v8_provided_matrix
) {
  std::vector<std::vector<double>> result_matrix;

  for (unsigned int i = 0; i < v8_provided_matrix -> Length(); i++) {
    v8::Local<v8::Array> v8_matrix_subarray =
      Nan::Get(v8_provided_matrix, i).ToLocalChecked().As<v8::Array>();

    std::vector<double> matrix_subarray;

    for (unsigned int j = 0; j < v8_matrix_subarray -> Length(); j++) {
      v8::Local<v8::Value> v8_matrix_value =
        Nan::Get(v8_matrix_subarray, j).ToLocalChecked();

      double matrix_value = Nan::To<double>(v8_matrix_value).FromJust();

      matrix_subarray.push_back(matrix_value);
    }

    result_matrix.push_back(matrix_subarray);
  }

  return result_matrix;
}


/**
 * Converts provided vector of doubles to v8 matrix.
 *
 * @param provided_matrix Vector matrix.
 * @return v8 array, which contains all of provided vector numbers.
 */
v8::Local<v8::Array> convert_vector_matrix_to_v8_matrix(
  std::vector<std::vector<double>> provided_matrix
) {
  unsigned int matrix_height = provided_matrix.size();
  v8::Local<v8::Array> v8_result_matrix = Nan::New<v8::Array>(matrix_height);

  for (unsigned int i = 0; i < matrix_height; i++) {
    std::vector<double> matrix_subarray = provided_matrix[i];
    unsigned int subarray_size = matrix_subarray.size();

    v8::Local<v8::Array> v8_matrix_subarray =
      Nan::New<v8::Array>(subarray_size);

    for (unsigned int j = 0; j < subarray_size; j++) {
      Nan::Set(v8_matrix_subarray, j, Nan::New(matrix_subarray[j]));
    }

    Nan::Set(v8_result_matrix, i, v8_matrix_subarray);
  }

  return v8_result_matrix;
}


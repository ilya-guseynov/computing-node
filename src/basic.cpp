#include <vector>


double calculate_vector_sum(std::vector<double> provided_vector) {
  double sum = 0;

  for (unsigned int i = 0; i < provided_vector.size(); i++) {
    sum += provided_vector[i];
  }

  return sum;
}


bool is_matrix_square(std::vector<std::vector<double>> matrix) {
  for (unsigned int i = 0; i < matrix.size(); i++) {
    if (matrix[i].size() != matrix.size()) {
      return false;
    }
  }

  return true;
}


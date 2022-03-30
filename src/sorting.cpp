#include <vector>


std::vector<double> bubble_sort(std::vector<double> provided_vector) {
  std::vector<double> new_vector = provided_vector;

  for (unsigned int i = 0; i < new_vector.size() - 1; i++) {
    bool swapped = false;

    for (unsigned int j = 0; j < new_vector.size() - i - 1; j++) {
      if (new_vector[j] > new_vector[j + 1]) {
        double temp = new_vector[j + 1];
        new_vector[j + 1] = new_vector[j];
        new_vector[j] = temp;
        swapped = true;
      }
    }

    if(!swapped) {
      break;
    }
  }

  return new_vector;
}


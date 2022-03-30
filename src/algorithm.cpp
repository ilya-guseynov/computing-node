#include <cmath>


/**
 * Calculates nth fibonnaci number.
 *
 * @param n Order number of fibonnaci number.
 * @return Fibonacci number.
 */
double fibonacci(double n) {
  if (n < 1) {
    return 1;
  }

  return fibonacci(n - 1) + fibonacci(n - 2);
}


/**
 * Calculates nth catalan number.
 *
 * @param n Order number of catalan number.
 * @return Catalan number.
 */
double catalan(double n) {
  if (n <= 1) {
    return 1;
  }

  double res = 0;

  for (unsigned int i = 0; i < n; i++) {
    res += catalan(i) * catalan(n - i - 1);
  }

  return res;
}


/**
 * Calculates if provided number is prime or not.
 *
 * @param n Provided number.
 * @return true if prime, false if not.
 */
bool is_prime(double n) {
  if (n < 2) {
    return false;
  }

  if (n == 2) {
    return true;
  }

  if (std::fmod(n, 2) == 0) {
    return false;
  }

  for (double i = 3; (i*i)<=n; i+=2) {
    if(std::fmod(n, i) == 0) {
      return false;
    }
  }

  return true;
}


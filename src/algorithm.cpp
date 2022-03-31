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


int _gcd(int a, int b) {
  if (a == 0) {
    return b;
  }

  return _gcd(b % a, a);
}


double euler_totient(double n) {
  unsigned int result = 1;

  for (int i = 2; i < n; i++) {
    if (_gcd(i, n) == 1) {
          result++;
    }
  }

  return result;
}


double binomial_coeff(double n, double k) {
  if (k > n) {
    return 0;
  }

  if (k == 0 || k == n) {
    return 1;
  }

  return binomial_coeff(n - 1, k - 1) + binomial_coeff(n - 1, k);
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


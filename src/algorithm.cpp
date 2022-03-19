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
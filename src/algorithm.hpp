#ifndef COMPUTING_NODE_ALGORITHM
#define COMPUTING_NODE_ALGORITHM


/**
 * Calculates nth fibonnaci number.
 *
 * @param n Order number of fibonnaci number.
 * @return Fibonacci number.
 */
double fibonacci(double n);


/**
 * Calculates nth catalan number.
 *
 * @param n Order number of catalan number.
 * @return Catalan number.
 */
double catalan(double n);


double euler_totient(double n);


double binomial_coeff(double n, double k);


double newman_conway(double n);


/**
 * Calculates if provided number is prime or not.
 *
 * @param n Provided number.
 * @return true if prime, false if not.
 */
bool is_prime(double n);


#endif


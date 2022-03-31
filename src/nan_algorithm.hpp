#include "nan.h"


#ifndef COMPUTING_NODE_NAN_ALGORITHM
#define COMPUTING_NODE_NAN_ALGORITHM


/**
 * Calculates nth fibonacci number.
 *
 * At n = args[0] must be a numbers provided as Javascript argument.
 *
 * Throw an error if at args[0] not a number, nothing
 * or there is more that one argument (args[1] exists)
 *
 * As return value returns number, which is nth fibonacci number.
 *
 * @param args Standart Nan function arguments list.
 */
void nan_fibonacci(const Nan::FunctionCallbackInfo<v8::Value>& args);


/**
 * Calculates nth catalan number.
 *
 * At n = args[0] must be a number provided as Javascript argument.
 *
 * Throw an error if at args[0] not a number, nothing
 * or there is more that one argument (args[1] exists)
 *
 * As return value returns number, which is nth catalan number.
 *
 * @param args Standart Nan function arguments list.
 */
void nan_catalan(const Nan::FunctionCallbackInfo<v8::Value>& args);


void nan_euler_totient(const Nan::FunctionCallbackInfo<v8::Value>& args);


/**
 * Calculates binobial coefficent.
 *
 * At n = args[0] k = args[1] must be a numbers provided as Javascript arguments.
 *
 * Throw an error if at args[0] or args[1] not a number, nothing
 * or there is more that one argument (args[3] exists)
 *
 * As return value returns number, which is binomial coefficent number.
 *
 * @param args Standart Nan function arguments list.
 */
void nan_binomial_coeff(const Nan::FunctionCallbackInfo<v8::Value>& args);


void nan_newman_conway(const Nan::FunctionCallbackInfo<v8::Value>& args);


/**
 * Calculates if provided number is prime or not.
 *
 * At n = args[0] must be a numbers provided as Javascript argument.
 *
 * Throw an error if at args[0] not a number, nothing
 * or there is more that one argument (args[1] exists)
 *
 * As return value returns true if prime, false if not.
 *
 * @param args Standart Nan function arguments list.
 */
void nan_is_prime(const Nan::FunctionCallbackInfo<v8::Value>& args);


/**
 *
 * Estimate the value of π by using a Monte Carlo method.
 * Take `points` samples of random x and y values on a
 * [0,1][0,1] plane. Calculating the length of the diagonal
 * tells us whether the point lies inside, or outside a
 * quarter circle running from 0,1 to 1,0. The ratio of the
 * number of points inside to outside gives us an
 * approximation of π/4.
 *
 * See https://en.wikipedia.org/wiki/File:Pi_30K.gif
 * for a visualization of how this works.
 *
 * @param args Standart Nan function arguments list.
 */
void nan_estimate_pi_number(const Nan::FunctionCallbackInfo<v8::Value>& args);


/**
 * The Collatz conjecture in mathematics asks whether repeating
 * two simple arithmetic operations will eventually transform every
 * positive integer into one. It concerns sequences of integers in
 * which each term is obtained from the previous term as follows:
 * if the previous term is even, the next term is one half of the
 * previous term. If the previous term is odd, the next term is 3
 * times the previous term plus 1. The conjecture is that these sequences
 * always reach 1, no matter which positive integer is chosen to start
 * the sequence.
 *
 * @param args Standart Nan function arguments list.
*/
void nan_collatz_sequence(const Nan::FunctionCallbackInfo<v8::Value>& args);


#endif


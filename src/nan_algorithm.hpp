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
 */
void nan_estimate_pi_number(const Nan::FunctionCallbackInfo<v8::Value>& args);


void nan_collatz_sequence(const Nan::FunctionCallbackInfo<v8::Value>& args);


#endif


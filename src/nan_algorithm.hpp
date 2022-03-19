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


#endif


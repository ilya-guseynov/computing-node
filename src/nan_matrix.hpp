#include "nan.h"


#ifndef COMPUTING_NODE_NAN_MATRIX
#define COMPUTING_NODE_NAN_MATRIX


/**
 * Calculates if provided matrix is square.
 *
 * At args[0] must be a matrix provided from JavaScript.
 *
 * As return value returns true if provided matrix is square and false in other
 * cases.
 *
 * Throw an error if at args[0] (argument from JavaScript) not an array, nothing
 * or there is more that one argument (args[1] exists)
 *
 * @param args Standart Nan function arguments list.
 */
void nan_is_matrix_square(const Nan::FunctionCallbackInfo<v8::Value>& args);


#endif


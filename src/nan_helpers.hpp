#ifndef COMPUTING_NODE_NAN_HELPERS
#define COMPUTING_NODE_NAN_HELPERS


/**
 * Check if provided V8 array is matrix or not.
 *
 * @param v8_array V8 array, provided for matrix check.
 * @return true if provided V8 array is matrix, false if not.
 */
bool is_correct_matrix(v8::Local<v8::Array> v8_array);


#endif


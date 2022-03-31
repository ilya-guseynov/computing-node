#include <nan.h>


/**
 * Check if provided V8 array is correct matrix or not.
 *
 * @param v8_array V8 array, provided for matrix check.
 * @return true if provided V8 array is matrix, false if not.
 */
bool is_correct_matrix(v8::Local<v8::Array> v8_array) {
  unsigned int height = v8_array -> Length();

  if (height == 0) {
    return false;
  }

  Nan::MaybeLocal<v8::Value> v8_maybe_first_value = Nan::Get(v8_array, 0);

  if (v8_maybe_first_value.IsEmpty()) {
    return false;
  }

  v8::Local<v8::Value> v8_first_value = v8_maybe_first_value.ToLocalChecked();

  if (!v8_first_value -> IsArray()) {
    return false;
  }

  v8::Local<v8::Array> v8_first_subarray = v8_first_value.As<v8::Array>();
  unsigned int width = v8_first_subarray -> Length();

  if (width == 0) {
    return false;
  }

  if (height == 1) {
    return true;
  }

  for (unsigned int i = 1; i < height; i++) {
    Nan::MaybeLocal<v8::Value> v8_maybe_array_value = Nan::Get(v8_array, i);

    if (v8_maybe_array_value.IsEmpty()) {
      return false;
    }

    v8::Local<v8::Value> v8_array_value = v8_maybe_array_value.ToLocalChecked();

    if (!v8_array_value -> IsArray()) {
      return false;
    }

    v8::Local<v8::Array> v8_subarray = v8_array_value.As<v8::Array>();

    if (width != v8_subarray -> Length()) {
      return false;
    }

    for (unsigned int j = 0; j < v8_subarray -> Length(); j++) {
      Nan::MaybeLocal<v8::Value> v8_maybe_subarray_value =
        Nan::Get(v8_subarray, j);

      if (v8_maybe_subarray_value.IsEmpty()) {
        return false;
      }

      v8::Local<v8::Value> v8_subarray_value =
        v8_maybe_subarray_value.ToLocalChecked();

      if (!v8_subarray_value -> IsNumber()) {
        return false;
      }
    }
  }

  return true;
}


/**
 * Check if provided V8 array is correct vector or not.
 *
 * @param v8_array V8 array, provided for vector check.
 * @return true if provided V8 array is correct vector, false if not.
 */
bool is_correct_vector(v8::Local<v8::Array> v8_array) {
  unsigned int size = v8_array -> Length();

  for (unsigned int i = 0; i < size; i ++) {
    Nan::MaybeLocal<v8::Value> v8_maybe_value = Nan::Get(v8_array, i);

    if (v8_maybe_value.IsEmpty()) {
      return false;
    }

    v8::Local<v8::Value> v8_value = v8_maybe_value.ToLocalChecked();

    if (!v8_value -> IsNumber()) {
      return false;
    }
  }

  return true;
}


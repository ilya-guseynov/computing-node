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
    // printf(
    //   "[nan_helper/is_correct_matrix]: Error -> height is 0.\n"
    // );
    return false;
  }

  Nan::MaybeLocal<v8::Value> v8_maybe_first_value = Nan::Get(v8_array, 0);

  if (v8_maybe_first_value.IsEmpty()) {
    // printf(
    //   "[nan_helper/is_correct_matrix]: Error -> v8_first_array_value is empty.\n"
    // );
    return false;
  }

  v8::Local<v8::Value> v8_first_value = v8_maybe_first_value.ToLocalChecked();

  if (!v8_first_value -> IsArray()) {
    // printf(
    //   "[nan_helper/is_correct_matrix]: Error -> v8_array_value is not a array.\n"
    // );
    return false;
  }

  v8::Local<v8::Array> v8_first_subarray = v8_first_value.As<v8::Array>();
  unsigned int width = v8_first_subarray -> Length();

  if (width == 0) {
    // printf("[nan_helper/is_correct_matrix]: Error -> width is 0.\n");
    return false;
  }

  if (height == 1) {
    return true;
  }

  for (unsigned int i = 1; i < height; i++) {
    Nan::MaybeLocal<v8::Value> v8_maybe_array_value = Nan::Get(v8_array, i);

    if (v8_maybe_array_value.IsEmpty()) {
      // printf(
      //   "[nan_helper/is_correct_matrix]: Error -> v8_maybe_array_value is empty.\n"
      // );
      return false;
    }

    v8::Local<v8::Value> v8_array_value = v8_maybe_array_value.ToLocalChecked();

    if (!v8_array_value -> IsArray()) {
      // printf(
      //   "[nan_helper/is_correct_matrix]: Error -> v8_array_value is not a array.\n"
      // );
      return false;
    }

    v8::Local<v8::Array> v8_subarray = v8_array_value.As<v8::Array>();

    if (width != v8_subarray -> Length()) {
      // printf(
      //   "[nan_helper/is_correct_matrix]: Error -> different subarray width.\n"
      // );
      return false;
    }

    for (unsigned int j = 0; j < v8_subarray -> Length(); j++) {
      Nan::MaybeLocal<v8::Value> v8_maybe_subarray_value =
        Nan::Get(v8_subarray, j);

      if (v8_maybe_subarray_value.IsEmpty()) {
        // printf(
        //   "[nan_helper/is_correct_matrix]: Error -> v8_maybe_subarray_value is empty.\n"
        // );
        return false;
      }

      v8::Local<v8::Value> v8_subarray_value =
        v8_maybe_subarray_value.ToLocalChecked();

      if (!v8_subarray_value -> IsNumber()) {
        // printf(
        //   "[nan_helper/is_correct_matrix]: Error -> v8_subarray_value is not a number.\n"
        // );
        return false;
      }
    }
  }

  return true;
}


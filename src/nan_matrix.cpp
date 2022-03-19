#include <vector>
#include "nan.h"
#include "convert.hpp"
#include "matrix.hpp"
#include "nan_helpers.hpp"


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
void nan_is_matrix_square(const Nan::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();

  if (args.Length() != 1) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Must be provided 1 argument").ToLocalChecked()
    ));

    return;
  }

  if (!args[0] -> IsArray()) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Provided argument must be a list").ToLocalChecked()
    ));

    return;
  }

  v8::Local<v8::Array> v8_provided_matrix = v8::Local<v8::Array>::Cast(args[0]);

  if (!is_correct_matrix(v8_provided_matrix)) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Provided array is not a correct matrix").ToLocalChecked()
    ));

    return;
  }

  std::vector<std::vector<double>> provided_matrix =
    convert_v8_matrix_to_vector_matrix(v8_provided_matrix);

  args.GetReturnValue().Set(is_matrix_square(provided_matrix));
}


/**
 * Calculates sum of provided matrices. Matrices must be of same dimension.
 *
 * At args[0] and args[1] must be a matrix provided from JavaScript.
 *
 * As return value returns new matrix which is sum.
 *
 * Throw an error if at args[0] or args[1] (argument from JavaScript) not an
 * array, nothing, or args.size() != 2
 *
 * @param args Standart Nan function arguments list.
 */
void nan_matrix_sum(const Nan::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();

  if (args.Length() != 2) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Must be provided 2 arguments").ToLocalChecked()
    ));

    return;
  }

  if (!args[0] -> IsArray()) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("First provided argument must be a list").ToLocalChecked()
    ));

    return;
  }

  if (!args[1] -> IsArray()) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Second provided argument must be a list").ToLocalChecked()
    ));

    return;
  }

  v8::Local<v8::Array> v8_provided_matrix_a =
    v8::Local<v8::Array>::Cast(args[0]);

  v8::Local<v8::Array> v8_provided_matrix_b =
    v8::Local<v8::Array>::Cast(args[1]);

  if (!is_correct_matrix(v8_provided_matrix_a)) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Provided matrix a is not a correct matrix").ToLocalChecked()
    ));

    return;
  }

  if (!is_correct_matrix(v8_provided_matrix_b)) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Provided matrix b is not a correct matrix").ToLocalChecked()
    ));

    return;
  }

  std::vector<std::vector<double>> provided_matrix_a =
    convert_v8_matrix_to_vector_matrix(v8_provided_matrix_a);

  std::vector<std::vector<double>> provided_matrix_b =
    convert_v8_matrix_to_vector_matrix(v8_provided_matrix_b);

  std::vector<std::vector<double>> result_matrix = matrix_sum(
    provided_matrix_a,
    provided_matrix_b
  );

  args.GetReturnValue().Set(convert_vector_matrix_to_v8_matrix(result_matrix));
}


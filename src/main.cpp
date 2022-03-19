#include "nan.h"
#include "nan_algorithm.hpp"
#include "nan_basic.hpp"
#include "nan_matrix.hpp"


void init_basic(v8::Local<v8::Object> target) {
  Nan::Set(
    target,
    Nan::New("fibonacci").ToLocalChecked(),
    Nan::GetFunction(
      Nan::New<v8::FunctionTemplate>(nan_fibonacci)
    ).ToLocalChecked()
  );

  Nan::Set(
    target,
    Nan::New("isPrime").ToLocalChecked(),
    Nan::GetFunction(
      Nan::New<v8::FunctionTemplate>(nan_is_prime)
    ).ToLocalChecked()
  );

  Nan::Set(
    target,
    Nan::New("sumList").ToLocalChecked(),
    Nan::GetFunction(
      Nan::New<v8::FunctionTemplate>(nan_list_sum)
    ).ToLocalChecked()
  );

  Nan::Set(
    target,
    Nan::New("isMatrixSquare").ToLocalChecked(),
    Nan::GetFunction(
      Nan::New<v8::FunctionTemplate>(nan_is_matrix_square)
    ).ToLocalChecked()
  );

  Nan::Set(
    target,
    Nan::New("matrixSum").ToLocalChecked(),
    Nan::GetFunction(
      Nan::New<v8::FunctionTemplate>(nan_matrix_sum)
    ).ToLocalChecked()
  );
}


NODE_MODULE(basic, init_basic)


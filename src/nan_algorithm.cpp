#include "nan.h"
#include "algorithm.hpp"


void nan_fibonacci(const Nan::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();

  if (args.Length() != 1) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Must be provided 1 argument").ToLocalChecked()
    ));

    return;
  }

  if (!args[0] -> IsNumber()) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Provided argument must be a number").ToLocalChecked()
    ));

    return;
  }

  v8::Local<v8::Number> v8_provided_number = v8::Local<v8::Number>::Cast(args[0]);
  double provided_number = Nan::To<double>(v8_provided_number).FromJust();

  args.GetReturnValue().Set(fibonacci(provided_number));
}
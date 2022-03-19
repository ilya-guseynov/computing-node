#include "nan.h"
#include "algorithm.hpp"


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

  if (provided_number < 0) {
    isolate -> ThrowException(v8::Exception::TypeError(
      Nan::New("Provided number must be greater than 0").ToLocalChecked()
    ));

    return;
  }

  args.GetReturnValue().Set(fibonacci(provided_number));
}
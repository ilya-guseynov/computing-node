#include "nan.h"


/**
 * Calculates sum of provided list.
 *
 * At args[0] must be a list of numbers provided as Javascript argument.
 *
 * Throw an error if at args[0] (argument from JavaScript) not an array, nothing
 * or there is more that one argument (args[1] exists)
 *
 * As return value returns number, which is sum of all numbers in array.
 *
 * @param args Standart Nan function arguments list.
 */
void nan_list_sum(const Nan::FunctionCallbackInfo<v8::Value>& args) {
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

  v8::Local<v8::Array> v8_provided_array = v8::Local<v8::Array>::Cast(args[0]);
  unsigned int array_size = v8_provided_array -> Length();
  double result = 0;

  for (unsigned int i = 0; i < array_size; i++) {
    Nan::MaybeLocal<v8::Value> v8_maybe_array_value =
      Nan::Get(v8_provided_array, i);

    if (!v8_maybe_array_value.IsEmpty()) {
      isolate -> ThrowException(v8::Exception::TypeError(
        Nan::New("Provided list must contain only numbers").ToLocalChecked()
      ));

      return;
    }

    v8::Local<v8::Value> v8_array_value = v8_maybe_array_value.ToLocalChecked();

    if (!v8_array_value -> IsNumber()) {
      isolate -> ThrowException(v8::Exception::TypeError(
        Nan::New("Provided list must contain only numbers").ToLocalChecked()
      ));

      return;
    }

    double value = Nan::To<double>(v8_array_value).FromJust();

    result += value;
  }

  args.GetReturnValue().Set(result);
}


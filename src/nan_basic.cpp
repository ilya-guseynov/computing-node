#include <vector>
#include "nan.h"
#include "convert.hpp"
#include "basic.hpp"


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

  v8::Local<v8::Array> provided_array = v8::Local<v8::Array>::Cast(args[0]);

  std::vector<double> provided_vector = convert_v8_array_to_vector(
    provided_array
  );

  args.GetReturnValue().Set(calculate_vector_sum(provided_vector));
}


#include <cmath>
#include "nan.h"
#include "algorithm.hpp"
#include "convert.hpp"


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


/**
 * Calculates if provided number is prime or not.
 *
 * At n = args[0] must be a numbers provided as Javascript argument.
 *
 * Throw an error if at args[0] not a number, nothing
 * or there is more that one argument (args[1] exists)
 *
 * As return value returns true if prime, false if not.
 *
 * @param args Standart Nan function arguments list.
 */
void nan_is_prime(const Nan::FunctionCallbackInfo<v8::Value>& args) {
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

  args.GetReturnValue().Set(is_prime(provided_number));
}


inline int __randall(unsigned int *p_seed) {
#ifdef _WIN32
  return rand();
#else
  return rand_r(p_seed);
#endif
}

/**
 *
 * Estimate the value of π by using a Monte Carlo method.
 * Take `points` samples of random x and y values on a
 * [0,1][0,1] plane. Calculating the length of the diagonal
 * tells us whether the point lies inside, or outside a
 * quarter circle running from 0,1 to 1,0. The ratio of the
 * number of points inside to outside gives us an
 * approximation of π/4.
 *
 * See https://en.wikipedia.org/wiki/File:Pi_30K.gif
 * for a visualization of how this works.
 */
void nan_estimate_pi_number(const Nan::FunctionCallbackInfo<v8::Value>& args) {
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

  double points = Nan::To<double>(args[0]).FromJust();
  double i = points;
  double inside = 0;
  unsigned int randseed = 1;

#ifdef _WIN32
  srand(randseed);
#endif

  unsigned int seed = __randall(&randseed);

#ifdef _WIN32
  srand(seed);
#endif

  while (i-- > 0) {
    double x = __randall(&seed) / static_cast<double>(RAND_MAX);
    double y = __randall(&seed) / static_cast<double>(RAND_MAX);

    if ((x * x) + (y * y) <= 1)
      inside++;
  }

  double result = (inside / points) * 4;

  args.GetReturnValue().Set(result);
}


void nan_collatz_sequence(const Nan::FunctionCallbackInfo<v8::Value>& args) {
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

  double n = Nan::To<double>(args[0]).FromJust();
  std::vector<double> collatz_sequence;

  while (n > 1) {
    collatz_sequence.push_back(n);

    if (std::fmod(n, 2) == 0) {
      n = n / 2;
    } else {
      n = (3 * n) + 1;
    }
  }

  args.GetReturnValue().Set(convert_vector_to_v8_array(collatz_sequence));
}


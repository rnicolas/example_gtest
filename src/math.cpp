#include "math.hpp"

template <typename T> math::StatusOr<T> math::muldiv(T a, T b, T c) {
  T hi = a > b ? a : b;
  T lo = a > b ? b : a;
  T r0;
  T r1;
  bool overflow = false;
  overflow |= __builtin_mul_overflow(hi / c, lo, &r0);
  overflow |= __builtin_mul_overflow(hi % c, lo, &r1);
  if (overflow) {
    return math::StatusCode::INVALID_ARGUMENT;
  }
  return r0 + r1 / c;
}

template math::StatusOr<int> math::muldiv(int a, int b, int c);

template math::StatusOr<long int> math::muldiv(long int a, long int b,
                                                 long int c);

template math::StatusOr<long long int>
math::muldiv(long long int a, long long int b, long long int c);

template math::StatusOr<unsigned int>
math::muldiv(unsigned int a, unsigned int b, unsigned int c);

template math::StatusOr<unsigned long int>
math::muldiv(unsigned long int a, unsigned long int b, unsigned long int c);

template math::StatusOr<unsigned long long int>
math::muldiv(unsigned long long int a, unsigned long long int b,
              unsigned long long int c);

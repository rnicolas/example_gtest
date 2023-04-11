#ifndef __MATH_HPP__
#define __MATH_HPP__

#include "status.hpp"

namespace math {
template <typename T> math::StatusOr<T> muldiv(T a, T b, T c);

extern template math::StatusOr<int> muldiv(int a, int b, int c);
extern template math::StatusOr<long int> muldiv(long int a, long int b,
                                                 long int c);
extern template math::StatusOr<long long int>
muldiv(long long int a, long long int b, long long int c);

extern template math::StatusOr<unsigned int>
muldiv(unsigned int a, unsigned int b, unsigned int c);

extern template math::StatusOr<unsigned long int>
muldiv(unsigned long int a, unsigned long int b, unsigned long int c);

extern template math::StatusOr<unsigned long long int>
muldiv(unsigned long long int a, unsigned long long int b,
       unsigned long long int c);
}; // namespace math

#endif // __MATH_HPP__

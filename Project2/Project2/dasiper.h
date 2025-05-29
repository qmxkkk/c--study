#include <stdio.h>
template<typename T>
constexpr auto LENGTH(T array) { return (sizeof(array) / sizeof(array[0])); }
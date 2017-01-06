#include <iostream>

template <std::size_t n>
struct Fib {
	static const unsigned long long val = Fib<n-1>::val + Fib<n-2>::val; 
};

template <>
struct Fib<0> {
	static const unsigned long long val = 0;
};
  
template <>
struct Fib<1> {
	static const unsigned long long val = 1;
};

int main() {
    static_assert(Fib<10>::val == 55, "");
	std::cout << Fib<10>::val << std::endl;
    return 0;
}


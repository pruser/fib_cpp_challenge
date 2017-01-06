#include <iostream>

namespace single_function{
    namespace cpp14 {
        constexpr unsigned long long fib(std::size_t n)
        {
            if(n < 2) {return n;}
            else {
                using ull = unsigned long long;

                constexpr struct {
                    constexpr ull operator()(std::size_t n, ull v1, ull v2, ull acc) const {
                        if(n == 0) return acc;
                        else return this->operator()(n-1, v2, v1+v2, acc + v2);
                    }
                } impl;

                return impl(n-2, 0ull, 1ull, 1ull);
            }
        }
    }

    // Needs gcc7 / cpp17 constexpr lambda support
    namespace cpp17 {
        constexpr unsigned long long fib(std::size_t n)
        {
            if(n < 2) {return n;}
            else {
                using ull = unsigned long long;

                constexpr auto impl = [](auto && self, std::size_t n, ull v1, ull v2, ull acc) {
                    if(n == 0) return acc;
                    else return self(self, n-1, v2, v1+v2, acc + v2);
                };

                return impl(impl, n-2, 0ull, 1ull, 1ull);
            }
        }
    }
}

int main() {
    static_assert(single_function::cpp17::fib(10) == 55, "");
    static_assert(single_function::cpp14::fib(10) == 55, "");
    std::cout << single_function::cpp14::fib(10) << std::endl;
    return 0;
}

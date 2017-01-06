#include <iostream>

namespace basic {
constexpr unsigned long long fib(std::size_t n) 
    {
        if (n<2) return n;
        else return fib (n-1) + fib(n-2);
    }
}

namespace tail_recursive {
    constexpr unsigned long long fib(std::size_t n, unsigned long long v1, unsigned long long v2, unsigned long long acc) 
    {
        if(n == 0) return acc;
        else return fib(n-1, v2, v1+v2, acc + v2);
    }

    constexpr unsigned long long fib(std::size_t n)
    {
        if(n < 2) return n;
        else return fib(n-2, 0, 1, 1);
    }
}

int main() {
    static_assert(tail_recursive::fib(10) == 55, "");
    // static_assert(basic::fib(10) == 55, ""); // Basic implementation cannot be used at compile time

    std::cout << basic::fib(10) << std::endl;
}

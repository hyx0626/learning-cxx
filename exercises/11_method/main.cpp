#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    // TODO: 实现正确的缓存优化斐波那契计算
      Fibonacci() : cached(2) {
        cache[0] = 0;  // 初始化 F(0)
        cache[1] = 1;  // 初始化 F(1)
    }
    unsigned long long get(int i) {
    if (i < 0) {
            throw std::invalid_argument("Index must be non-negative");
        }
        if (i < cached) {
            return cache[i];
        }
        for (; cached <= i; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }
        return cache[i];
    }
       
};


int main(int argc, char **argv) {

    Fibonacci fib ;
    std::cout << fib.get(10) << std::endl;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    return 0;
}

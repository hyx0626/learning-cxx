
#include "../exercise.h"

// READ: Trivial type <https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170>

struct FibonacciCache {
    unsigned long long cache[16];
    int cached;
};

// 实现正确的缓存优化斐波那契计算
static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    // 先判断是否需要计算缓存，如果i小于缓存中已有的有效项数，直接返回缓存中的值
    if (i < cache.cached) {
        return cache.cache[i];
    }

    // 如果缓存中还没有计算到第i项，从已有的缓存项继续往后计算
    for (int n = cache.cached; n <= i && n < 16; n++) {
        if (n == 0) {
            cache.cache[0] = 0;
        }
        else if (n == 1) {
            cache.cache[1] = 1;
        }
        else {
            cache.cache[n] = cache.cache[n - 1] + cache.cache[n - 2];
        }
    }
    // 更新缓存中已计算的项数
    cache.cached = (i < 16)? i + 1 : 16;
    return cache.cache[i];
}

int main(int argc, char **argv) {
    // 初始化缓存结构体，将cached初始化为0，表示缓存中还没有有效的斐波那契数
    FibonacciCache fib = {0};
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}
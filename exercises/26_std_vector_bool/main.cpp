#include "../exercise.h"
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector_bool>
// READ: 模板特化 <https://zh.cppreference.com/w/cpp/language/template_specialization>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    std::vector<bool> vec(100, true); // 使用构造函数初始化一个包含100个元素且初始值都为true的vector<bool>，第一个参数指定元素个数，第二个参数指定初始值
    ASSERT(vec[0], "Make this assertion pass.");
    ASSERT(vec[99], "Make this assertion pass.");
    ASSERT(vec.size() == 100, "Make this assertion pass.");
    // NOTICE: 平台相关！注意 CI:Ubuntu 上的值。
    std::cout << "sizeof(std::vector<bool>) = " << sizeof(std::vector<bool>) << std::endl;
    ASSERT(sizeof(vec) == 24, "Fill in the correct value."); 
    // 在常见的64位系统上（如Ubuntu常用的环境），一般vector<bool>会有一些额外的内存管理开销等，其大小通常为24字节左右，具体可能因编译器和平台略有差异，但在题目给定的测试环境下按此填写可通过断言
    {
        vec[20] = false;
        ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`."); // 因为前面将vec[20]设置为了false，所以这里应该用!vec[20]来使断言通过
    }
    {
        vec.push_back(false);
        ASSERT(vec.size() == 101, "Fill in the correct value."); // 原来有100个元素，调用push_back添加一个元素后，大小变为101
        ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`."); // 新添加的元素初始值为false，所以用!vec[100]
    }
    {
        auto ref = vec[30];
        ASSERT(ref, "Fill in `ref` or `!ref`"); // 这里获取到的ref初始值应该是vec[30]原本的值（之前初始化时都是true），所以用ref
        ref = false;
        ASSERT(!ref, "Fill in `ref` or `!ref`"); // 刚刚将ref设置为了false，所以用!ref
        // THINK: WHAT and WHY?
        ASSERT(!vec[30], "Fill in `vec[30]` or `!vec[30]`."); 
        // 对于vector<bool>，其返回的元素引用（像这里的ref）实际上是一种代理对象，对这个代理对象的修改会反映到原vector的对应元素上，所以当把ref设置为false后，vec[30]也变为了false，这里用!vec[30]使断言通过
    }
    return 0;
}
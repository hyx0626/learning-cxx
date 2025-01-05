#include "../exercise.h"
#include <string>

// READ: 字符串 <https://zh.cppreference.com/w/cpp/string/basic_string>

int main(int argc, char **argv) {
    // READ: 字符串字面量 <https://zh.cppreference.com/w/cpp/string/basic_string/operator%22%22s>
    using namespace std::string_literals;
    auto hello = "Hello"s;
    auto world = "world";
    // READ: `decltype` 表达式 <https://zh.cppreference.com/w/cpp/language/decltype>
    // READ: `std::is_same_v` 元编程判别 <https://zh.cppreference.com/w/cpp/types/is_same>
    ASSERT((std::is_same_v<decltype(hello), std::string>), "Fill in the missing type.");
    // `hello` 是通过 `std::string` 的字面量后缀 `s` 创建的，所以其类型为 `std::string`，这里用 `std::string` 来使断言通过，验证其类型是否正确
    ASSERT((std::is_same_v<decltype(world), const char*>), "Fill in the missing type.");
    // `world` 是普通的C风格字符串字面量，其类型为 `const char*`，所以这里填写 `const char*` 来进行类型验证
    // TODO: 将 `?` 替换为正确的字符串
    ASSERT(hello + ", " + world + '!' == "Hello, world!", "Fill in the missing string.");
    // 根据前面定义的 `hello` 和 `world` 字符串，按照代码中的拼接逻辑，拼接后的结果应该是 "Hello, world!"，所以这里填写此字符串来使断言通过
    return 0;
}
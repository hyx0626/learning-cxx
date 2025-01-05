#include "../exercise.h"
#include <map>

// READ: `std::map` <https://zh.cppreference.com/w/cpp/container/map>
// READ: `std::unordered_map` <https://zh.cppreference.com/w/cpp/container/unordered_map>

template<class k, class v>
bool key_exists(std::map<k, v> const &map, k const &key) {
    return map.find(key)!= map.end();
    // 通过调用map的find成员函数查找给定的键，如果返回的迭代器不等于end()，说明找到了该键，即键存在，返回true；否则返回false
}

template<class k, class v>
void set(std::map<k, v> &map, k key, v value) {
    map[key] = value;
    // 直接利用map的下标运算符[]，如果键已经存在，会更新对应的值；如果键不存在，则会插入一个新的键值对
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    using namespace std::string_literals;

    std::map<std::string, std::string> secrets;

    set(secrets, "hello"s, "world"s);
    ASSERT(key_exists(secrets, "hello"s), "\"hello\" shoud be in `secrets`");
    ASSERT(!key_exists(secrets, "foo"s), "\"foo\" shoud not be in `secrets`");

    set(secrets, "foo"s, "bar"s);
    set(secrets, "Infini"s, "Tensor"s);
    ASSERT(secrets["hello"] == "world", "hello -> world");
    ASSERT(secrets["foo"] == "bar", "foo -> bar");
    ASSERT(secrets["Infini"] == "Tensor", "Infini -> Tensor");

    set(secrets, "hello"s, "developer"s);
    ASSERT(secrets["hello"] == "developer", "hello -> developer");

    return 0;
}

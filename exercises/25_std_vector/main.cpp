#include "../exercise.h"
#include <cstring>
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    {
        std::vector<int> vec{1, 2, 3, 4, 5};
        ASSERT(vec.size() == 5, "Fill in the correct value.");
        // std::vector的size()函数返回的是当前容器中元素的个数，这里初始化了5个元素，所以size为5。

        ASSERT(sizeof(vec) == sizeof(std::vector<int>), "Fill in the correct value.");
        // sizeof操作符用于获取类型或者变量所占的字节数，这里获取的是std::vector<int>类型对象所占字节大小，并不是其存储元素占用的字节数总和。

        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");
        // 要比较内存中的数据，使用data()函数获取指向存储元素的内存的指针，用于和数组进行内存比较。
    }
    {
        std::vector<double> vec{1, 2, 3, 4, 5};
        {
            ASSERT(vec.size() == 5, "Fill in the correct value.");
            // 同理，初始化了5个元素，size为5。
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value.");
            double ans[]{1, 2, 3, 4, 5};
            ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");
        }
        {
            vec.push_back(6);
            ASSERT(vec.size() == 6, "Fill in the correct value.");
            // push_back会在向量末尾添加一个元素，原来有5个元素，添加后变为6个元素，所以size为6。
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value.");
            // sizeof获取的是对象本身类型的大小，不受元素个数动态变化影响。
            vec.pop_back();
            ASSERT(vec.size() == 5, "Fill in the correct value.");
            // pop_back会移除末尾一个元素，元素个数变回5个，所以size为5。
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value.");
        }
        {
            vec[4] = 6;
            ASSERT(vec[0] == 1, "Fill in the correct value.");
            ASSERT(vec[1] == 2, "Fill in the correct value.");
            ASSERT(vec[2] == 3, "Fill in the correct value.");
            ASSERT(vec[3] == 4, "Fill in the correct value.");
            ASSERT(vec[4] == 6, "Fill in the correct value.");
            // 只是修改了索引为4的元素值为6，其他索引对应的元素值不变。
        }
        {
            // THINK: `std::vector` 插入删除的时间复杂度是什么？
            // 对于插入（insert），在末尾插入是平均时间复杂度O(1)，在中间插入可能涉及到元素移动，时间复杂度是O(n)。删除（erase）同理，删除末尾元素是O(1)，删除中间元素可能涉及元素移动，时间复杂度是O(n)。

            vec.insert(vec.begin() + 1, 1.5);
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 3, 4, 6}), "Make this assertion pass.");
            // 在索引为1的位置插入元素1.5，所以变成相应的新序列。
            vec.erase(vec.begin() + 2);
            ASSERT((vec == std::vector<double>{1, 1.5, 3, 4, 6}), "Make this assertion pass.");
            // 删除索引为2的元素，得到新的序列。
        }
        {
            vec.shrink_to_fit();
            ASSERT(vec.capacity() == vec.size(), "Fill in the correct value.");
            // shrink_to_fit会尝试减少容量使其等于当前元素个数（size）。
            vec.clear();
            ASSERT(vec.empty(), "`vec` is empty now.");
            ASSERT(vec.size() == 0, "Fill in the correct value.");
            ASSERT(vec.capacity() == 0, "Fill in the correct value.");
            // clear会移除所有元素，size变为0，调用shrink_to_fit后容量也变为0。
        }
    }
    {
        std::vector<char> vec(48, 'z'); // TODO: 调用正确的构造函数
        // 构造一个包含48个元素，每个元素初始化为'z'的字符向量。
        ASSERT(vec[0] == 'z', "Make this assertion pass.");
        ASSERT(vec[47] == 'z', "Make this assertion pass.");
        ASSERT(vec.size() == 48, "Make this assertion pass.");
        ASSERT(sizeof(vec) == sizeof(std::vector<char>), "Fill in the correct value.");
        {
            auto capacity = vec.capacity();
            vec.resize(16);
            ASSERT(vec.size() == 16, "Fill in the correct value.");
            ASSERT(vec.capacity() == capacity, "Fill in a correct identifier.");
            // resize会改变元素个数（size），如果新大小小于原容量，容量一般不变（具体取决于实现，但通常是这样）。
        }
        {
            vec.reserve(256);
            ASSERT(vec.size() == 16, "Fill in the correct value.");
            ASSERT(vec.capacity() == 256, "Fill in the correct value.");
            // reserve只会改变容量（capacity），不会改变元素个数（size），用于提前预留足够的空间。
        }
        {
            vec.push_back('a');
            vec.push_back('b');
            vec.push_back('c');
            vec.push_back('d');
            ASSERT(vec.size() == 20, "Fill in the correct value.");
            // 原来有16个元素，又添加了4个元素，所以size变为20。
            ASSERT(vec.capacity() == 256, "Fill in the correct value.");
            // 容量之前已经通过reserve设置为256，没有超出容量限制，所以容量不变。
            ASSERT(vec[15] == '\0', "Fill in the correct value.");
            // 之前通过resize变为16个元素，未初始化的部分默认值是'\0'。
            ASSERT(vec[16] == 'a', "Fill in the correct value.");
            ASSERT(vec[17] == 'b', "Fill in the correct value.");
            ASSERT(vec[18] == 'c', "Fill in the correct value.");
            ASSERT(vec[19] == 'd', "Fill in the correct value.");
        }
    }

    return 0;
}
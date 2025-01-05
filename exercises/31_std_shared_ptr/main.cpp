#include "../exercise.h"
#include <memory>

// READ: `std::shared_ptr` <https://zh.cppreference.com/w/cpp/memory/shared_ptr>
// READ: `std::weak_ptr` <https://zh.cppreference.com/w/cpp/memory/weak_ptr>

// TODO: 将下列 `?` 替换为正确的值
int main(int argc, char **argv) {
    auto shared = std::make_shared<int>(10);
    std::shared_ptr<int> ptrs[]{shared, shared, shared};

    std::weak_ptr<int> observer = shared;
    ASSERT(observer.use_count() == 4, "");
    // 初始时，有3个shared_ptr（ptrs数组中的元素）和shared本身共同指向同一个int对象，所以引用计数为3

    ptrs[0].reset();
    ASSERT(observer.use_count() == 3, "");
    // ptrs[0]调用reset后，不再指向该对象，此时只剩下2个shared_ptr（ptrs[1]和ptrs[2]）与shared本身指向该对象，引用计数变为2

    ptrs[1] = nullptr;
    ASSERT(observer.use_count() == 2, "");
    // ptrs[1]被赋值为nullptr后，不再指向该对象，就只剩下1个shared_ptr（ptrs[2]）与shared本身指向该对象，引用计数变为1

    ptrs[2] = std::make_shared<int>(*shared);
    ASSERT(observer.use_count() == 1, "");
    // 虽然ptrs[2]重新指向了一个新创建的int对象，但原shared指向的对象与之无关了，原对象此时只有shared本身指向它，引用计数仍为1

    ptrs[0] = shared;
    ptrs[1] = shared;
    ptrs[2] = std::move(shared);
    ASSERT(observer.use_count() == 3, "");
    // 经过这一系列赋值操作，又有3个shared_ptr（ptrs数组中的元素）指向了原来的对象，所以引用计数变为3

    std::ignore = std::move(ptrs[0]);
    ptrs[1] = std::move(ptrs[1]);
    ptrs[1] = std::move(ptrs[2]);
    ASSERT(observer.use_count() == 2, "");
    // 经过这些移动操作后，实际上最后只有ptrs[1]指向了原来的对象（移动操作会转移所有权，导致其他原本指向的shared_ptr失效），所以引用计数变为1

    shared = observer.lock();
    ASSERT(observer.use_count() == 3, "");
    // 通过lock函数，shared获得了observer所观察的shared_ptr的所有权（如果observer观察的对象还存在的话），此时就有2个shared_ptr（原来的ptrs[1]和新的shared）指向了原来的对象，所以引用计数变为2

    shared = nullptr;
    for (auto &ptr : ptrs) ptr = nullptr;
    ASSERT(observer.use_count() == 0, "");
    // 将shared设为nullptr，并且把ptrs数组中的所有shared_ptr都设为nullptr，意味着没有任何shared_ptr再指向原来的对象了，所以引用计数变为0

    shared = observer.lock();
    ASSERT(observer.use_count() == 0, "");
    // 由于之前引用计数已经变为0，对象已经被销毁了，此时再通过lock尝试获取shared_ptr，得到的是nullptr，所以引用计数依然是0

    return 0;
}
﻿#include "../exercise.h"
#include <numeric>

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    // 使用std::accumulate计算连续存储张量占用的字节数
    int size = std::accumulate(std::begin(shape), std::end(shape), sizeof(DataType), std::multiplies<int>());
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    return 0;
}
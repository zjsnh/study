#pragma once

// 声明模板函数，但不定义它
template <typename T>
T add(T a, T b);

//// 显式声明模板实例化
//extern template int add<int>(int, int);
//extern template double add<double>(double, double);


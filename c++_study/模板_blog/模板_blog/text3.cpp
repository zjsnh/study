#include "text1.h"

//// 在源文件中定义模板函数
//template <typename T>
//T add(T a, T b) {
//    return a + b;
//}

// 在这里显式实例化模板，告诉编译器生成特定类型的代码
template int add<int>(int, int);
template double add<double>(double, double);

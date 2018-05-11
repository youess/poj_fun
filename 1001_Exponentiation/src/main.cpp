
/*
 * 计算浮点数的指数，考虑精度的问题
 * http://poj.org/problem?id=1001
 */

// #include <sstream>
#include <string>
#include <iostream>


int main() {

    std::string s;
    int n(0);
    // double res(0);
    // double tmp(0);
    while (std::cin >> s >> n)
    {
        // 测试
        // std::cout << "输出结果: ";
        // std::cout << s << " " << n << std::endl;

        /* 无脑相乘
        std::stringstream ss(s);
        ss >> res;
        std::cout << "输入double值: " << res << " 指数: " << n;

        tmp = res;
        for (int i = 1; i < n; ++i) {
            res *= tmp;
        }
        std::cout << " 指数结果为:" << res << std::endl;
        // 98.999 10
        // 输入double值: 98.999 指数: 10 指数结果为:9.04291e+19
        */


    }

    return 0;
}

/*
 * 计算浮点数的指数，考虑精度的问题
 * http://poj.org/problem?id=1001
 *
 * 高精度解析:
 * https://wenku.baidu.com/view/54adf6c18bd63186bcebbc68.html
 */

// #include <sstream>
#include <string>
#include <iostream>
#include <memory.h>


int main() {

    // std::string s;
    char d[5];
    int n(0);
    // double res(0);
    // double tmp(0);
    while (std::cin >> d >> n)
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

        /* Warm up
        for (int i = 0; i < 5; ++i) {
            std::cout << d[i];
        }
        std::cout << " " << n << std::endl;
        */

        int a[150] = {0}, b[150] = {0}, c[150] = {0};
        int lena, lenb, lenc, lend, len;
        int i, j, k, temp, flag, digit;

        // 基数的长度
        lend = strlen(d);
        // 小数点的位置
        for (i=0; d[i]; ++i)
            if (d[i] == '.') break;
        digit = lend - i;
        for (j=i; d[j]; ++j) d[j] = d[j+1];
        lend -= 1;

        // 逆序数字数组
        for (i=0; i <= lend / 2; ++i)
        {
            temp = d[i]; d[i] = d[lend - i];
            d[lend - i] = temp;
        }

        // copy 数组, ascii字符0-9，码表从48位开始
        for (i=0; d[i]; ++i) a[i] = d[i] - 48;
        lena = lend;
        for (i=0; i <= lena; ++i) b[i] = a[i];
        lenb = lena;

        // 计算乘法
        for (i = 1; i <= n - 1; ++i) {
            // 计算两个数相乘结果
            for (j = 0; j <= lenb; ++j) {
                for (k=0; k <= lena; ++k) {
                    c[j + k] += a[k] * b[j];
                    c[j + k + 1] += c[j + k] / 10;
                    c[j + k] %= 10;
                }
            }
            // 将c的值赋予b，能够让上面的循环在>2的指数下继续成立
            k--; j--;
            lenc = c[j + k + 1] != 0 ? j + k + 1 : j + k;
            for (j=0; j <= lenc; ++j) b[j] = c[j];
            lenb = lenc;
            // 清零c，作为辅助结果。
            memset(c, 0, sizeof(c));
        }

        // 打印结果，判断小数点前是否为0.
        digit = n * digit; len = lenb + 1 - digit; flag = 0;
        for (i=lenb - len; i>=0; --i) {
            if (b[i] != 0) {flag = 1; break;}
        }
        if (flag == 0) {
            for (i=lenb; i>=lenb-len+1; --i)
                std::cout << b[i];
            std::cout << std::endl;
            continue;
        }
        if (len == 1 && b[lenb] == 0) std::cout << ".";
        else {
            for (i=lenb; i>=lenb-len+1;--i)
                std::cout << b[i];
            std::cout << ".";
        }
        for (i=0; i<=lenb-len;++i)
            if (b[i] != 0) {temp =i; break; }

        for (i=lenb-len; i>=temp;--i)
            std::cout << b[i];
        std::cout << std::endl;
    }

    return 0;
}
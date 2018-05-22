
/*
 * 计算浮点数的指数，考虑精度的问题
 * http://poj.org/problem?id=1001
 *
 * 高精度解析:
 * https://wenku.baidu.com/view/54adf6c18bd63186bcebbc68.html
 *
 * 大体步骤为用数组代替单纯的double精度类型，并注意后续的打印格式
 *
 * 数组a和数组b分别表示两个数，数组c表示结果。
 *
 * 保持数组a,b逆序，容易往后相加计算。
 *
 * [5, 4] 和 [5, 4]
 * eg: a[0] * b[0] = 25 = c[0]
 * c[0] = 25 % 10, c[1] += 25 / 10;  然后继续往后的操作。
 *
 *
 */

#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;


int main()
{

    // 读入数据
    char d[10] = {0};
    int n(0);

    while (scanf("%s%d", d, &n) != EOF)
    {
        if (n == 0)
        {
            printf("1\n");
            continue;
        }

        int a[150]={0}, b[150]={0}, c[150]={0};
        int lena, lenb, lenc, lend;

        // 正确读取数字
        // 11.345 digit=3, len=2, lena=4
        // eg: 0000.01 1

        int i, j, digit, flag(0);

        // 跳过前面的0
        for (i=0; d[i]; ++i)
            if (d[i] != '0' || d[i+1] == '.') {flag=1; break;}
        if (flag) for (j=0; d[j]; ++j) d[j] = d[j+i];

        // 跳过小数点后面的0
        for (i=0; d[i]; ++i)
            if (d[i] == '.') break;

        lend = (int)strlen(d) - 1;
        if (lend < 0) {
            printf("0\n");
            continue;
        }

        digit = i == lend + 1 ? 0 : i;                      // . position
        int z(0);
        for (j=i+1; d[j]; ++j)
        {
            if (d[j] == '0') z += 1;
            if (d[j] != '0') z = 0;
        }

        // printf("%d\n", z);
        if (z > 0)
        {
            for (j=0; j < z; ++j) d[lend-j] = d[lend-j+1];     // 后续置空
        }
        lend = lend - z;

        // check the normalized string
        // for (i=0; d[i]; ++i) {printf("%c", d[i]);} printf("\n");

        // 去掉"."
        if (digit > 0) {
            for (j=digit; d[j]; ++j) d[j] = d[j+1];
            digit = lend - digit;    // 小数点位数
            lend -= 1;
        }
        // printf("%d %d\n", lend, digit);
        // for (i=0; d[i]; ++i) {printf("%c", d[i]);} printf("\n");

        // 交换数字字符的顺序
        char temp;
        for (i=0; i<=lend/2; ++i)
        {
            temp = d[i]; d[i] = d[lend-i];
            d[lend-i] = temp;
        }
        // for (i=0; d[i]; ++i) {printf("%c", d[i]);} printf("\n");

        // 复制d的值到a, b数组中。
        for (i=0; d[i]; ++i) a[i] = d[i] - 48;
        for (i=0; d[i]; ++i) b[i] = a[i];
        lena = lenb = lend;

        // for (i=0; i <= lena; ++i) {printf("%d", a[i]);} printf("\n");
        // printf("%d %d\n", digit, lena);
        //for (i=0; i <= lena; ++i) printf("%d", a[i]);
        //printf("\n");
        // printf("%d %d %d\n", lena, lenb, lend);
        // 进行乘法操作
        int k;
        for (k = 1; k <= n - 1; ++k)         // 阶乘
        {
            for (i=0; i <= lena; ++i)
            {
                for (j=0; j<=lenb; ++j)
                {
                    c[i+j] += a[i] * b[j];
                    c[i+j+1] += c[i+j] / 10;
                    c[i+j] %= 10;
                    // printf("%d ", c[i+j]);
                }
            }
            i--; j--;
            lenc =  c[i+j+1] != 0 ? i + j + 1 : i + j;
            // 将a复制结果c
            for (i=0; i <= lenc; ++i) a[i] = c[i];
            lena = lenc;
            memset(c, 0, sizeof(c));
        }
        //for (i=0; i <= lena; ++i) {printf("%d", a[i]);} printf("\n");
        // 打印结果
        int len;
        digit *= n;               // 小数点位数
        len = lena + 1 - digit;   // 非小数点位数

        if ( (len == 1 && a[lena] == 0 || len == 0) && digit != 0)
        {
            //printf("C1 %d %d %d\n", digit, len, lena);
            printf(".");
            for (i=lena-len; i>=0; i--)
                printf("%d", a[i]);
        }else if (digit == 0) {
            //printf("C2 %d %d %d\n", digit, len, lena);
            for (i=lena; i>=digit; i--)
                printf("%d", a[i]);
        } else {
            //printf("C3 %d %d %d\n", digit, len, lena);
            for (i=lena; i>digit-1; i--)
                printf("%d", a[i]);
            printf(".");
            for (i = digit-1; i >= 0; i--)
                printf("%d", a[i]);
        }
        printf("\n");


        /*
        flag = 0;                 // 是否全部都是0
        printf("%d %d\n", digit, len);
        for (i=lena-len; i>=0;--i)
            if (a[i] != 0) {flag = 1; break;}

        if (flag == 0)
        {
            for (i=lena; i>=lena-len+1; --i) printf("%d", a[i]);
            // printf("0");
            printf("\n");
            continue;
        }
        // 打印整数部分
        if (len == 1 && a[lena] == 0) printf(".");
        else {
            for (i=lena;i>=lena-len+1; --i) printf("%d", a[i]);
            printf(".");
        }
        // 打印小数部分
        int tmp(0);
        for (i=0; i<=lena-len; ++i)
        {
            if (a[i] != 0) {tmp = i; break;}
        }
        for (i=lena-len; i>=tmp; --i)
            printf("%d", a[i]);
        printf("\n");
        */
    }

    return 0;
}
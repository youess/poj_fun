/*
 * Problem: http://poj.org/problem?id=1002
 *
 * 如何解答，构建一个hash表用来查询字符转换成数字
 * 然后再用一个hash表进行查询计数
 * STL用map来计算会超时，不知道是输入还是数据结构的原因O(nlogn)并不适合
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int cmpStr(const void* a, const void* b)
{
    const char** aa = (const char**) a;
    const char** bb = (const char**) b;
    return strcmp(*aa, *bb);
}
 */

int main()
{

    // 存储电话号码
    char ph[100000][9];
    memset(ph, 0, sizeof(ph));

    // 读取每一行的编码前字符
    char buf[1000];
    memset(ph, 0, sizeof(buf));

    // 读取首行整数
    int nph;
    scanf("%d", &nph);

    // 26字母映射表
    char map[26] = {
            '2', '2', '2',           // ABC
            '3', '3', '3',           // DEF
            '4', '4', '4',           // GHI
            '5', '5', '5',           // JKL
            '6', '6', '6',           // MNO
            '7', 0, '7', '7',        // PQRS, Q not used set null char
            '8', '8', '8',           // TUV
            '9', '9', '9', 0         // WXYZ
    };

    // 读取标识的编码后的手机号码
    int x(0);
    for (int i=0; i<nph; ++i)
    {
        scanf("%s", buf);
        x = 0;         // point column index
        for (int j=0; buf[j]; ++j)
        {
            if (buf[j] == '-') continue;
            if (buf[j] >= 'A' && buf[j] <= 'Z') buf[j] = map[buf[j] - 'A'];
            ph[i][x++] = buf[j];             // 更改之后x自增
            if (x == 3) ph[i][x++] = '-';
        }
    }
    // 按照首字母进行排序
    // qsort(ph, nph, 9, strcmp);
    qsort(ph, nph, 9, (int (*)(const void *, const void *))strcmp);

    // 打印有出现两次以上的号码
    int flag(0);         // 判断是否有重复的电话号码
    x = 1;               // 记录排序好的数组重复个数
    int i;
    for (i = 1; i < nph; ++i)
    {
        if (strcmp(ph[i-1], ph[i]))         // 比较两行字符是否相同, 若不同大于或小于0
        {
            if (x > 1) {
                printf("%s %d\n", ph[i-1], x);
                flag = 1;
            }
            x = 1;                          // 重新记录下一个电话号码
        } else { x++; }                    // 若相同strcmp返回0
    }
    if (x > 1)
    {
        printf("%s %d\n", ph[i-1], x);
        flag = 1;
    }
    if (!flag) printf("No duplicates.\n");

}

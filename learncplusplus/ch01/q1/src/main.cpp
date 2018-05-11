#include <iostream>


void readNumber(int &a)
{
    std::cin >> a;
}

int writeAnswer(int &b)
{
    std::cout << b << std::endl;
    return 0;
}

int main() {

    int a, b, c(0);

    readNumber(a);
    readNumber(b);

    c = a + b;

    writeAnswer(c);

    return 0;
}
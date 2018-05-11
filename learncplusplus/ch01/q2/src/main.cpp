
#include "../include/io.h"

int main() {

    int a, b, c(0);

    readNumber(a);
    readNumber(b);

    c = a + b;

    writeAnswer(c);

    return 0;
}
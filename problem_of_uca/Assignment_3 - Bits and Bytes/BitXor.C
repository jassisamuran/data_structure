#include <stdio.h>

int bitXor(int x, int y) {
    int a = x & ~y;
    int b = ~x & y;
    int result = ~(~a & ~b);
    return result;
}

int main() {
    int x = 4;
    int y = 5;
    int result = bitXor(x, y);

    printf("bitXor(%d, %d) = %d\n", x, y, result);

    return 0;
}

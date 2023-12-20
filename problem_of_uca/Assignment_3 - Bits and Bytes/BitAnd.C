#include <stdio.h>

int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

int main() {
    int x = 5;
    int y = 6;
    int result = bitAnd(x, y);

    printf("bitAnd(%d, %d) = %d\n", x, y, result);

    return 0;
}

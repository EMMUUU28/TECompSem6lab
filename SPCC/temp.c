#include <stdio.h>

int main() {
    int x = 5;
    float y = 3.14;

    if (x > 0) {
        y = y + 1;
    } else {
        y = y - 1;
    }

    printf("Result: %f\n", y);

    return 0;
}

#include <stdio.h>

int main() {
printf("\033[2J\033[H");
    float grid[24][80];
    for (int y = 0; y < 24; y++) {
        for (int x = 0; x < 80; x++) {
            grid[y][x] = 0.5;
        }
    }

    for (int y = 0; y < 24; y++) {
        for (int x = 0; x < 80; x++) {
            printf("%f ", grid[y][x]);
        }
        printf("\n");
    }

    return 0;
}




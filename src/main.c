#define STB_PERLIN_IMPLEMENTATION
#include "stb_perlin.h"  // кавычки, не скобки!
#include <stdio.h>

int main() {
    float grid[24][80];
    float x = 1.0f;
    float y = 1.0f;
    float time = 0.0f;
    
    float value = stb_perlin_noise3(x * 0.1f, y * 0.1f, time * 0.05f, 0, 0, 0);
    for (int yg = 0; yg < 24; yg++) {
        for (int xg = 0; xg < 80; xg++) {
      grid[yg][xg] = stb_perlin_noise3(xg * 0.1f, yg * 0.1f, 0, 0, 0, 0);
    }
  }

  for (int yg = 0; yg < 24; yg++) {
    for (int xg = 0; xg < 80; xg++) {
         printf("%f", grid[yg][xg]);
    }
     printf("\n");
  }
    
    return 0;
}

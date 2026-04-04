#define TB_IMPL
#include "termbox2.h"
#include <stdio.h>
#include <unistd.h>
#define STB_PERLIN_IMPLEMENTATION
#include "stb_perlin.h"

int main() {
    float scale = 0.1f;
    float time = 0.0f;
    tb_init();

    while(1) {
        tb_clear();

        for (int y = 0; y < tb_height(); y++) {
            for (int x = 0; x < tb_width(); x++) {
                float n = stb_perlin_noise3(x * scale, y * scale, time, 0, 0, 0);

                if (n < -0.2f)     tb_printf(x, y, TB_WHITE, TB_DEFAULT, ".");
                else if (n < 0.2f) tb_printf(x, y, TB_WHITE, TB_DEFAULT, "*");
                else               tb_printf(x, y, TB_WHITE, TB_DEFAULT, "#");
            }
        }

        time += 0.05f;
        tb_present();
        usleep(100000);
    }

    return 0;
}

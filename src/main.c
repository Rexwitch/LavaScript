#define TB_IMPL
#define TB_LIB_OPTS
#define TB_OPT_TRUECOLOR

#include "termbox2.h"
#include <stdio.h>

#define STB_PERLIN_IMPLEMENTATION
#include "stb_perlin.h"
#include <unistd.h>

int main() {
  float scale = 0.05f;
  float time = 0.1f;
  tb_init();

  while (1) {
   struct tb_event ev;
   if (tb_peek_event(&ev, 0) == TB_OK) {
      if (ev.type == TB_EVENT_RESIZE) {
        tb_clear();
      }
      if (ev.key == TB_KEY_CTRL_C) break;
    }
      tb_clear();
      int h = tb_height();
      int w = tb_width();
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                float n = stb_perlin_noise3(x * scale, y * scale, time, 0, 0, 0);

                if (n < -0.2f)     tb_printf(x, y, TB_WHITE, TB_DEFAULT, " ");
                else if (n < 0.01f) tb_printf(x, y, TB_WHITE, TB_DEFAULT, "░");
                else               tb_printf(x, y, TB_WHITE, TB_DEFAULT, "█");
      }
    }
    time += 0.01f;
    tb_present();
    usleep(100000);
  }
  tb_shutdown();
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);

  // x0 < x1:
  draw_line(41, 90, 300, 90, s, c); // slope of 0
  draw_line(3, 3, 87, 42, s, c); // octant 1
  draw_line(89, 4, 179, 94, s, c); // slope of 1
  draw_line(24, 50, 48, 128, s, c); // octant 2
  draw_line(84, 460, 284, 60, s, c); // octant 7
  draw_line(354, 360, 424, 290, s, c); // slope of -1
  draw_line(70, 400, 270, 300, s, c); // octant 8

  // x0 > x1 (draw_line function must swap coordinates):
  draw_line(261, 40, 161, 340, s, c); // octant 3
  draw_line(264, 289, 164, 389, s, c); // slope of -1
  draw_line(194, 362, 75, 300, s, c); // octant 4
  draw_line(463, 320, 107, 320, s, c); // slope of 0
  draw_line(397, 100, 49, 60, s, c); // octant 5
  draw_line(407, 407, 7, 7, s, c); // slope of 1
  draw_line(186, 242, 86, 42, s, c); // octant 6

  // vertical lines (no change in x):
  draw_line(357, 3, 357, 357, s, c); // bottom to top
  draw_line(240, 385, 240, 85, s, c); // top to bottome

  display(s);
  save_extension(s, "lines.png");
}

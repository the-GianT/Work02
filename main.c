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
  draw_line(3, 3, 87, 42, s, c); // octant 1
  draw_line(24, 50, 48, 128, s, c); // octant 2
  draw_line(84, 460, 284, 60, s, c); // octant 7
  draw_line(70, 400, 270, 300, s, c); // octant 8

  // x0 > x1 (draw_line function must swap coordinates):
  draw_line(261, 40, 161, 340, s, c); // octant 3
  draw_line(194, 362, 75, 300, s, c); // octant 4
  draw_line(397, 100, 49, 60, s, c); // octant 5
  draw_line(186, 242, 86, 42, s, c); // octant 6

  display(s);
  save_extension(s, "lines.png");
}

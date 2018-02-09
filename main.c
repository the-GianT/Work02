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

  draw_line(3, 3, 87, 42, s, c); // octant 1
  draw_line(24, 50, 48, 128, s, c); // octant 2

  display(s);
  save_extension(s, "lines.png");
}

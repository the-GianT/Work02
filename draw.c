#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int a = y1 - y0; // delta y
  int b = x0 - x1; // negative delta x
  float m = -a/b; // slope
  int x;
  int y;
  int d;

  if (0 <= m && m < 1) { // octant 1
    x = x0;
    y = y0;
    d = 2 * a + b; // equivalent to f(x+1, y+1/2)
    while (x <= x1) {
      plot(s, c, x, y);
      if (d > 0) { // if midpoint between the two pixels is below the line
	y++;
	d += 2 * b;
      }
      x++;
      d += 2 * a;
    }
  }
}

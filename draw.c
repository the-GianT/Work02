#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int a = y1 - y0; // delta y
  int b = x0 - x1; // negative delta x
  // printf("a: %d\nb: %d\n", a, b);
  /*
  float m = -a/b; // slope
  printf("slope: %f\n", m);
  */
  int x;
  int y;
  int d;

  // if (0 <= m && m < 1) { // octant 1
  if (a >= 0) { // positive slope (or slope of zero)
    
    if (a < -b) { // octant 1
      // printf("Got here.\n");
      x = x0;
      y = y0;
      d = 2 * a + b; // equivalent to f(x+1, y+1/2)
      while (x <= x1) {
	// printf("x: %d\n", x);
	plot(s, c, x, y);
	if (d > 0) { // if midpoint between the two pixels is below the line
	  y++;
	  d += 2 * b;
	}
	x++;
	d += 2 * a;
      }
    } else { // octant 2
      /* insert implementation here */
    }
  } else { // negative slope
    
    if (a > b) { // octant 7
      /* insert implementation here */
    } else { // octant 8
      /* insert implementation here */
    }
  }
}


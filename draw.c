#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

/*======== void draw_line() ==========
Inputs:   int x0
         int y0
         int x1
         int y1
         screen s
         color c
Returns:
Draws a line of color c from pixel (x0, y0) to pixel (x1, y1), using Bresenham's
Line Algorithm
Gian
====================*/
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

  // terms of line function f(x, y) = Ax + By + C
  int a;
  int b;
  
  int x;
  int y;
  int d;

  // Always draw from left to right.
  if (x0 > x1) { // perform swap
    int tmpx;
    int tmpy;

    tmpx = x0;
    x0 = x1;
    x1 = tmpx;

    tmpy = y0;
    y0 = y1;
    y1 = tmpy;
  }

  a = y1 - y0; // delta y
  b = x0 - x1; // negative delta x
  x = x0;
  y = y0;

  if (a >= 0) { // positive slope (or slope of zero)
    
    if (a < -b) { // octant 1
      
      d = 2 * a + b; // equivalent to f(x0+1, y0+1/2)
      while (x <= x1) {
	plot(s, c, x, y);
	if (d > 0) { // if midpoint between the two pixels is below the line
	  y++;
	  d += 2 * b;
	}
	x++;
	d += 2 * a;
      }
      
    } else { // octant 2
      
      d = a + 2 * b; // equivalent to f(x0+1/2, y0+1)
      while (y <= y1) {
	plot(s, c, x, y);
	if (d < 0) {
	  // if midpoint between the two pixels is to the left of the line
	  x++;
	  d += 2 * a;
	}
	y++;
	d += 2 * b;
      }
    }
    
  } else { // negative slope

    if (a < b) { // octant 7
      
      d = a - 2 * b; // equivalent to f(x0+1/2, y0-1)
      while (y >= y1) {
	plot(s, c, x, y);
	if (d > 0) {
	  // if midpoint between the two pixels is to the left of the line
	  x++;
	  d += 2 * a;
	}
	y--;
	d -= 2 * b;
      }
      
    } else { // octant 8
      
      d = 2 * a - b; // equivalent to f(x0+1, y0-1/2)
      while (x <= x1) {
	plot(s, c, x, y);
	if (d < 0) { // if midpoint between the two pixels is above the line
	  y--;
	  d -= 2 * b;
	}
	x++;
	d += 2 * a;
      }
    }
  } // end else statement
} // end void draw_line()


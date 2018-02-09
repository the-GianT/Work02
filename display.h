#include "ml6.h"

#ifndef DISPLAY_H
#define DISPLAY_H

void plot(screen, color, int, int);
void clear_screen(screen);
void save_ppm(screen, char *);
void save_extension(screen, char *);
void display(screen);

#endif

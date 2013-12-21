#ifndef GCHR_H
#define GCHR_H
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#define GCHR_VERBOSE

void get_gchr(ALLEGRO_BITMAP* dest, const char *data, unsigned char scale);

#endif

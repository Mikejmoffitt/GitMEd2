/* Ghost in the Machine level editor */
/* GitMEd2 by Michael Moffitt 2013 */
/* Licensed under the GNU General Public License v3.0 */

#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>

#include "gchr.h"
#include "chr.h"

ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_BITMAP* buffer = NULL;
ALLEGRO_BITMAP* layers[3];

// Display dimensions for scaling set to defaults of the buffer size
int disp_w = 512;
int disp_h = 384;


void draw(ALLEGRO_BITMAP* chr, int x, int y);
void draw_layers(int xoff, int yoff);

void mainloop();
void playsfx(ALLEGRO_SAMPLE* snd);
int update();
int main(int argc, char **argv);

#endif

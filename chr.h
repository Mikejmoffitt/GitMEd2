/* Struct to hold graphics data */
/* GitMEd2 by Michael Moffitt 2013 */
/* Licensed under the GNU General Public License v3.0 */

#ifndef CHR_H
#define CHR_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define CHR_NUMTILES 26

#include "gfx/tiles/0.png.h"
#include "gfx/tiles/1.png.h"
#include "gfx/tiles/2.png.h"
#include "gfx/tiles/3.png.h"
#include "gfx/tiles/4.png.h"
#include "gfx/tiles/5.png.h"
#include "gfx/tiles/6.png.h"
#include "gfx/tiles/7.png.h"
#include "gfx/tiles/8.png.h"
#include "gfx/tiles/9.png.h"
#include "gfx/tiles/10.png.h"
#include "gfx/tiles/11.png.h"
#include "gfx/tiles/12.png.h"
#include "gfx/tiles/13.png.h"
#include "gfx/tiles/14.png.h"
#include "gfx/tiles/15.png.h"
#include "gfx/tiles/16.png.h"
#include "gfx/tiles/17.png.h"
#include "gfx/tiles/18.png.h"
#include "gfx/tiles/19.png.h"
#include "gfx/tiles/20.png.h"
#include "gfx/tiles/21.png.h"
#include "gfx/tiles/22.png.h"
#include "gfx/tiles/23.png.h"
#include "gfx/tiles/24.png.h"
#include "gfx/tiles/25.png.h"

#include "gchr.h"

typedef struct
{
	ALLEGRO_BITMAP* tiles[CHR_NUMTILES];
} Chr;

void chr_load(Chr *chr);
void chr_unload(Chr *chr);
#endif

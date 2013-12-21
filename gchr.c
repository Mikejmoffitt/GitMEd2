#include "gchr.h"

void get_gchr(ALLEGRO_BITMAP* dest, const char *data, unsigned char scale)
{
	const char readOffset = 4;
	if (scale < 0) // No silly 0x0 bitmaps here
	{
		scale = 1;
	}
	
	// Anywhere from 0 to 255 
	int w = data[1] + (data[0] << 8); 
	// Anywhere from 0 to 255 
	int h = data[3] + (data[2] << 8);

#ifdef GCHR_VERBOSE
	printf("Width: %i\nHeight: %i\n",w,h);
#endif

	ALLEGRO_BITMAP* px = al_create_bitmap(scale,scale);
	al_set_target_bitmap(px);
	al_clear_to_color(al_map_rgb(255,255,255));
	
	ALLEGRO_COLOR colors[4];
	colors[0] = al_map_rgb(255,255,255);
	colors[1] = al_map_rgb(160,160,160);
	colors[2] = al_map_rgb(80,80,80);
	colors[3] = al_map_rgb(0,0,0);
	
	
	dest = al_create_bitmap(w*scale,h*scale);
	al_set_target_bitmap(dest);

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w/2; x++)
		{
			// Separate the single byte into two nybbles
			int index = ((x) + (y*(w/2))) + readOffset;

			char px2 = (data[index])%16;
			char px1 = (data[index]) >> 4;

			// Current pixel (discarding first two bytes for size)
			if (px1 > 0)
			{
				al_draw_tinted_bitmap(px,colors[(px1-1)%4],(x*2)*scale,y*scale,0);
			}
			if (px2 > 0)
			{
				al_draw_tinted_bitmap(px,colors[(px2-1)%4],((x*2)+1)*scale,y*scale,0);
			}
#ifdef GCHR_VERBOSE
			if (px1 == 0)
			{
				printf(" ");
			}
			else
			{
				printf("%d",(int)px1);
			}
			if (px2 == 0)
			{
				printf(" ");
			}
			else
			{
				printf("%d",(int)px2);
			}
#endif
		}
		
#ifdef GCHR_VERBOSE
		printf("\n");
#endif
	}
	al_destroy_bitmap(px);
}

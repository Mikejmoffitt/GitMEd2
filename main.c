#include "main.h"

void draw(ALLEGRO_BITMAP* chr, int x, int y)
{
	al_draw_bitmap(chr, x, y, 0);
}

void mainloop()
{
	int ok = 1;
	Chr foo;
	chr_load(&foo);
	while(ok)
	{
		// Just draw a tile to show that anything is working...
		draw(foo.tiles[7],0,0);
		ok = update();
	}
}

void playsfx(ALLEGRO_SAMPLE* snd)
{
	// Play just once, no looping
	al_play_sample(snd,1,0,1,ALLEGRO_PLAYMODE_ONCE,0);
}

int update()
{
	// Handle events for window closing, etc
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMEOUT timeout;
	al_init_timeout(&timeout, 0.0001);
	if (!al_is_event_queue_empty(event_queue))
	{
		al_get_next_event(event_queue,&ev);
		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
		{
			return 0;
		}
	}
	
	// Draw buffer scaled to display size onto display
	al_set_target_backbuffer(display);
	al_clear_to_color(al_map_rgb(0,0,0));
	al_draw_scaled_bitmap(buffer,0,0,512,384,0,0,disp_w,disp_h,0);
	al_flip_display();
	
	// Go back to drawing to the buffer
	al_set_target_bitmap(buffer);
	return 1;
}

int main(int argc, char **argv)
{
	// Get allegro started up
	if (!al_init())
	{
		fprintf(stderr, "Failed to initialize Allegro.\n");
		return -1;
	}
	if (!al_init_primitives_addon())
	{
		fprintf(stderr, "Failed to init primitives addon.\n");
		return -1;
	}
	if (!al_init_image_addon())
	{
		fprintf(stderr, "Failed to init image addon.\n");
		return -1;
	}
	
	// Build display surface
	al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_SUGGEST);
	int flags = 0;
	flags = flags | ALLEGRO_FULLSCREEN_WINDOW | ALLEGRO_NOFRAME;
	al_set_new_display_flags(flags);
	display = al_create_display(512,384);
	if (!display)
	{
		fprintf(stderr, "Failed to create display surface.\n");
		return -1;
	}
	
	// Build buffer to draw to
	buffer = al_create_bitmap(512,384);
	
	// Get dimenison info on backdrop
	disp_w = al_get_bitmap_width(al_get_backbuffer(display));
	disp_h = al_get_bitmap_height(al_get_backbuffer(display));

	// Get event queue set up
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	
	// Main loop
	mainloop();

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	return 0;
}

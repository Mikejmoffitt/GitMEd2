CXX=clang
CFLAGS=-Wl,--as-needed
CFLAGS_DEBUG=-Wall -Wl,--as-needed -ggdb
LDFLAGS=`pkg-config --cflags --static --libs allegro-static-5.0 allegro_acodec-static-5.0 allegro_audio-static-5.0 allegro_color-static-5.0 allegro_dialog-static-5.0 allegro_image-static-5.0 allegro_main-static-5.0 allegro_primitives-static-5.0`
INCLUDE=

OBJS=main.c gchr.c chr.c
OUT=gitmed
OUT_DEBUG=gitmed-debug

all: gitmed_rule

debug: gitmed_debug_rule

clean:
	rm -rf *.o gitmed

gitmed_rule: $(OJBS)
	$(CXX) $(OBJS) -o $(OUT) $(INCLUDE) $(CFLAGS) $(LDFLAGS)

gitmed_debug_rule: $(OJBS)
	$(CXX) $(OBJS) -o $(OUT_DEBUG) $(INCLUDE) $(CFLAGS_DEBUG) $(LDFLAGS)

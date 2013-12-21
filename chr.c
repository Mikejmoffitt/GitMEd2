#include "chr.h"

void chr_load(Chr *chr)
{
	printf("Loading from gchr consts\n");
	get_gchr(chr->tiles[0],gchr_0,1);
	get_gchr(chr->tiles[1],gchr_1,1);
	get_gchr(chr->tiles[2],gchr_2,1);
	get_gchr(chr->tiles[3],gchr_3,1);
	get_gchr(chr->tiles[4],gchr_4,1);
	get_gchr(chr->tiles[5],gchr_5,1);
	get_gchr(chr->tiles[6],gchr_6,1);
	get_gchr(chr->tiles[7],gchr_7,1);
	get_gchr(chr->tiles[8],gchr_8,1);
	get_gchr(chr->tiles[9],gchr_9,1);
	get_gchr(chr->tiles[10],gchr_10,1);
	get_gchr(chr->tiles[11],gchr_11,1);
	get_gchr(chr->tiles[12],gchr_12,1);
	get_gchr(chr->tiles[13],gchr_13,1);
	get_gchr(chr->tiles[14],gchr_14,1);
	get_gchr(chr->tiles[15],gchr_15,1);
	get_gchr(chr->tiles[16],gchr_16,1);
	get_gchr(chr->tiles[17],gchr_17,1);
	get_gchr(chr->tiles[18],gchr_18,1);
	get_gchr(chr->tiles[19],gchr_19,1);
	get_gchr(chr->tiles[20],gchr_20,1);
	get_gchr(chr->tiles[21],gchr_21,1);
	get_gchr(chr->tiles[22],gchr_22,1);
	get_gchr(chr->tiles[23],gchr_23,1);
	get_gchr(chr->tiles[24],gchr_24,1);
	get_gchr(chr->tiles[25],gchr_25,1);
	printf("Done loading.\n");
}

void chr_unload(Chr *chr)
{
	for (int i = 0; i < CHR_NUMTILES; i++)
	{
		al_destroy_bitmap(chr->tiles[i]);
	}
}

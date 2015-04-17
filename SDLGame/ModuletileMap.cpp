
#include "Application.h"
#include "Globals.h"
#include "ModuletileMap.h"
#include "ctype.h"

ModuleTileMap::ModuleTileMap(Application* app, bool start_Enabled) : Module(app, start_Enabled), tiles(22)
{

	
	tiles[0].x = 255;
	tiles[0].y = 15;
	tiles[0].h = 16;
	tiles[0].w = 16;


	tiles[1].x = 271;
	tiles[1].y = 15;
	tiles[1].h = 16;
	tiles[1].w = 16;

	tiles[2].x = 288;
	tiles[2].y = 15;
	tiles[2].h = 16;
	tiles[2].w = 16;

	tiles[3].x = 305;
	tiles[3].y = 15;
	tiles[3].h = 16;
	tiles[3].w = 16;

	tiles[4].x = 322;
	tiles[4].y = 15;
	tiles[4].h = 16;
	tiles[4].w = 16;

	tiles[5].x = 339;
	tiles[5].y = 15;
	tiles[5].h = 16;
	tiles[5].w = 16;

	tiles[6].x = 356;
	tiles[6].y = 15;
	tiles[6].h = 16;
	tiles[6].w = 16;

	tiles[7].x = 373;
	tiles[7].y = 15;
	tiles[7].h = 16;
	tiles[7].w = 16;
	//--------------- SECOND ROW
	tiles[8].x = 255;
	tiles[8].y = 32;
	tiles[8].h = 16;
	tiles[8].w = 16;

	tiles[9].x = 271;
	tiles[9].y = 32;
	tiles[9].h = 16;
	tiles[9].w = 16;

	tiles[10].x = 288;
	tiles[10].y = 32;
	tiles[10].h = 16;
	tiles[10].w = 16;

	tiles[11].x = 305;
	tiles[11].y = 32;
	tiles[11].h = 16;
	tiles[11].w = 16;

	tiles[12].x = 322;
	tiles[12].y = 32;
	tiles[12].h = 16;
	tiles[12].w = 16;

	tiles[13].x = 339;
	tiles[13].y = 32;
	tiles[13].h = 16;
	tiles[13].w = 16;


	tiles[14].x = 356;
	tiles[14].y = 32;
	tiles[14].h = 16;
	tiles[14].w = 16;

	tiles[15].x = 355;
	tiles[15].y = 32;
	tiles[15].h = 16;
	tiles[15].w = 16;
	//--------------- THIRD ROW

	tiles[16].x = 255;
	tiles[16].y = 49;
	tiles[16].h = 16;
	tiles[16].w = 16;

	tiles[17].x = 271;
	tiles[17].y = 49;
	tiles[17].h = 16;
	tiles[17].w = 16;

	tiles[18].x = 288;
	tiles[18].y = 49;
	tiles[18].h = 16;
	tiles[18].w = 16;

	tiles[19].x = 305;
	tiles[19].y = 49;
	tiles[19].h = 16;
	tiles[19].w = 16;


	tiles[20].x = 322;
	tiles[20].y = 49;
	tiles[20].h = 16;
	tiles[20].w = 16;

	tiles[21].x = 339;
	tiles[21].y = 49;
	tiles[21].h = 16;
	tiles[21].w = 16;
}


bool ModuleTileMap::Start()
{
	
	tilesReference = App->textures->Load("C:\\Users\\Ruben\\Documents\\Visual Studio 2013\\Projects\\SDL_Game_v5\\SDL Game\\Game\\BombermanTiles.png");
	
	return 1;
}

bool ModuleTileMap::Init()
{
	LOG("TILE INITIATION");
	LoadMap("C:\\Users\\Ruben\\Documents\\Visual Studio 2013\\Projects\\SDL_Game_v5\\SDL Game\\firstLevel.txt");
	PrintMap();
	return true;
}

void ModuleTileMap::LoadMap(char* name)
{
		int x, y;
		FILE *fp;
		char tile[10];
		fp = fopen(name, "rb");

		/* If we can't open the map then exit */

		if (fp == NULL)
		{
			LOG("Failed to open map %s\n", name);

			exit(1);
		}

		/* Read the data from the file into the map */

		for (y = 0; y<MAX_MAP_Y; y++)
		{
			for (x = 0; x<MAX_MAP_X; x++)
			{
					//fscanf(fp, "%s", &map.tile[x][y]);
					fscanf(fp, "%s", tile);

					map.tile[x][y] = atoi(tile);
			}
		}

		/* Close the file afterwards */

		fclose(fp);
}

void ModuleTileMap::PrintMap()const
{
	for (int y = 0; y<MAX_MAP_Y; y++)
	{
		for (int x = 0; x<MAX_MAP_X; x++)
		{
			LOG("%d", map.tile[x][y]);
		}
	}

}


bool ModuleTileMap::CleanUp()
{

	return 0;
}


void ModuleTileMap::BuildMap()
{
	int x, y;

	/* Draw the background */

	


	/* Draw the map */

	for (y = 0; y<MAX_MAP_Y; y++)
	{
		for (x = 0; x<MAX_MAP_X; x++)
		{
			if (map.tile[x][y] == 0)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[0], 0.75f);
			}

			if (map.tile[x][y] == 1)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[1], 0.75f);
			}

			if (map.tile[x][y] == 2)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[2], 0.75f);
			}

			if (map.tile[x][y] == 3)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[3], 0.75f);
			}

			if (map.tile[x][y] == 4)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[4], 0.75f);
			}

			if (map.tile[x][y] == 5)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[5], 0.75f);
			}

			if (map.tile[x][y] == 6)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[6], 0.75f);
			}

			if (map.tile[x][y] == 7)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[7], 0.75f);
			}

			if (map.tile[x][y] == 8)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[8], 0.75f);
			}

			if (map.tile[x][y] == 9)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[9], 0.75f);
			}
			if (map.tile[x][y] == 10)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[10], 0.75f);
			}

			if (map.tile[x][y] == 11)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[11], 0.75f);
			}

			if (map.tile[x][y] == 12)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[12], 0.75f);
			}

			if (map.tile[x][y] == 13)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[13], 0.75f);
			}

			if (map.tile[x][y] == 14)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[14], 0.75f);
			}

			if (map.tile[x][y] == 15)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[15], 0.75f);
			}

			if (map.tile[x][y] == 16)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[16], 0.75f);
			}

			if (map.tile[x][y] == 17)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[17], 0.75f);
			}

			if (map.tile[x][y] == 18)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[18], 0.75f);
			}

			if (map.tile[x][y] == 19)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[19], 0.75f);
			}

			if (map.tile[x][y] == 20)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[20], 0.75f);
			}

			if (map.tile[x][y] == 21)
			{
				App->renderer->Blit(tilesReference, x*TILE_SIZE, y*TILE_SIZE, &tiles[21], 0.75f);
			}

		}
	}
}



update_status ModuleTileMap::Update()
{

	BuildMap();
	LOG("TileMap being drawn");
	return UPDATE_CONTINUE;
}
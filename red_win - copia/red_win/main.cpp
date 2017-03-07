#include "SDL/include/SDL.h"
#include <iostream>
#include <stdio.h>

#pragma comment( lib, "SDL/libx86/SDL2.lib")
#pragma comment( lib, "SDL/libx86/SDL2main.lib")
#define BULLET 2

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	bool close = false;
	bool shoot = false;
	SDL_Window* max;
	SDL_Renderer* maxito;
	SDL_Event event;
	SDL_Surface* image1,*image2,*image3;
	SDL_Texture* tex,*tox,*laser;
	int counter = 0;

	SDL_CreateWindowAndRenderer(800, 800, SDL_RENDERER_PRESENTVSYNC, &max, &maxito);//Create a window
	
	SDL_Rect rect = { 150,175,100,50 };   //Create a rectangle in the position 150,175 with the size 100x50
	SDL_Rect screen = { 0,0,800,800 };
	SDL_Rect shoote[BULLET];
	shoote[0]={ -25,-25,25,25};
	
	
	image1 = SDL_LoadBMP("flappybird.bmp");
	if (image1 == NULL)
	{
		printf("SDL_image Error: %s\n",SDL_GetError());
	}
	image2 = SDL_LoadBMP("8bits.bmp");
	if (image2 == NULL)
	{
		printf("SDL_image Error: %s\n", SDL_GetError());
	}
	image3 = SDL_LoadBMP("laser.bmp");
	if (image3 == NULL)
	{
		printf("SDL_image Error: %s\n", SDL_GetError());
	}

	
	tex = SDL_CreateTextureFromSurface(maxito,image1);
	tox = SDL_CreateTextureFromSurface(maxito, image2);
	laser = SDL_CreateTextureFromSurface(maxito, image3);
	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);
	SDL_FreeSurface(image3);

	while (close==false)  //bucle infinit
	{
		
		SDL_SetRenderDrawColor(maxito, 255, 0, 0, 255);//red
		SDL_RenderClear(maxito); // Clear the window and make it all red
		//SDL_SetRenderDrawColor(maxito, 0, 0, 255, 255);   //Color of the rectangle
		SDL_RenderCopy(maxito, tox, NULL, &screen);//renderitza la textura del rectangle que fa de background( si el renderitzem l'ultim quedara per sobre dels altres)
		
		for (int i = 0; i < 2; i++)
		{
			SDL_RenderCopy(maxito, laser, NULL, &shoote[i]);
		}
	
		if (shoot)
		{
			shoote[counter-1].x = (rect.x+10);
			shoote[counter-1].y = rect.y+(rect.h/3);
			shoot = false;
		}
		SDL_RenderCopy(maxito, tex, NULL, &rect);//renderitza la textura del rectangle petit
		SDL_RenderPresent(maxito);// Render the changes above(per sobre)
		SDL_PollEvent(&event);
		for (int i = 0; i < 2; i++)
		{
			shoote[i].x++;
		}

		switch (event.type)
		{
		case SDL_KEYDOWN:
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
			{
				close = true;
				break;
			}
			case SDLK_UP:
			{
				rect.y--;
				break;
			}
			case SDLK_DOWN:
			{
				rect.y++;
				break;
			}
			case SDLK_RIGHT:
			{
				rect.x++;
				break;
			}
			case SDLK_LEFT:
			{
				rect.x--;
				break;
			}
			case SDLK_SPACE:
			{
				counter++;
				if (counter == BULLET+1)
				{
					counter = 1;
				}
				shoot = true;
				break;
			}
			}
			break;
		}
		}
		SDL_Delay(5);
	}
	SDL_Quit();

	return 0;
}
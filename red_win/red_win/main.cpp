#include "SDL/include/SDL.h"
#include <iostream>
#include <stdio.h>

#pragma comment( lib, "SDL/libx86/SDL2.lib")
#pragma comment( lib, "SDL/libx86/SDL2main.lib")

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	bool close = false;
	SDL_Window* max;
	SDL_Renderer* maxito;
	SDL_Event event;
	SDL_Surface* image1,*image2;
	SDL_Texture* tex,*tox;

	SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_RESIZABLE, &max, &maxito);//Create a window
	SDL_Rect rect = { 150,175,100,50 };   //Create a rectangle in the position 150,175 with the size 100x50
	SDL_Rect screen = { 0,0,800,800 };
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

	tex = SDL_CreateTextureFromSurface(maxito,image1);
	tox = SDL_CreateTextureFromSurface(maxito, image2);
	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);


	SDL_SetRenderDrawColor(maxito, 255, 0, 0, 255);//red
	SDL_RenderClear(maxito); // Clear the window and make it all red

	



	while (close==false)  //bucle infinit
	{
		
		SDL_SetRenderDrawColor(maxito, 255, 0, 0, 255);//red
		SDL_RenderClear(maxito); // Clear the window and make it all red
		
		//SDL_SetRenderDrawColor(maxito, 0, 0, 255, 255);   //Color of the rectangle
		SDL_RenderDrawRect(maxito, &screen);// Render (draw) the edges of the rectangle
		SDL_RenderFillRect(maxito, &screen);//Painting all the rectangle
		SDL_RenderDrawRect(maxito, &rect);// Render (draw) the edges of the rectangle
		SDL_RenderFillRect(maxito, &rect);//Painting all the rectangle
		SDL_RenderCopy(maxito, tox, NULL, &screen);//renderitza la textura del rectangle que fa de background( si el renderitzem l'ultim quedara per sobre dels altres)
		SDL_RenderCopy(maxito, tex, NULL, &rect);//renderitza la textura del rectangle petit
		SDL_RenderPresent(maxito);// Render the changes above(per sobre)
		SDL_PollEvent(&event);

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
			}
			break;
		}
		}
		SDL_Delay(5);
	}

	SDL_Quit();

	return 0;
}
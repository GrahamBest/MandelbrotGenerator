#include <SDL2/SDL.h>
#include <iostream>
#include <complex>

#undef main

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

#define MATH_PI 3.1415

int main(int argc, char* argv[])
{
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL, &window, &renderer);
	SDL_SetWindowPosition(window, 16, 16);

	for (int x = 0; x < WINDOW_WIDTH; x++)
	{
		for (int y = 0; y < WINDOW_HEIGHT; y++)
		{
			std::complex<double> cIterator(0.5 * x / WINDOW_WIDTH, 0.5 * y / WINDOW_HEIGHT);
			std::complex<double> z(0.0, 0.0);
			
			float count = 0;

			while (count < 255.0)
			{
				z = z * z + cIterator;	
				
				if (abs(z) > 2.0)
				{
					break;
				}

				count++;
			}

			SDL_SetRenderDrawColor(renderer, count, count, 255, 255);

			SDL_RenderDrawPoint(renderer, x, y);
		}
	}

	SDL_RenderPresent(renderer);

	printf("Finished!\n");

	std::cin.get();

	SDL_Quit();
}

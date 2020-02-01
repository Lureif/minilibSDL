#include "ft_minilibsdl.h"

bool		renderer_init(SDL_Window **window, SDL_Renderer **renderer)
{
	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
       	SDL_RenderSetLogicalSize(*renderer, WIN_WIDTH, WIN_HEIGHT);
	SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
	SDL_RenderClear(*renderer);
	SDL_RenderPresent(*renderer);
	return (true);
}

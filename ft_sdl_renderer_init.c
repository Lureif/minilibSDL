#include "ft_minilibsdl.h"

bool		renderer_init(SDL_Window *window, SDL_Renderer **renderer, const int dimentions[2])
{
	*renderer = SDL_CreateRenderer(window, -1, 0);
	if (*renderer == NULL)
	{
		sdl_error_handler("SDL", "renderer_init", SDL_ERROR);
		return (false);
	}
	SDL_RenderSetLogicalSize(*renderer, dimentions[0], dimentions[1]);
	SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
	SDL_RenderClear(*renderer);
	SDL_RenderPresent(*renderer);
	return (true);
}

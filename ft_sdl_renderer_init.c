#include "ft_minilibsdl.h"

bool		renderer_init(SDL_Renderer **renderer)
{
       	SDL_RenderSetLogicalSize(*renderer, WIN_WIDTH, WIN_HEIGHT);
	SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
	SDL_RenderClear(*renderer);
	SDL_RenderPresent(*renderer);
	return (true);
}

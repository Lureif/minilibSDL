#include "ft_minilibsdl.h"

bool	surface_init(SDL_Window *window, SDL_Surface **win_surface)
{
	if (!(*win_surface = SDL_GetWindowSurface(window)))
	{
		sdl_error_handler("SDL", "surface_init", SDL_ERROR);
		return (false);
	}
	return (true);
}

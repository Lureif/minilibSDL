#include "ft_minilibsdl.h"

bool	window_init(SDL_Window **window, const char *WIN_NAME, int WIDTH, int HEIGHT)
{
	if (!WIN_NAME || !WIDTH || !HEIGHT)
	{
		error_handler("USER", "window_init", MISSING_WIN_SPEC);
		return (false);
	}
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		error_handler("SDL", "window_init", SDL_ERROR);
		return (false);
	}
	if (!(*window = SDL_CreateWindow(WIN_NAME,
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					WIDTH,
					HEIGHT,
					/*SDL_WINDOW_SHOWN*/ 0)))
	{
		error_handler("SDL", "window_init", SDL_ERROR);
		return (false);
	}
	return (true);
}

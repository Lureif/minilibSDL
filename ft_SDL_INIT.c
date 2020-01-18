#include "ft_sdlh.h"

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

bool	surface_init(SDL_Surface **win_surface, SDL_Window *window)
{
	if (!(*win_surface = SDL_GetWindowSurface(window)))
	{
		error_handler("SDL", "surface_init", SDL_ERROR);
		return (false);
	}
	return (true);
}

bool		renderer_init(SDL_Renderer **renderer)
{
       	SDL_RenderSetLogicalSize(*renderer, WIN_WIDTH, WIN_HEIGHT);
	SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
	SDL_RenderClear(*renderer);
	SDL_RenderPresent(*renderer);
	return (true);
}

void		event_loop(SDL_Window *window)
{
	SDL_Event 	event;	
	bool 		STATE;

	STATE = true;
	while (STATE == true)
	{
		SDL_UpdateWindowSurface(window);
		while (SDL_PollEvent(&event))
		{
			/* ================================================= */
			/* =============== EVENTS GO HERE ==================*/
			/* ================================================= */
			if (event.type == SDL_QUIT ||
			    (event.type == SDL_KEYUP &&
			     event.key.keysym.sym == SDLK_ESCAPE))
			{
				STATE = false;
				break;
			}
			/* render_to_window(renderer, something you cooked up); */
		}
		SDL_Delay(16); // 16 for 60fps
	}
}

#include "ft_minilibsdl.h"

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

#include "ft_sdlh.h"

void	ft_sdl_cleanup(t_SDL_OBJS *sdl_objs)
{
	SDL_DestroyRenderer(sdl_objs->render_surface);
	SDL_DestroyWindow(sdl_objs->window);
}

bool	ft_sdl_full_init(t_SDL_OBJS *sdl_objs) // this is going to have to change.
{
	unsigned char state[3];

	state[0] = window_init(&sdl_objs->window, WIN_TITLE, WIN_WIDTH, WIN_HEIGHT);
	state[1] = surface_init(&sdl_objs->win_surface, sdl_objs->window);
	state[2] = renderer_init(&sdl_objs->render_surface);
	return(state[0] & state[1] & state[2]);
}

int	main(__attribute__((unused)) int ac, __attribute__((unused)) char **av)
{
	t_SDL_OBJS sdl_objs;

	bzero(&sdl_objs, sizeof(sdl_objs));
	if (ft_sdl_full_init(&sdl_objs) == false)
	{
		ft_sdl_cleanup(&sdl_objs);
		printf("quitting sdl...\n");
		SDL_Quit();
		return (0);
	}
	/*=================================================*/
	/*======== PROJECT SPECIFIC CODE GOES HERE ========*/
	/*=================================================*/
	event_loop(sdl_objs.window);
	ft_sdl_cleanup(&sdl_objs);
	SDL_Quit();
	return (0);
}

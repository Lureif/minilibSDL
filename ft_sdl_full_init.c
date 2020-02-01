#include "ft_minilibsdl.h"

bool	ft_sdl_full_init(t_SDL_OBJS *sdl_objs) // this is going to have to change.
{
	unsigned char state[3];

	state[0] = window_init(&sdl_objs->window, WIN_TITLE, WIN_WIDTH, WIN_HEIGHT);
	state[1] = surface_init(&sdl_objs->win_surface, sdl_objs->window);
	state[2] = renderer_init(&sdl_objs->window, &sdl_objs->render_surface);
	return(state[0] & state[1] & state[2]);
}

#include "ft_minilibsdl.h"

bool	ft_sdl_full_init(t_SDL_OBJS *sdl_objs, bool renderer) // this is going to have to change.
{
	unsigned char state[2];

	state[0] = window_init(&sdl_objs->window, WIN_TITLE, WIN_WIDTH, WIN_HEIGHT);
	if (renderer == true)
		state[1] = renderer_init(sdl_objs->window, &sdl_objs->render_surface);
	else
		state[1] = surface_init(&sdl_objs->win_surface, sdl_objs->window);
	return(state[0] & state[1]);
}

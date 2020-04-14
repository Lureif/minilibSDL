#include "ft_minilibsdl.h"

bool	ft_sdl_full_init(t_SDL_OBJS *sdl_objs, bool rendererp)
{
	unsigned char state[2];

	state[0] = window_init(&sdl_objs->window, WIN_TITLE, WIN_WIDTH, WIN_HEIGHT);
	if (rendererp == true)
		state[1] = renderer_init(sdl_objs->window, &sdl_objs->renderer);
	else
		state[1] = surface_init(sdl_objs->window, &sdl_objs->surface);
	return(state[0] & state[1]);
}

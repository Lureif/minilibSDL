#include "ft_minilibsdl.h"

bool	ft_sdl_full_init(t_SDL_OBJS *sdl_objs, const size_t dimentions[2], const char *win_title, const bool rendererp)
{
	unsigned char state[2];

	state[0] = window_init(&sdl_objs->window, win_title, dimentions[0], dimentions[1]);
	if (rendererp == true)
		state[1] = renderer_init(sdl_objs->window, &sdl_objs->renderer);
	else
		state[1] = surface_init(sdl_objs->window, &sdl_objs->surface);
	return(state[0] & state[1]);
}

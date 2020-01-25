#include "ft_minilibsdl.h"

void	ft_sdl_cleanup(t_SDL_OBJS *sdl_objs)
{
	SDL_FreeSurface(sdl_objs->win_surface);
	SDL_DestroyRenderer(sdl_objs->render_surface);
	SDL_DestroyWindow(sdl_objs->window);
}

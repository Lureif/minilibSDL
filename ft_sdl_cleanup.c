#include "ft_minilibsdl.h"

void	ft_sdl_cleanup(t_SDL_OBJS *sdl_objs, bool surfacep)
{
	if (surfacep == true)
	{
		SDL_FreeSurface(sdl_objs->win_surface);
		printf("freed surface\n");
	}
	if (sdl_objs->render_surface)
	{
		SDL_DestroyRenderer(sdl_objs->render_surface);
		printf("doestroyed renderer\n");
	}
	if (sdl_objs->window)
	{
		SDL_DestroyWindow(sdl_objs->window);
		printf("destroyed window\n");
	}
}

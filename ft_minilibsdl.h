#ifndef FT_SDLH_H
# define FT_SDLH_H
# include <SDL2/SDL.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# define WIN_TITLE "INSERT WINDOW TITLE HERE"
# define WIN_HEIGHT 500
# define WIN_WIDTH 500
# define NO_FLAGS 0

typedef	struct		s_SDL_OBJS
{
	SDL_Window	*window;
	SDL_Surface	*win_surface;
	SDL_Renderer	*render_surface;
}			t_SDL_OBJS;

enum	err_codes
{
	SDL_ERROR,
	MISSING_WIN_SPEC,
	/*************************************/
	/*add other non sdl error codes here */
	/*************************************/
	__ERR_CODE_NUMBER
};

/* 
** boilerplate
*/

/*
** --- Setup functions
*/

/*
** --------------- init functions (in order)
*/

bool			ft_sdl_full_init(t_SDL_OBJS *sdl_objs);
bool			window_init(SDL_Window **window, const char *WIN_NAME, int WIDTH, int HEIGHT);
bool			renderer_init(SDL_Renderer **renderer);
bool			surface_init(SDL_Surface **win_surface, SDL_Window *window);
void			ft_sdl_cleanup(t_SDL_OBJS *sdl_objs);

/*
** --------------- event stuff 
*/
void			event_loop(SDL_Window *window);
void			render_to_window(SDL_Renderer *renderer, SDL_Rect what_thy_want);

/*
**  --- error hanling
*/
void			error_handler(const char *err_source, const char *err_function, int err_code);
void			strcat_w_endl(char *stackstr, const char *txt, const char *endl_char);

/*
** end boilerplate
*/

#endif

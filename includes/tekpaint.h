/*
** tekpaint.h for  in /home/thomas/Documents/epitech/gfx_tekpaint
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Mon Jan 25 10:53:54 2016 thomas
** Last update Tue Jan 26 21:59:50 2016 thomas
*/

#ifndef __TEKPAINT_H__
# define __TEKPAINT_H__

# include <lapin.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <dirent.h>

# define MY_BLUE 0x2E2E2E
# define DEGREES_TO_RADIANS(angleDegrees) (angleDegrees * M_PI / 180.0)

# define PEN_TOOL 2
# define EMPTY_CIRCLE_TOOL 4
# define CIRCLE_TOOL 8
# define SQUARE_TOOL 16
# define LINE_TOOL 32
# define BUCKET_TOOL 64
# define ERASER_TOOL 128
# define BMP_LOAD_TOOL 256
# define EMPTY_SQUARE_TOOL 512

# define PALETTE_WIDTH 400
# define PALETTE_HEIGHT 400

# define WIN_NAME "Tekpaint - henon_t/linder_l/bauer_b/strass_v"
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# define WIN_FULLSCREEN false
# define WIN_REFRESH_PER_SEC 50

# define LOGO_PATH "res/logo.bmp"
# define MUSIC_PATH "res/theme.ogg"

# define ALPHA_WIDTH 28
# define ALPHA_HEIGHT 48

# define EXPLORER_WIDTH 600
# define EXPLORER_HEIGHT 500
# define EXPLORER_DISPLAY_NBR 10

typedef	struct		s_linkedlist
{
  struct s_linkedlist	*next;
  void			*data;
}			t_linkedlist;

typedef struct          s_workplan
{
  t_bunny_pixelarray    *buffer;
  int                   width;
  int                   height;
}                       t_workplan;

typedef struct          s_window
{
  t_bunny_window        *win;
  unsigned int          width;
  unsigned int          height;
  char                  fullscreen;
  char                  *name;
  unsigned char         frequency;
  t_bunny_pixelarray    *background;
}                       t_window;

typedef struct          s_toolbar
{
  t_bunny_pixelarray    *buffer;
  int                   width;
  int                   height;
  t_linkedlist		*buttons;
}                       t_toolbar;

typedef struct          s_bunny_square
{
  t_bunny_position      pos;
  int                   width;
  int                   height;
}                       t_bunny_square;

typedef struct          s_palette
{
  unsigned int	        width;
  unsigned int		height;
  t_bunny_window	*win;
  t_bunny_pixelarray	*buffer;
}                       t_palette;

struct s_tekpaint;

typedef struct		s_explorer
{
  char			*win_name;
  t_bunny_window	*win;
  t_bunny_pixelarray	*buffer;
  char			*extension;
  char			*current_path;
  char			*img;
  t_linkedlist		*files;
}			t_explorer;

typedef struct          s_tool
{
  unsigned int	        color;
  unsigned int		current_tool;
  unsigned int		thickness;
  t_bunny_pixelarray	*bmp_buffer_tmp;
  t_bunny_position	*origin;
  t_palette		palette;
  t_bunny_pixelarray	*font_buffer;
  t_explorer		*explorer;
}                       t_tool;

typedef struct          s_tekpaint
{
  t_workplan		workplan;
  t_window		window;
  t_toolbar		toolbar;
  t_tool		tool;
  char			playmusic;
}                       t_tekpaint;

typedef struct		s_button
{
  int			width;
  int			height;
  t_bunny_position	pos;
  t_bunny_pixelarray	*buffer;
  char			(*on_click)(t_tekpaint*);
}			t_button;

typedef struct	s_header_bmp
{
  char		signature[2];
  char		total_size[4];
  char		reserved[4];
  char		offset_pixels[4];
} __attribute__ ((packed)) t_header_bmp;

typedef struct s_header_img_bmp
{
  char         size_header_img[4];
  char         img_width[4];
  char         img_height[4];
  char         nbr_plans[2];
  char         bits_per_pixel[2];
  char         compression_method[4];
  char         total_size_img[4];
  char         horizontal_resolution[4];
  char         vertical_resolution[4];
  char         nbr_colors_palette[4];
  char         nbr_important_colors_palette[4];
} __attribute__ ((packed)) t_header_img_bmp;

typedef struct		s_line
{
  unsigned int		color;
  double		coef;
  double		temp;
  t_bunny_square	square;
}			t_line;

typedef struct			s_rgb_color
{
  unsigned char			blue;
  unsigned char			green;
  unsigned char			red;
  unsigned char			alpha;
} __attribute__ ((packed))	t_rgb_color;

typedef struct			s_dim
{
  unsigned int			width;
  unsigned int			height;
}				t_dim;

typedef struct			s_gfx_chars
{
  char				c;
  t_bunny_position		pos;
}				t_gfx_chars;

static t_gfx_chars gfx_chars[69] = {
  { 'a', { 5, 5 } },
  { 'b', { 6, 5 } },
  { 'c', { 7, 5 } },
  { 'd', { 8, 5 } },
  { 'e', { 9, 5 } },
  { 'f', { 10, 5 } },
  { 'g', { 11, 5 } },
  { 'h', { 0, 6 } },
  { 'i', { 1, 6 } },
  { 'j', { 2, 6 } },
  { 'k', { 3, 6 } },
  { 'l', { 4, 6 } },
  { 'm', { 5, 6 } },
  { 'n', { 6, 6 } },
  { 'o', { 7, 6 } },
  { 'p', { 8, 6 } },
  { 'q', { 9, 6 } },
  { 'r', { 10, 6 } },
  { 's', { 11, 6 } },
  { 't', { 0, 7 } },
  { 'u', { 1, 7 } },
  { 'v', { 2, 7 } },
  { 'w', { 3, 7 } },
  { 'x', { 4, 7 } },
  { 'y', { 5, 7 } },
  { 'z', { 6, 7 } },
  { 'A', { 9, 2 } },
  { 'B', { 10, 2 } },
  { 'C', { 11, 2 } },
  { 'D', { 0, 3 } },
  { 'E', { 1, 3 } },
  { 'F', { 2, 3 } },
  { 'G', { 3, 3 } },
  { 'H', { 4, 3 } },
  { 'I', { 5, 3 } },
  { 'J', { 6, 3 } },
  { 'K', { 7, 3 } },
  { 'L', { 8, 3 } },
  { 'M', { 9, 3 } },
  { 'N', { 10, 3 } },
  { 'O', { 11, 3 } },
  { 'P', { 0, 4 } },
  { 'Q', { 1, 4 } },
  { 'R', { 2, 4 } },
  { 'S', { 3, 4 } },
  { 'T', { 4, 4 } },
  { 'U', { 5, 4 } },
  { 'V', { 6, 4 } },
  { 'W', { 7, 4 } },
  { 'X', { 8, 4 } },
  { 'Y', { 9, 4 } },
  { 'Z', { 10, 4 } },
  { ' ', { 0, 0 } },
  { '!', { 1, 0 } },
  { '"', { 2, 0 } },
  { '.', { 2, 1 } },
  { '-', { 1, 1 } },
  { ',', { 0, 1 } },
  { '/', { 3, 1 } },
  { '0', { 4, 1 } },
  { '1', { 5, 1 } },
  { '2', { 6, 1 } },
  { '3', { 7, 1 } },
  { '4', { 8, 1 } },
  { '5', { 9, 1 } },
  { '6', { 10, 1 } },
  { '7', { 11, 1 } },
  { '8', { 0, 2 } },
  { '9', { 1, 2 } }
};

void set_max_heap_size(size_t);

/*
** linked_lists.c
*/
t_linkedlist	*create_elem(void *);
char		append_elem(t_linkedlist **, void *);
void		free_list(t_linkedlist **);
unsigned int	elem_count(t_linkedlist *);

/*
** main.c
*/
t_bunny_response	main_loop(void *);
char			set_tool(t_bunny_position *, t_tekpaint *);

/*
** io.c
*/
char			save_pixelarray(char *, t_bunny_pixelarray *);
t_bunny_pixelarray	*load_pixelarray(char *, int, int);

/*
** bases.c
*/
void		blit_pixelarrays(t_bunny_pixelarray *, t_bunny_pixelarray *,
  t_bunny_position *);
unsigned int	get_pixel(t_bunny_pixelarray *, int, int);
void		set_pixel(t_bunny_pixelarray *, unsigned int, int, int);
void		fill_buffer(t_bunny_pixelarray *, unsigned);
void		set_rgb_pixel(t_bunny_pixelarray *buffer, unsigned int pixel,
			      t_rgb_color *color);

/*
** init.c
*/
char init_toolbar(t_window *, t_toolbar *);
char init_workplan(t_toolbar *, t_window *, t_workplan *);
char init_background(t_window *);
char init_window(t_tekpaint *);
char init_tool(t_tool *);
char init_music();
char init_logo(t_toolbar *);

/*
** bmp.c
*/
t_bunny_pixelarray	*load_bmp(char *);
t_bunny_pixelarray	*convert_to_pixelarray(int, int, int, unsigned char);
void paste_bmp(t_tekpaint *tekpaint, t_bunny_position *pos);

/*
** buttons.c
*/

t_button	*init_bt(t_bunny_pixelarray *,
    t_bunny_pixelarray *, char (*event)(t_tekpaint*));
void		init_buttons(t_linkedlist **, t_bunny_pixelarray *);
void		init_bts(t_linkedlist **, t_bunny_pixelarray *);
void		init_bts2(t_linkedlist **, t_bunny_pixelarray *);

/*
** buttons_event.c
*/
char on_palette_click(t_tekpaint *);
char on_pen_click(t_tekpaint *);
char on_circle_click(t_tekpaint *);
char on_empty_circle_click(t_tekpaint *);
char on_square_click(t_tekpaint *);
char on_line_click(t_tekpaint *);
char on_reset_workplan_click(t_tekpaint *);
char on_bucket_click(t_tekpaint *);
char on_less_click(t_tekpaint *);
char on_plus_click(t_tekpaint *);
char on_eraser_click(t_tekpaint *);
char on_save_tkp_click(t_tekpaint *);
char on_load_bmp_click(t_tekpaint *);
char on_load_tkp_click(t_tekpaint *);
char on_empty_square_click(t_tekpaint *);

/*
** events.c
*/
t_bunny_response on_win_click(t_bunny_event_state,
  t_bunny_mousebutton, void *);
char	on_mouse_move(t_tekpaint *, t_bunny_position *);

/*
** pen.c
*/
void pen(t_bunny_pixelarray *, t_bunny_position *,
  unsigned int, t_bunny_square);

/*
** line.c
*/
void right_abs(t_bunny_pixelarray *, t_bunny_position *,
  t_bunny_position post, t_line);
void left_abs(t_bunny_pixelarray *, t_bunny_position *,
  t_bunny_position, t_line);
void ordonate(t_bunny_pixelarray *, t_bunny_position *,
  t_bunny_position, t_line);
void line(t_bunny_pixelarray *, t_bunny_square,
  t_bunny_position, unsigned int);
void make_line(t_bunny_pixelarray *, t_bunny_position *,
  unsigned int, t_bunny_square);

/*
** circle.c
*/
void my_set_empty_circle(t_bunny_pixelarray *, t_bunny_position *,
			 t_bunny_position *, unsigned int);
void my_set_circle(t_bunny_pixelarray *, t_bunny_position *,
  t_bunny_position *, unsigned int);
void empty_circle(t_bunny_pixelarray *, t_bunny_position *, unsigned int);
void circle(t_bunny_pixelarray *, t_bunny_position *, unsigned int);

/*
** square.c
*/
void square_xp_yp(t_bunny_pixelarray *, t_bunny_square *,  unsigned int);
void square_xp_yn(t_bunny_pixelarray *, t_bunny_square *, unsigned int);
void square_xn_yp(t_bunny_pixelarray *, t_bunny_square *, unsigned int);
void square_xn_yn(t_bunny_pixelarray *, t_bunny_square *, unsigned int);
void square(t_bunny_pixelarray *, t_bunny_square *, unsigned int);
void make_square(t_bunny_pixelarray *, t_bunny_position *, unsigned int);

/*
** empty_square.c
*/
void empty_square(t_bunny_pixelarray *, t_bunny_square,
  unsigned int, int);
void make_empty_square(t_bunny_pixelarray *, t_bunny_position *,
  unsigned int, int);

/*
** bucket.c
*/
char		bucket(t_tekpaint *);

/*
** buttons/
*/
t_bunny_pixelarray	*buttons_circle();
t_bunny_pixelarray	*buttons_circle_border();
t_bunny_pixelarray	*buttons_empty_circle();
t_bunny_pixelarray	*buttons_empty_circle_border();
t_bunny_pixelarray	*buttons_less();
t_bunny_pixelarray	*buttons_less_border();
t_bunny_pixelarray	*buttons_line();
t_bunny_pixelarray	*buttons_line_border();
t_bunny_pixelarray	*buttons_more();
t_bunny_pixelarray	*buttons_more_border();
void			draw_pen(t_bunny_pixelarray *);
t_bunny_pixelarray	*buttons_pen();
t_bunny_pixelarray	*buttons_pen_border();
t_bunny_pixelarray	*buttons_square();
t_bunny_pixelarray	*buttons_square_border();
t_bunny_pixelarray	*buttons_empty_square_border();
void			init_icon(t_bunny_pixelarray *);
void			init_icon_border(t_bunny_pixelarray *);
t_bunny_pixelarray      *buttons_bucket_border();
t_bunny_pixelarray      *buttons_bucket();
void                    buttons_bucket_2(t_bunny_pixelarray *);
t_bunny_pixelarray	*buttons_clean_border();
t_bunny_pixelarray	*buttons_empty_border();
t_bunny_pixelarray	*buttons_palette_border();
t_bunny_pixelarray	*buttons_color();
t_bunny_pixelarray	*buttons_erase();
t_bunny_pixelarray	*buttons_load_bmp();
void			next_load_bmp(t_bunny_pixelarray *pix,
				      t_bunny_square squar);
void			next_load2_bmp(t_bunny_pixelarray *pix,
				       t_bunny_square squar);
void			next_load2(t_bunny_pixelarray *pix,
				   t_bunny_square squar);
void			next_load(t_bunny_pixelarray *pix,
				  t_bunny_square squar);
t_bunny_pixelarray	*buttons_load();
void			next1(t_bunny_pixelarray *pix,
			      t_bunny_square squar);
void			array(t_bunny_pixelarray *pix,
			      t_bunny_square squar);
t_bunny_pixelarray	*buttons_save();
void			next1_bmp(t_bunny_pixelarray *pix,
				  t_bunny_square squar);
void			array_bmp(t_bunny_pixelarray *pix,
				  t_bunny_square squar);
t_bunny_pixelarray	*buttons_save_bmp();

/*
** eraser.c
*/
void eraser(t_bunny_pixelarray *, t_bunny_position *, t_bunny_square);

/*
** my.c
*/
void	my_putstr(char *);
void	my_putchar(char);
int	my_strlen(char *);
char	*my_strstr(char *, char *);

/*
** util.c
*/
void	clean_buffer(char *, int);
char	remove_carriage_return(char *);
char	*my_strcat(char *str1, char *str2);
char	*concat_path(char *str1, char *str2);
int	my_strcmp(char *s1, char *s2);

/*
** tkp.c
*/
char			save_pixelarray(char *, t_bunny_pixelarray *);
char			save_tkp(t_tekpaint *);
char			load_tkp(t_tekpaint *);
t_bunny_pixelarray	*load_pixelarray(char *, int, int);

/*
** config_file.c
*/
char		load_config(t_tekpaint *, char *);

/*
** palette.c
*/
t_bunny_response	main_loop_palette(void *);
t_bunny_response	on_palette_event_click(t_bunny_event_state,
  t_bunny_mousebutton, void *);
char			open_palette(t_tekpaint *);
void palette_reset(t_palette *);

/*
** font.c
*/
char	font_check_valid_char(char c);
char	font_put_at(t_bunny_pixelarray *workplan_buffer,
	t_bunny_pixelarray *font_buffer, t_bunny_position *pos_workplan,
	t_bunny_position *pos_font);
char	font_putstr(t_tekpaint *tekpaint, t_bunny_pixelarray *buffer,
		    t_bunny_position *pos_in_buffer, char *str);

/*
** explorer.c
*/
t_bunny_response main_loop_explorer(void *data);
char explorer_on_enter(t_tekpaint *tekpaint, t_explorer *explorer, int *i);
t_bunny_response explorer_on_key(t_bunny_event_state state,
				 t_bunny_keysym key, void *data);
char	explorer_reset(t_tekpaint *tekpaint, t_explorer *explorer);
char	explorer(t_tekpaint *tekpaint, t_explorer *explorer);
char		*get_focused_file_name(t_explorer *explorer, int start);
char	explorer_on_enter_file(char *file_name, char *path, t_explorer *explorer);

#endif

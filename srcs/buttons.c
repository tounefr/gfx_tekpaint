/*
** buttons.c for  in /home/henon_t/gfx_tekpaint
**
** Made by Thomas Henon
** Login   <henon_t@epitech.net>
**
** Started on  Wed Jan 20 17:33:09 2016 Thomas Henon
** Last update Tue Jan 26 20:11:35 2016 Thomas Henon
*/

#include "tekpaint.h"

t_button		*init_bt(t_bunny_pixelarray *buffer,
				 t_bunny_pixelarray *design_buffer,
				 char (*event)(t_tekpaint*))
{
  t_button		*button;
  t_bunny_pixelarray	*buffer_bt;
  static unsigned int	x_position = 10;

  if (NULL == (button = bunny_malloc(sizeof(*button))))
    return (NULL);
  if (!buffer)
    return (NULL);
  button->width = 50;
  button->height = 50;
  button->pos.x = x_position;
  x_position = x_position + 65;
  button->pos.y = 5;
  button->on_click = event;
  buffer_bt = design_buffer;
  blit_pixelarrays(buffer, buffer_bt, &button->pos);
  bunny_delete_clipable(&buffer_bt->clipable);
  return (button);
}

void		init_bts(t_linkedlist **bts, t_bunny_pixelarray *buff)
{
  *bts = NULL;
  append_elem(bts, init_bt(buff, buttons_pen_border(),
			   &on_pen_click));
  append_elem(bts, init_bt(buff, buttons_circle_border(),
			   &on_circle_click));
  append_elem(bts, init_bt(buff, buttons_empty_circle_border(),
			   &on_empty_circle_click));
  append_elem(bts, init_bt(buff, buttons_square_border(),
			   &on_square_click));
  append_elem(bts, init_bt(buff, buttons_empty_square_border(),
			   &on_empty_square_click));
  append_elem(bts, init_bt(buff, buttons_line_border(),
			   &on_line_click));
  init_bts2(bts, buff);
}

void		init_bts2(t_linkedlist **bts, t_bunny_pixelarray *buff)
{
  append_elem(bts, init_bt(buff, buttons_erase(),
			   &on_eraser_click));
  append_elem(bts, init_bt(buff, buttons_more_border(),
			   &on_plus_click));
  append_elem(bts, init_bt(buff, buttons_less_border(),
			   &on_less_click));
  append_elem(bts, init_bt(buff, buttons_clean_border(),
			   &on_reset_workplan_click));
  append_elem(bts, init_bt(buff, buttons_color(),
			   &on_palette_click));
  append_elem(bts, init_bt(buff, buttons_load(),
			   &on_load_tkp_click));
  append_elem(bts, init_bt(buff, buttons_save(),
			   &on_save_tkp_click));
  append_elem(bts, init_bt(buff, buttons_load_bmp(),
			   &on_load_bmp_click));
}

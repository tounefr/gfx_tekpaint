/*
** bases2.c for  in /home/henon_t/gfx_tekpaint/srcs
** 
** Made by Thomas Henon
** Login   <henon_t@epitech.net>
** 
** Started on  Tue Jan 26 19:53:04 2016 Thomas Henon
** Last update Tue Jan 26 19:53:31 2016 Thomas Henon
*/

#include "tekpaint.h"

void	blit_pixelarrays2(t_bunny_pixelarray *background,
			 t_bunny_pixelarray *buffer,
			 t_bunny_position *pos,
			 t_dim *dim)
{
  int	x;
  int	y;

  y = 0;
  while (y < dim->height)
    {
      x = 0;
      while (x < dim->width)
	{
	  set_pixel(background,
	    get_pixel(buffer, x + buffer->clipable.clip_x_position,
	    y + buffer->clipable.clip_y_position),
	    x + pos->x,
	    y + pos->y);
	  x++;
	}
      y++;
    }
}

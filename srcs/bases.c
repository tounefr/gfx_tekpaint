/*
** bases.c for  in /home/henon_t/gfx_tekpaint
**
** Made by Thomas Henon
** Login   <henon_t@epitech.net>
**
** Started on  Sat Jan 23 11:54:08 2016 Thomas Henon
** Last update Tue Jan 26 20:43:08 2016 thomas
*/

#include "tekpaint.h"

void		fill_buffer(t_bunny_pixelarray *buffer,
			    unsigned color)
{
  int		i;
  unsigned int	dim;

  i = 0;
  dim = buffer->clipable.clip_width * buffer->clipable.clip_height;
  while (i < dim)
    ((t_color*)buffer->pixels)[i++].full = color;
}

void		set_pixel(t_bunny_pixelarray *buffer,
			  unsigned int color,
			  int x,
			  int y)
{
  unsigned int	index;

  index = buffer->clipable.clip_width * y + x;
  if (x >= 0 && x <= buffer->clipable.clip_width &&
      y >= 0 && y <= buffer->clipable.clip_height)
    ((t_color*)buffer->pixels)[index].full = color;
}

void	set_rgb_pixel(t_bunny_pixelarray *buffer,
		      unsigned int pixel,
		      t_rgb_color *color)
{
  ((t_color*)buffer->pixels)[pixel].argb[RED_CMP] = color->red;
  ((t_color*)buffer->pixels)[pixel].argb[GREEN_CMP] = color->green;
  ((t_color*)buffer->pixels)[pixel].argb[BLUE_CMP] = color->blue;
}

unsigned int	get_pixel(t_bunny_pixelarray *buffer,
			  int x,
			  int y)
{
  unsigned int	color;
  unsigned int	i;

  i = buffer->clipable.clip_width * y + x;
  if (x >= 0 && x <= buffer->clipable.clip_width &&
      y >= 0 && y <= buffer->clipable.clip_height)
    color = (((t_color*)buffer->pixels)[i].full);
  else
    color = 0;
  return (color);
}

void	blit_pixelarrays(t_bunny_pixelarray *background,
			 t_bunny_pixelarray *buffer,
			 t_bunny_position *pos)
{
  int	x;
  int	y;

  y = pos->y;
  while (y < (pos->y + buffer->clipable.clip_height))
    {
      x = pos->x;
      while (x < (pos->x + buffer->clipable.clip_width))
	{
	  if (x < background->clipable.clip_width &&
	      y < background->clipable.clip_height)
	    {
	      set_pixel(background, get_pixel(buffer,
	      x-pos->x + buffer->clipable.clip_x_position,
	      y-pos->y + buffer->clipable.clip_y_position), x, y);
	    }
	  x++;
	}
      y++;
    }
}

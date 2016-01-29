/*
** font.c for gfx_tekpaint in /home/thomas/Documents/epitech/gfx_tekpaint/srcs
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Tue Jan 26 00:27:15 2016 Thomas HENON
** Last update Tue Jan 26 20:07:46 2016 Thomas Henon
*/

#include "tekpaint.h"

char			font_put_at(t_bunny_pixelarray *workplan_buffer,
				    t_bunny_pixelarray *font_buffer,
				    t_bunny_position *pos_workplan,
				    t_bunny_position *pos_font)
{
  t_dim			dim;
  t_bunny_position	pos;

  dim.width = ALPHA_WIDTH;
  dim.height = ALPHA_HEIGHT;
  font_buffer->clipable.clip_x_position = 48 * pos_font->x - 3;
  font_buffer->clipable.clip_y_position = 48 * pos_font->y;
  blit_pixelarrays2(workplan_buffer, font_buffer, pos_workplan, &dim);
}

void	font_set_colors(t_bunny_pixelarray *buffer,
			unsigned int background_color,
			unsigned int letters_color)
{
  int	row;
  int	col;

  row = 0;
  while (row < buffer->clipable.clip_height)
    {
      col = 0;
      while (col < buffer->clipable.clip_width)
	{
	  if (get_pixel(buffer, col, row) == BLACK)
	    set_pixel(buffer, background_color, col, row);
	  if (get_pixel(buffer, col, row) == WHITE)
	    set_pixel(buffer, letters_color, col, row);
	  col++;
	}
      row++;
    }
}

char	font_putstr(t_tekpaint *tekpaint,
		    t_bunny_pixelarray *buffer,
		    t_bunny_position *pos_in_buffer,
		    char *str)
{
  int	i;
  int	i2;

  i = 0;
  while (str && str[i] != '\0')
    {
      i2 = 0;
      while (i2 < 59)
	{
	  if (gfx_chars[i2].c == str[i])
	    {
	      font_put_at(buffer, tekpaint->tool.font_buffer,
			  pos_in_buffer, &(gfx_chars[i2].pos));
	      pos_in_buffer->x += ALPHA_WIDTH;
	    }
	  i2++;
	}
      i++;
    }
  return (1);
}

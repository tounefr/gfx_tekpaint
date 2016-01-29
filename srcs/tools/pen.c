/*
** pen.c for  in /home/thomas/Documents/epitech
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Mon Jan 25 10:40:36 2016 thomas
** Last update Tue Jan 26 20:16:24 2016 Thomas Henon
*/

#include "tekpaint.h"

void				pen(t_bunny_pixelarray *pix,
				    t_bunny_position *pos_mouse,
				    unsigned int color,
				    t_bunny_square squar)
{
  static t_bunny_position	posp;
  static int			is_pass = 0;
  const  bool			*key;

  key = bunny_get_mouse_button();
  if (is_pass == 0)
    {
      posp = *pos_mouse;
      is_pass = 1;
    }
  if (key[BMB_LEFT] == true)
    {
      squar.pos = posp;
      line(pix, squar, *pos_mouse, color);
    }
  posp = *pos_mouse;
}

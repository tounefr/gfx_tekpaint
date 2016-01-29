/*
** square2.c for  in /home/thomas/Documents/epitech
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Mon Jan 25 10:57:25 2016 thomas
** Last update Mon Jan 25 11:01:13 2016 thomas
*/

#include "tekpaint.h"

void				make_square(t_bunny_pixelarray *pix,
					    t_bunny_position *pos_mouse,
					    unsigned int color)
{
  static t_bunny_position	origin;
  static int			clik;
  const  bool			*key;
  t_bunny_square		squar;

  key = bunny_get_mouse_button();
  if (key[BMB_LEFT] == true && clik == 0)
    {
      origin = *pos_mouse;
      clik = 1;
    }
  if (key[BMB_LEFT] == false && clik == 1)
    {
      squar.pos = origin;
      squar.width = pos_mouse->x - origin.x;
      squar.height = pos_mouse->y - origin.y;
      square(pix, &squar, color);
      clik = 0;
    }
}

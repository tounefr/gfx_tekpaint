/*
** empty_square.c for  in /home/bauer_b/rendu/gfx_tekpaint/srcs
**
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
**
** Started on  Sun Jan 24 14:30:44 2016 Aurélien BAUER
** Last update Tue Jan 26 20:42:18 2016 thomas
*/

#include "tekpaint.h"

void				empty_square(t_bunny_pixelarray *pix,
					     t_bunny_square squar,
					     unsigned int color,
					     int size)
{
  t_bunny_position		pos2;
  t_bunny_position		pos3;
  t_bunny_position		pos4;

  pos2.x = squar.pos.x + squar.width;
  pos2.y = squar.pos.y;
  pos3.x = squar.pos.x + squar.width;
  pos3.y = squar.pos.y + squar.height;
  pos4.x = squar.pos.x;
  pos4.y = squar.pos.y + squar.height;
  squar.width = size;
  squar.height = size;
  line(pix, squar, pos2, color);
  line(pix, squar, pos4, color);
  squar.pos = pos2;
  line(pix, squar, pos3, color);
  squar.pos = pos4;
  line(pix, squar, pos3, color);
}

void				make_empty_square(t_bunny_pixelarray *pix,
						  t_bunny_position *pos_mouse,
						  unsigned int color,
						  int size)
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
      empty_square(pix, squar, color, size);
      clik = 0;
    }
}

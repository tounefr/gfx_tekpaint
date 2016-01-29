/*
** buttons_square.c for  in /home/bauer_b/rendu/gfx_tekpaint
**
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
**
** Started on  Fri Jan 22 18:26:53 2016 Aurélien BAUER
** Last update Sun Jan 24 19:14:03 2016 Thomas Henon
*/

#include "tekpaint.h"

t_bunny_pixelarray	*buttons_empty_square_border()
{
  t_bunny_pixelarray	*pix;
  t_bunny_square	squar;
  t_bunny_position	pos;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);
  init_icon_border(pix);
  squar.pos.x = 15;
  squar.pos.y = 15;
  squar.width = 2;
  squar.height = 2;
  pos.x = 35;
  pos.y = 15;
  line(pix, squar, pos, WHITE);
  pos.y = 35;
  pos.x = 15;
  line(pix, squar, pos, WHITE);
  squar.pos.y = 35;
  pos.y = 35;
  pos.x = 35;
  line(pix, squar, pos, WHITE);
  squar.pos.x = 35;
  squar.pos.y = 15;
  line(pix, squar, pos, WHITE);
  return (pix);
}

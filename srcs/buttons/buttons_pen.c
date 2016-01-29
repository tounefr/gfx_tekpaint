/*
** buttons_pen.c for  in /home/bauer_b/rendu/gfx_colle_fantasy5
**
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
**
** Started on  Fri Jan 22 16:26:31 2016 Aurélien BAUER
** Last update Mon Jan 25 11:07:06 2016 thomas
*/

#include "tekpaint.h"

void			draw_pen(t_bunny_pixelarray *pix)
{
  t_bunny_square	squar;

  squar.pos.x = 20;
  squar.pos.y = 8;
  squar.width = 10;
  squar.height = 20;
  square(pix, &squar, WHITE);
  squar.pos.y = 32;
  squar.height = 1;
  square(pix, &squar, WHITE);
  squar.pos.x = 21;
  squar.pos.y = 33;
  squar.width = 8;
  squar.height = 1;
  square(pix, &squar, WHITE);
  squar.pos.x = 22;
  squar.pos.y = 34;
  squar.width = 6;
  squar.height = 1;
  square(pix, &squar, WHITE);
  squar.pos.x = 23;
  squar.pos.y = 35;
  squar.width = 4;
  squar.height = 1;
  square(pix, &squar, WHITE);
}

t_bunny_pixelarray	*buttons_pen()
{
  t_bunny_pixelarray	*pix;
  t_bunny_square	squar;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);
  init_icon(pix);
  draw_pen(pix);
  squar.pos.x = 24;
  squar.pos.y = 36;
  squar.width = 2;
  squar.height = 1;
  square(pix, &squar, WHITE);
  return (pix);
}

t_bunny_pixelarray	*buttons_pen_border()
{
  t_bunny_pixelarray	*pix;
  t_bunny_square	squar;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);
  init_icon_border(pix);
  draw_pen(pix);
  squar.pos.x = 24;
  squar.pos.y = 36;
  squar.width = 2;
  squar.height = 1;
  square(pix, &squar, WHITE);
  return (pix);
}

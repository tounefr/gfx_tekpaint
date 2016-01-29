/*
** buttons_line.c for  in /home/bauer_b/rendu/gfx_tekpaint
**
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
**
** Started on  Fri Jan 22 18:38:38 2016 Aurélien BAUER
** Last update Mon Jan 25 11:06:58 2016 thomas
*/

#include "tekpaint.h"

t_bunny_pixelarray	*buttons_line()
{
  t_bunny_pixelarray	*pix;
  t_bunny_square	squar;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);
  init_icon(pix);
  squar.pos.x = 24;
  squar.pos.y = 5;
  squar.width = 2;
  squar.height = 40;
  square(pix, &squar, WHITE);
  return (pix);
}

t_bunny_pixelarray	*buttons_line_border()
{
  t_bunny_pixelarray	*pix;
  t_bunny_square	squar;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);
  init_icon_border(pix);
  squar.pos.x = 24;
  squar.pos.y = 5;
  squar.width = 2;
  squar.height = 40;
  square(pix, &squar, WHITE);
  return (pix);
}

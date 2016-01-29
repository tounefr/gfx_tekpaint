/*
** buttons_square.c for  in /home/bauer_b/rendu/gfx_tekpaint
**
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
**
** Started on  Fri Jan 22 18:26:53 2016 Aurélien BAUER
** Last update Mon Jan 25 11:06:41 2016 thomas
*/

#include "tekpaint.h"

t_bunny_pixelarray	*buttons_square()
{
  t_bunny_pixelarray	*pix;
  t_bunny_square	squar;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);
  init_icon(pix);
  squar.pos.x = 15;
  squar.pos.y = 15;
  squar.width = 20;
  squar.height = 20;
  square(pix, &squar, WHITE);
  return (pix);
}

t_bunny_pixelarray	*buttons_square_border()
{
  t_bunny_pixelarray	*pix;
  t_bunny_square	squar;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);
  init_icon_border(pix);
  squar.pos.x = 15;
  squar.pos.y = 15;
  squar.width = 20;
  squar.height = 20;
  square(pix, &squar, WHITE);
  return (pix);
}

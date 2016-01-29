/*
** buttons_less.c for  in /home/bauer_b/rendu/gfx_tekpaint
**
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
**
** Started on  Fri Jan 22 18:56:50 2016 Aurélien BAUER
** Last update Mon Jan 25 11:06:50 2016 thomas
*/

#include "tekpaint.h"

t_bunny_pixelarray	*buttons_less()
{
  t_bunny_pixelarray	*pix;
  t_bunny_square	squar;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);;
  init_icon(pix);
  squar.pos.x = 10;
  squar.pos.y = 20;
  squar.width = 30;
  squar.height = 10;
  square(pix, &squar, WHITE);
  return (pix);
}

t_bunny_pixelarray	*buttons_less_border()
{
  t_bunny_pixelarray	*pix;
  t_bunny_square	squar;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);
  init_icon_border(pix);
  squar.pos.x = 10;
  squar.pos.y = 20;
  squar.width = 30;
  squar.height = 10;
  square(pix, &squar, WHITE);
  return (pix);
}

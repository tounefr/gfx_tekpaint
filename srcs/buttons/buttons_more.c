/*
** buttons_more.c for  in /home/bauer_b/rendu/gfx_tekpaint
**
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
**
** Started on  Fri Jan 22 18:50:06 2016 Aurélien BAUER
** Last update Mon Jan 25 11:07:13 2016 thomas
*/

#include "tekpaint.h"

t_bunny_pixelarray	*buttons_more()
{
  t_bunny_pixelarray	*pix;
  t_bunny_square	squar;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);
  init_icon(pix);
  squar.pos.x = 10;
  squar.pos.y = 20;
  squar.width = 30;
  squar.height = 10;
  square(pix, &squar, WHITE);
  squar.pos.x = 20;
  squar.pos.y = 10;
  squar.width = 10;
  squar.height = 30;
  square(pix, &squar, WHITE);
  return (pix);
}

t_bunny_pixelarray	*buttons_more_border()
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
  squar.pos.x = 20;
  squar.pos.y = 10;
  squar.width = 10;
  squar.height = 30;
  square(pix, &squar, WHITE);
  return (pix);
}

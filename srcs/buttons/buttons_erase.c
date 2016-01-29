/*
** buttons_erase.c for  in /home/bauer_b/rendu/gfx_tekpaint/icon
**
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
**
** Started on  Tue Jan 26 14:05:43 2016 Aurélien BAUER
** Last update Tue Jan 26 16:08:02 2016 thomas
*/

#include "tekpaint.h"

t_bunny_pixelarray	*buttons_erase()
{
  t_bunny_pixelarray	*pix;
  t_bunny_square	squar;

  pix = bunny_new_pixelarray(50, 50);
  init_icon_border(pix);
  squar.pos.x = 20;
  squar.pos.y = 10;
  squar.width = 10;
  squar.height = 18;
  empty_square(pix, squar, WHITE, 1);
  squar.pos.x = 20;
  squar.pos.y = 29;
  squar.width = 11;
  squar.height = 10;
  square(pix, &squar, WHITE);
  return (pix);
}

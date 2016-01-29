/*
** buttons_color.c for  in /home/bauer_b/rendu/gfx_tekpaint/icon
**
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
**
** Started on  Tue Jan 26 14:26:26 2016 Aurélien BAUER
** Last update Tue Jan 26 16:07:18 2016 thomas
*/

#include "tekpaint.h"

t_bunny_pixelarray	*buttons_color()
{
  t_bunny_pixelarray	*pix;
  t_bunny_square	squar;

  pix = bunny_new_pixelarray(50, 50);
  init_icon_border(pix);
  squar.pos.x = 7;
  squar.pos.y = 7;
  squar.width = 10;
  squar.height = 10;
  square(pix, &squar, RED);
  squar.pos.x = 20;
  squar.pos.y = 20;
  squar.width = 10;
  squar.height = 10;
  square(pix, &squar, GREEN);
  squar.pos.x = 33;
  squar.pos.y = 33;
  squar.width = 10;
  squar.height = 10;
  square(pix, &squar, BLUE);
  return (pix);
}

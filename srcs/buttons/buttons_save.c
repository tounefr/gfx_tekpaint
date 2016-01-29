/*
** button_save.c for  in /home/bauer_b/rendu/gfx_tekpaint/icon
**
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
**
** Started on  Tue Jan 26 11:18:58 2016 Aurélien BAUER
** Last update Tue Jan 26 20:41:32 2016 thomas
*/

#include "tekpaint.h"

void			next1(t_bunny_pixelarray *pix, t_bunny_square squar)
{
  squar.pos.x = 21;
  squar.pos.y = 34;
  squar.width = 9;
  square(pix, &squar, WHITE);
  squar.pos.x = 20;
  squar.pos.y = 33;
  squar.width = 11;
  square(pix, &squar, WHITE);
  squar.pos.x = 19;
  squar.pos.y = 32;
  squar.width = 13;
  square(pix, &squar, WHITE);
  squar.pos.x = 18;
  squar.pos.y = 31;
  squar.width = 15;
  square(pix, &squar, WHITE);
  squar.pos.x = 17;
  squar.pos.y = 30;
  squar.width = 17;
  square(pix, &squar, WHITE);
  squar.pos.x = 16;
  squar.pos.y = 29;
  squar.width = 19;
  square(pix, &squar, WHITE);
}

void			array(t_bunny_pixelarray *pix, t_bunny_square squar)
{
  squar.pos.x = 22;
  squar.pos.y = 35;
  squar.width = 7;
  squar.height = 1;
  square(pix, &squar, WHITE);
  squar.pos.x = 23;
  squar.pos.y = 36;
  squar.width = 5;
  square(pix, &squar, WHITE);
  squar.pos.x = 24;
  squar.pos.y = 37;
  squar.width = 3;
  square(pix, &squar, WHITE);
  squar.pos.x = 25;
  squar.pos.y = 38;
  squar.width = 1;
  square(pix, &squar, WHITE);
  next1(pix, squar);
  squar.pos.x = 20;
  squar.pos.y = 5;
  squar.width = 10;
  squar.height = 29;
  square(pix, &squar, WHITE);
}

t_bunny_pixelarray	*buttons_save()
{
  t_bunny_pixelarray	*pix;
  t_bunny_square	squar;

  pix = bunny_new_pixelarray(50, 50);
  init_icon_border(pix);
  squar.pos.x = 5;
  squar.pos.y = 40;
  squar.width = 40;
  squar.height = 5;
  square(pix, &squar, WHITE);
  squar.pos.x = 5;
  squar.pos.y = 35;
  squar.width = 5;
  squar.height = 5;
  square(pix, &squar, WHITE);
  squar.pos.x = 40;
  squar.pos.y = 35;
  squar.width = 5;
  squar.height = 5;
  square(pix, &squar, WHITE);
  array(pix, squar);
  return (pix);
}

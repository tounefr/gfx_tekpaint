/*
** buttons_load_bmp.c for  in /home/bauer_b/rendu/gfx_tekpaint/icon
**
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
**
** Started on  Tue Jan 26 14:46:22 2016 Aurélien BAUER
** Last update Tue Jan 26 16:09:33 2016 thomas
*/

#include "tekpaint.h"

void			next_load2_bmp(t_bunny_pixelarray *pix,
				       t_bunny_square squar)
{
  squar.pos.x = 19;
  squar.pos.y = 10;
  squar.width = 11;
  square(pix, &squar, 0x1007B8);
  squar.pos.x = 18;
  squar.pos.y = 11;
  squar.width = 13;
  square(pix, &squar, 0x1007B8);
  squar.pos.x = 17;
  squar.pos.y = 12;
  squar.width = 15;
  square(pix, &squar, 0x1007B8);
  squar.pos.x = 16;
  squar.pos.y = 13;
  squar.width = 17;
  square(pix, &squar, 0x1007B8);
  squar.pos.x = 15;
  squar.pos.y = 14;
  squar.width = 19;
  square(pix, &squar, 0x1007B8);
  squar.pos.x = 20;
  squar.pos.y = 15;
  squar.width = 10;
  squar.height = 20;
  square(pix, &squar, 0x1007B8);
}

void	next_load_bmp(t_bunny_pixelarray *pix, t_bunny_square squar)
{
  squar.pos.x = 24;
  squar.pos.y = 5;
  squar.width = 1;
  squar.height = 1;
  square(pix, &squar, 0x1007B8);
  squar.pos.x = 23;
  squar.pos.y = 6;
  squar.width = 3;
  square(pix, &squar, 0x1007B8);
  squar.pos.x = 22;
  squar.pos.y = 7;
  squar.width = 5;
  square(pix, &squar, 0x1007B8);
  squar.pos.x = 21;
  squar.pos.y = 8;
  squar.width = 7;
  square(pix, &squar, 0x1007B8);
  squar.pos.x = 20;
  squar.pos.y = 9;
  squar.width = 9;
  square(pix, &squar, 0x1007B8);
  next_load2_bmp(pix, squar);
}

t_bunny_pixelarray	*buttons_load_bmp()
{
  t_bunny_pixelarray	*pix;
  t_bunny_square	squar;

  pix = bunny_new_pixelarray(50, 50);
  init_icon_border(pix);
  squar.pos.x = 5;
  squar.pos.y = 40;
  squar.width = 40;
  squar.height = 5;
  square(pix, &squar, 0x1007B8);
  squar.pos.x = 5;
  squar.pos.y = 35;
  squar.width = 5;
  squar.height = 5;
  square(pix, &squar, 0x1007B8);
  squar.pos.x = 40;
  squar.pos.y = 35;
  squar.width = 5;
  squar.height = 5;
  square(pix, &squar, 0x1007B8);
  next_load_bmp(pix, squar);
  return (pix);
}

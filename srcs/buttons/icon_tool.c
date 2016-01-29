/*
** icon_tool.c for  in /home/bauer_b/rendu/gfx_tekpaint
**
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
**
** Started on  Fri Jan 22 17:32:58 2016 Aurélien BAUER
** Last update Fri Jan 22 17:57:08 2016 Aurélien BAUER
*/

#include "tekpaint.h"

void                    init_icon(t_bunny_pixelarray *pix)
{
  t_bunny_square        init;

  init.pos.x = 0;
  init.pos.y = 0;
  init.width = 50;
  init.height = 50;
  square(pix, &init, MY_BLUE);
}

void                    init_icon_border(t_bunny_pixelarray *pix)
{
  t_bunny_square        init;

  init.pos.x = 0;
  init.pos.y = 0;
  init.width = 50;
  init.height = 50;
  square(pix, &init, WHITE);
  init.pos.x = 2;
  init.pos.y = 2;
  init.width = 46;
  init.height = 46;
  square(pix, &init, MY_BLUE);
}

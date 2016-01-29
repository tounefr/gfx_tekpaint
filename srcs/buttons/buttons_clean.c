/*
** buttons_clean.c for  in /home/henon_t/gfx_tekpaint/srcs
** 
** Made by Thomas Henon
** Login   <henon_t@epitech.net>
** 
** Started on  Sun Jan 24 18:55:15 2016 Thomas Henon
** Last update Sun Jan 24 19:14:26 2016 Thomas Henon
*/

#include "tekpaint.h"

t_bunny_pixelarray	*buttons_clean_border()
{
  t_bunny_pixelarray	*pix;
  t_bunny_square	squar;
  t_bunny_position	pos;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);
  init_icon_border(pix);
  squar.pos.x = 0;
  squar.pos.y = 0;
  squar.width = 2;
  squar.height = 2;
  pos.x = 50;
  pos.y = 50;
  line(pix, squar, pos, WHITE);
  squar.pos.x = 50;
  pos.x = 0;
  line(pix, squar, pos, WHITE);
  return (pix);
}

/*
** buttons_bucket.c for  in /home/thomas/Documents/epitech/gfx_tekpaint/srcs/buttons
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Sat Jan 23 17:54:53 2016 thomas
** Last update Sat Jan 23 17:55:27 2016 thomas
*/

#include "tekpaint.h"

void                    buttons_bucket_2(t_bunny_pixelarray *pix)
{
  t_bunny_square        squar;
  t_bunny_position      pos2;

  squar.pos.x = 15;
  squar.pos.y = 45;
  squar.width = 2;
  squar.height = 2;
  pos2.x = 35;
  pos2.y = 45;
  line(pix, squar, pos2, WHITE);
}

t_bunny_pixelarray      *buttons_bucket()
{
  t_bunny_pixelarray    *pix;
  t_bunny_square        squar;
  t_bunny_position      pos2;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);
  init_icon(pix);
  squar.pos.x = 10;
  squar.pos.y = 15;
  squar.width = 2;
  squar.height = 2;
  pos2.x = 15;
  pos2.y = 45;
  line(pix, squar, pos2, WHITE);
  squar.pos.x = 40;
  squar.pos.y = 15;
  squar.width = 2;
  squar.height = 2;
  pos2.x = 35;
  pos2.y = 45;
  line(pix, squar, pos2, WHITE);
  buttons_bucket_2(pix);
  return (pix);
}

t_bunny_pixelarray      *buttons_bucket_border()
{
  t_bunny_pixelarray    *pix;
  t_bunny_square        squar;
  t_bunny_position      pos2;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);
  init_icon_border(pix);
  squar.pos.x = 10;
  squar.pos.y = 5;
  squar.width = 1;
  squar.height = 2;
  pos2.x = 15;
  pos2.y = 45;
  line(pix, squar, pos2, WHITE);
  return (pix);
}

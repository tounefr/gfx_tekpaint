/*
** buttons_circle.c for  in /home/bauer_b/rendu/gfx_tekpaint
**
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
**
** Started on  Fri Jan 22 18:00:36 2016 Aurélien BAUER
** Last update Sat Jan 23 17:30:38 2016 thomas
*/

#include "tekpaint.h"

t_bunny_pixelarray	*buttons_circle()
{
  t_bunny_pixelarray	*pix;
  t_bunny_position	origin;
  t_bunny_position	dist;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);
  init_icon(pix);
  origin.x = 25;
  origin.y = 25;
  dist.x = 10;
  dist.y = 24;
  my_set_circle(pix, &origin, &dist, WHITE);
  return (pix);
}

t_bunny_pixelarray	*buttons_circle_border()
{
  t_bunny_pixelarray	*pix;
  t_bunny_position	origin;
  t_bunny_position	dist;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);
  init_icon_border(pix);
  origin.x = 25;
  origin.y = 25;
  dist.x = 10;
  dist.y = 24;
  my_set_circle(pix, &origin, &dist, WHITE);
  return (pix);
}

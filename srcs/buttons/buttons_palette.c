/*
** buttons_empty_circle.c for  in /home/bauer_b/rendu/gfx_tekpaint
**
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
**
** Started on  Fri Jan 22 18:17:10 2016 Aurélien BAUER
** Last update Sat Jan 23 17:30:17 2016 thomas
*/

#include "tekpaint.h"

t_bunny_pixelarray	*buttons_palette_border()
{
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray *buffer;
  t_bunny_position pos;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);
  init_icon_border(pix);
  if ((buffer = load_bmp("res/color.bmp")) != NULL)
  {
    pos.x = 0;
    pos.y = 0;
    blit_pixelarrays(pix, buffer, &pos);
  }
  return (pix);
}

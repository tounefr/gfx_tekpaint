/*
** buttons_less.c for  in /home/bauer_b/rendu/gfx_tekpaint
**
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
**
** Started on  Fri Jan 22 18:56:50 2016 Aurélien BAUER
** Last update Tue Jan 26 20:41:12 2016 thomas
*/

#include "tekpaint.h"

t_bunny_pixelarray	*buttons_empty_border()
{
  t_bunny_pixelarray	*pix;

  if (NULL == (pix = bunny_new_pixelarray(50, 50)))
    return (NULL);
  init_icon_border(pix);
  return (pix);
}

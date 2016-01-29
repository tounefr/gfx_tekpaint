/*
** eraser.c for  in /home/thomas/Documents/epitech/gfx_tekpaint
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Sat Jan 23 16:59:36 2016 thomas
** Last update Tue Jan 26 20:15:45 2016 Thomas Henon
*/

#include "tekpaint.h"

void				eraser(t_bunny_pixelarray *pix,
				       t_bunny_position *pos_mouse,
				       t_bunny_square squar)
{
  static t_bunny_position	posp;
  static int			is_pass;
  const  bool			*key;

  key = bunny_get_mouse_button();
  if (is_pass == 0)
    {
      posp = *pos_mouse;
      is_pass = 1;
    }
  if (key[BMB_LEFT] == true)
    {
      squar.pos = posp;
      line(pix, squar, *pos_mouse, WHITE);
    }
  posp = *pos_mouse;
}

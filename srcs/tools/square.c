/*
** square.c for  in /home/thomas/Documents/epitech/gfx_tekpaint
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Sat Jan 23 16:49:19 2016 thomas
** Last update Tue Jan 26 20:16:51 2016 Thomas Henon
*/

#include "tekpaint.h"

void                    square_xp_yp(t_bunny_pixelarray *pix,
				     t_bunny_square *squ,
				     unsigned int color)
{
  t_bunny_position	posi;

  posi.y = squ->pos.y - 1;
  while (++posi.y < (squ->height + squ->pos.y))
    {
      posi.x = squ->pos.x - 1;
      while (++posi.x < (squ->width + squ->pos.x))
        set_pixel(pix, color, posi.x, posi.y);
    }
}

void                    square_xp_yn(t_bunny_pixelarray *pix,
				     t_bunny_square *squ,
				     unsigned int color)
{
  t_bunny_position	posi;

  posi.y = squ->pos.y + 1;
  while (--posi.y > (squ->height + squ->pos.y))
    {
      posi.x = squ->pos.x - 1;
      while (++posi.x < (squ->width + squ->pos.x))
        set_pixel(pix, color, posi.x, posi.y);
    }
}

void                    square_xn_yp(t_bunny_pixelarray *pix,
				     t_bunny_square *squ,
				     unsigned int color)
{
  t_bunny_position	posi;

  posi.y = squ->pos.y - 1;
  while (++posi.y < (squ->height + squ->pos.y))
    {
      posi.x = squ->pos.x + 1;
      while (--posi.x > (squ->width + squ->pos.x))
        set_pixel(pix, color, posi.x, posi.y);
    }
}

void                    square_xn_yn(t_bunny_pixelarray *pix,
				     t_bunny_square *squ,
				     unsigned int color)
{
  t_bunny_position  posi;

  posi.y = squ->pos.y + 1;
  while (--posi.y > (squ->height + squ->pos.y))
    {
      posi.x = squ->pos.x + 1;
      while (--posi.x > (squ->width + squ->pos.x))
        set_pixel(pix, color, posi.x, posi.y);
    }
}

void                    square(t_bunny_pixelarray *pix,
                               t_bunny_square *squ,
                               unsigned int color)
{
  if (squ->width >= 0 && squ->height >= 0)
    square_xp_yp(pix, squ, color);
  if (squ->width >= 0 && squ->height < 0)
    square_xp_yn(pix, squ, color);
  if (squ->width < 0 && squ->height >= 0)
    square_xn_yp(pix, squ, color);
  if (squ->width < 0 && squ->height < 0)
    square_xn_yn(pix, squ, color);
}

/*
** circle.c for  in /home/thomas/Documents/epitech
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Mon Jan 25 10:55:06 2016 thomas
** Last update Tue Jan 26 20:14:57 2016 Thomas Henon
*/

#include "tekpaint.h"

void			my_set_empty_circle(t_bunny_pixelarray *pix,
					    t_bunny_position *origin,
					    t_bunny_position *dist,
					    unsigned int color)
{
  double		radius;
  double		angle;
  t_bunny_position	pos;

  angle = 0;
  dist->x = dist->x - origin->x;
  dist->y = dist->y - origin->y;
  radius = sqrt(pow(dist->x, 2) + pow(dist->y, 2));
  while (angle < 360)
    {
      pos.x = cos(DEGREES_TO_RADIANS(angle)) * radius + origin->x;
      pos.y = sin(DEGREES_TO_RADIANS(angle)) * radius + origin->y;
      if (pos.x > 0 && pos.x < pix->clipable.clip_width &&
	  pos.y > 0 && pos.y < pix->clipable.clip_height)
	set_pixel(pix, color, pos.x, pos.y);
      angle += 0.1;
    }
}

void			my_set_circle(t_bunny_pixelarray *pix,
				      t_bunny_position *origin,
				      t_bunny_position *dist,
				      unsigned int color)
{
  double		radius;
  double		mini_radius;
  double		angle;
  t_bunny_position	pos;

  angle = 0;
  dist->x = dist->x - origin->x;
  dist->y = dist->y - origin->y;
  radius = sqrt(pow(dist->x, 2) + pow(dist->y, 2));
  mini_radius = 1;
  while (mini_radius < radius)
    {
      angle = 0;
      while (angle < 360)
	{
	  pos.x = cos(DEGREES_TO_RADIANS(angle)) * mini_radius + origin->x;
	  pos.y = sin(DEGREES_TO_RADIANS(angle)) * mini_radius + origin->y;
	  if (pos.x > 0 && pos.x < pix->clipable.clip_width &&
	      pos.y > 0 && pos.y < pix->clipable.clip_height)
	    set_pixel(pix, color, pos.x, pos.y);
	  angle += 0.10;
	}
      mini_radius += 0.25;
    }
}

void				empty_circle(t_bunny_pixelarray *pix,
					     t_bunny_position *pos_mouse,
					     unsigned int color)
{
  static t_bunny_position	origin;
  static int			clik;
  const  bool			*key;

  key = bunny_get_mouse_button();
  if (key[BMB_LEFT] == true && clik == 0)
    {
      origin = *pos_mouse;
      clik = 1;
    }

  if (key[BMB_LEFT] == false && clik == 1)
    {
      my_set_empty_circle(pix, &origin, pos_mouse, color);
      clik = 0;
    }
}

void				circle(t_bunny_pixelarray *pix,
				       t_bunny_position *pos_mouse,
				       unsigned int color)
{
  static t_bunny_position	origin;
  static int			clik;
  const  bool			*key;

  key = bunny_get_mouse_button();
  if (key[BMB_LEFT] == true && clik == 0)
    {
      origin = *pos_mouse;
      clik = 1;
    }
  if (key[BMB_LEFT] == false && clik == 1)
    {
      my_set_circle(pix, &origin, pos_mouse, color);
      clik = 0;
    }
}

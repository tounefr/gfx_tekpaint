/*
** buttons_event2.c for  in /home/thomas/Documents/epitech/gfx_tekpaint
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Sat Jan 23 16:40:43 2016 thomas
** Last update Mon Jan 25 16:01:20 2016 Thomas HENON
*/

#include "tekpaint.h"

char	on_palette_click(t_tekpaint *tekpaint)
{
  open_palette(tekpaint);
  return (1);
}

char on_bucket_click(t_tekpaint *tekpaint)
{
  my_putstr("Outil : sceau\n");
  tekpaint->tool.current_tool = BUCKET_TOOL;
  return (1);
}

char	on_pen_click(t_tekpaint *tekpaint)
{
  my_putstr("Outil : Pen\n");
  tekpaint->tool.current_tool = PEN_TOOL;
  return (1);
}

char	on_circle_click(t_tekpaint *tekpaint)
{
  my_putstr("Outil : Cercle rempli\n");
  tekpaint->tool.current_tool = CIRCLE_TOOL;
  return (1);
}

char  on_empty_circle_click(t_tekpaint *tekpaint)
{
  my_putstr("Outil : Cercle vide\n");
  tekpaint->tool.current_tool = EMPTY_CIRCLE_TOOL;
  return (1);
}

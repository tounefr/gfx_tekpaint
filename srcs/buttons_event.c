/*
** buttons_event.c for  in /home/henon_t/gfx_tekpaint
**
** Made by Thomas Henon
** Login   <henon_t@epitech.net>
**
** Started on  Wed Jan 20 17:33:31 2016 Thomas Henon
** Last update Mon Jan 25 17:19:46 2016 thomas
*/

#include "tekpaint.h"

char	on_square_click(t_tekpaint *tekpaint)
{
  my_putstr("Outil : Carré\n");
  tekpaint->tool.current_tool = SQUARE_TOOL;
  return (1);
}

char	on_line_click(t_tekpaint *tekpaint)
{
  my_putstr("Outil : Line\n");
  tekpaint->tool.current_tool = LINE_TOOL;
  return (1);
}

char	on_plus_click(t_tekpaint *tekpaint)
{
  my_putstr("Epaisseur augmenté\n");
  tekpaint->tool.thickness++;
  return (1);
}

char	on_less_click(t_tekpaint *tekpaint)
{
  if ((tekpaint->tool.thickness - 1) > 0)
    {
      my_putstr("Epaisseur réduite\n");
      tekpaint->tool.thickness--;
    }
  else
    my_putstr("Impossible de baisser l'épaisseur en dessous de 1 !\n");
  return (1);
}

char			on_reset_workplan_click(t_tekpaint *tekpaint)
{
  t_bunny_position	pos;

  my_putstr("Plan de travail nettoyé !\n");
  fill_buffer(tekpaint->workplan.buffer, WHITE);
  pos.x = 0;
  pos.y = tekpaint->toolbar.height;
  blit_pixelarrays(tekpaint->window.background,
		   tekpaint->workplan.buffer, &pos);
  return (1);
}

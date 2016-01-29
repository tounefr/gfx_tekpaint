/*
** buttons_event3.c for  in /home/thomas/Documents/epitech/gfx_tekpaint
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Sat Jan 23 16:40:53 2016 thomas
** Last update Tue Jan 26 19:59:05 2016 Thomas Henon
*/

#include "tekpaint.h"

char	on_eraser_click(t_tekpaint *tekpaint)
{
  tekpaint->tool.current_tool = ERASER_TOOL;
  my_putstr("Outil : gomme\n");
  return (1);
}

char	on_save_tkp_click(t_tekpaint *tekpaint)
{
  if (save_tkp(tekpaint))
    return (1);
  return (0);
}

char			on_load_tkp_click(t_tekpaint *tekpaint)
{
  t_explorer		explorer_var;
  t_bunny_position	pos;
  t_bunny_pixelarray	*buffer;

  explorer_var.extension = ".tkp";
  explorer_var.win_name = "Charger une image TKP";
  tekpaint->tool.current_tool = 0;
  if (explorer(tekpaint, &explorer_var))
    {
      buffer = load_pixelarray(explorer_var.img,
			       tekpaint->workplan.width,
			       tekpaint->workplan.height);
      if (!buffer)
	my_putstr("Erreur durant le chargement de l'image\n");
      else
	{
	  pos.x = 0;
	  pos.y = 0;
	  blit_pixelarrays(tekpaint->workplan.buffer, buffer, &pos);
	}
    }
  bunny_set_click_response(on_win_click);
  return (1);
}

char		on_load_bmp_click(t_tekpaint *tekpaint)
{
  t_explorer	explorer_var;

  explorer_var.extension = ".bmp";
  explorer_var.win_name = "Charger une image BMP";
  tekpaint->tool.current_tool = 0;
  if (explorer(tekpaint, &explorer_var))
    {
      tekpaint->tool.bmp_buffer_tmp = load_bmp(explorer_var.img);
      if (!tekpaint->tool.bmp_buffer_tmp)
	  my_putstr("Erreur durant le chargement de l'image\n");
      else
	{
	  tekpaint->tool.current_tool = BMP_LOAD_TOOL;
	  my_putstr("Image chargé !\n");
	  my_putstr("Cliquez quelque part sur l'écran !\n");
	}
    }
  bunny_set_click_response(on_win_click);
  return (1);
}

char	on_empty_square_click(t_tekpaint *tekpaint)
{
  tekpaint->tool.current_tool = EMPTY_SQUARE_TOOL;
  my_putstr("Outil : carré vide\n");
  return (1);
}

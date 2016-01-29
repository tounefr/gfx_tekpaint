/*
** palette.c for  in /home/thomas/Documents/epitech/gfx_tekpaint
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Sat Jan 23 16:48:05 2016 thomas
** Last update Tue Jan 26 20:09:12 2016 Thomas Henon
*/

#include "tekpaint.h"

t_bunny_response	main_loop_palette(void *data)
{
  t_tekpaint		*tekpaint;
  t_palette		*palette;

  tekpaint = (t_tekpaint*) data;
  palette = &tekpaint->tool.palette;
  bunny_display(palette->win);
  return (GO_ON);
}

t_bunny_response	on_palette_event_click(t_bunny_event_state state,
					       t_bunny_mousebutton key,
					       void *datas)
{
  t_tekpaint		*tekpaint;
  t_palette		*palette;
  unsigned int		color;

  tekpaint = (t_tekpaint*) datas;
  palette = &tekpaint->tool.palette;
  tekpaint->tool.current_tool = 0;
  color = get_pixel(palette->buffer,
    bunny_get_mouse_position()->x,
    bunny_get_mouse_position()->y);
  tekpaint->tool.color = color;
  return (EXIT_ON_CROSS);
}

void	palette_reset(t_palette *palette)
{
  bunny_set_click_response(on_win_click);
  bunny_set_loop_main_function((t_bunny_loop)main_loop);
  palette->win = NULL;
}

char			open_palette(t_tekpaint *tekpaint)
{
  t_bunny_position	pos;
  t_palette		*palette;

  palette = &tekpaint->tool.palette;
  palette->win = bunny_start_style(PALETTE_WIDTH, PALETTE_HEIGHT,
				   TITLEBAR | CLOSE_BUTTON,
				   "Palette de couleurs");
  if (NULL == (palette->buffer = load_bmp("res/palette.bmp")))
    return (0);
  pos.x = 0;
  pos.y = 0;
  bunny_blit(&palette->win->buffer, &palette->buffer->clipable, &pos);
  bunny_set_click_response(on_palette_event_click);
  bunny_set_loop_main_function((t_bunny_loop)main_loop_palette);
  bunny_loop(palette->win, 50, tekpaint);
  bunny_stop(palette->win);
  palette_reset(palette);
  return (1);
}

/*
** main.c for  in /home/thomas/Documents/epitech/gfx_tekpaint
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Mon Jan 18 15:43:16 2016 Thomas HENON
** Last update Tue Jan 26 20:53:55 2016 thomas
*/

#include "tekpaint.h"

char	set_tool2(t_bunny_position *pos,
		  t_tekpaint *tekpaint,
		  t_bunny_square *square)
{
  if (tekpaint->tool.current_tool & LINE_TOOL)
    make_line(tekpaint->workplan.buffer, pos, tekpaint->tool.color, *square);
  if (tekpaint->tool.current_tool & ERASER_TOOL)
    eraser(tekpaint->workplan.buffer, pos, *square);
  if (tekpaint->tool.current_tool & EMPTY_SQUARE_TOOL)
    make_empty_square(tekpaint->workplan.buffer,
		      pos,
		      tekpaint->tool.color,
		      tekpaint->tool.thickness);
    return (1);
}

char			set_tool(t_bunny_position *mouse_position, t_tekpaint *tekpaint)
{
  t_bunny_position	pos;
  t_bunny_square	square;

  square.height = tekpaint->tool.thickness;
  square.width = tekpaint->tool.thickness;
  pos.x = mouse_position->x;
  pos.y = mouse_position->y - tekpaint->toolbar.height;
  if (pos.x <= 0 || pos.x >= tekpaint->workplan.width ||
      pos.y <= 0 || pos.y >= tekpaint->workplan.height)
    return (0);
  if (tekpaint->tool.current_tool & PEN_TOOL)
    pen(tekpaint->workplan.buffer, &pos, tekpaint->tool.color, square);
  if (tekpaint->tool.current_tool & EMPTY_CIRCLE_TOOL)
    empty_circle(tekpaint->workplan.buffer, &pos, tekpaint->tool.color);
  if (tekpaint->tool.current_tool & CIRCLE_TOOL)
    circle(tekpaint->workplan.buffer, &pos, tekpaint->tool.color);
  if (tekpaint->tool.current_tool & SQUARE_TOOL)
    make_square(tekpaint->workplan.buffer, &pos, tekpaint->tool.color);
  return (set_tool2(&pos, tekpaint, &square));
}

t_bunny_response		main_loop(void *data)
{
  t_tekpaint			*tekpaint;
  t_bunny_position		pos;
  static t_bunny_position	mouse_position;

  tekpaint = (t_tekpaint*)data;
  pos.x = 0;
  pos.y = 0;
  set_tool(&mouse_position, tekpaint);
  mouse_position = *((t_bunny_position*)bunny_get_mouse_position());
  pos.y = tekpaint->toolbar.height;
  blit_pixelarrays(tekpaint->window.background,
		   tekpaint->workplan.buffer, &pos);
  pos.y = 0;
  bunny_blit(&tekpaint->window.win->buffer,
	     &tekpaint->window.background->clipable, &pos);
  if (tekpaint->tool.palette.win)
    bunny_display(tekpaint->tool.palette.win);
  bunny_display(tekpaint->window.win);
  return (GO_ON);
}

int                     main()
{
  t_tekpaint            tekpaint;

  tekpaint.window.width = WIN_WIDTH;
  tekpaint.window.height = WIN_HEIGHT;
  tekpaint.window.name = WIN_NAME;
  tekpaint.window.fullscreen = WIN_FULLSCREEN;
  tekpaint.window.frequency = WIN_REFRESH_PER_SEC;
  tekpaint.toolbar.width = tekpaint.window.width;
  tekpaint.toolbar.height = (int)(8.0/100.0 * tekpaint.window.height);
  tekpaint.workplan.width = tekpaint.window.width;
  tekpaint.workplan.height =
    tekpaint.window.height - tekpaint.toolbar.height;
  tekpaint.playmusic = false;
  if (!init_window(&tekpaint))
    return (1);
  return (0);
}

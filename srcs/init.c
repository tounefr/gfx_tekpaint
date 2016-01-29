/*
** init.c for  in /home/henon_t/gfx_tekpaint
**
** Made by Thomas Henon
** Login   <henon_t@epitech.net>
**
** Started on  Sat Jan 23 12:01:04 2016 Thomas Henon
** Last update Thu Jan 28 20:40:04 2016 Thomas HENON
*/

#include "tekpaint.h"

char			init_toolbar(t_window *win,
				     t_toolbar *toolbar)
{
  t_bunny_position	pos;

  if (NULL == (toolbar->buffer = bunny_new_pixelarray(
    toolbar->width, toolbar->height)))
    return (0);
  fill_buffer(toolbar->buffer, MY_BLUE);
  pos.x = 0;
  pos.y = 0;
  init_bts(&toolbar->buttons, toolbar->buffer);
  blit_pixelarrays(win->background, toolbar->buffer, &pos);
  bunny_delete_clipable(&toolbar->buffer->clipable);
  return (1);
}

char	init_tool(t_tool *tool)
{
  tool->thickness = 1;
  tool->current_tool = PEN_TOOL;
  tool->color = BLACK;
  return (1);
}

char			init_workplan(t_toolbar *toolbar,
				      t_window *win,
				      t_workplan *workplan)
{
  t_bunny_position	pos;

  if (NULL == (workplan->buffer = bunny_new_pixelarray(
	workplan->width, workplan->height)))
    return (0);
  fill_buffer(workplan->buffer, WHITE);
  pos.x = 0;
  pos.y = toolbar->height;
  blit_pixelarrays(win->background, workplan->buffer, &pos);
  return (1);
}

char	init_background(t_window *win)
{
  if (NULL == (win->background = bunny_new_pixelarray(
    win->width, win->height)))
    return (0);
  fill_buffer(win->background, WHITE);
  return (1);
}

char	init_window(t_tekpaint *tekpaint)
{
  set_max_heap_size(30);
  tekpaint->window.win = bunny_start_style(
    tekpaint->window.width, tekpaint->window.height,
    TITLEBAR | CLOSE_BUTTON, tekpaint->window.name);
  tekpaint->tool.palette.win = NULL;
  tekpaint->tool.font_buffer = NULL;
  tekpaint->tool.explorer = NULL;
  if (!init_background(&tekpaint->window))
    return (0);
  if (!init_toolbar(&tekpaint->window, &tekpaint->toolbar))
    return (0);
  if (!init_tool(&tekpaint->tool))
    return (0);
  if (!init_workplan(&tekpaint->toolbar, &tekpaint->window,
     &tekpaint->workplan))
    return (0);
  if (NULL == (tekpaint->tool.font_buffer = load_bmp("res/font.bmp")))
    return (0);
  init_music();
  bunny_set_click_response(on_win_click);
  bunny_set_loop_main_function((t_bunny_loop)main_loop);
  bunny_loop(tekpaint->window.win, tekpaint->window.frequency, tekpaint);
  bunny_stop(tekpaint->window.win);
  free_window(tekpaint);
  return (1);
}

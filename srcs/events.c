/*
** event.c for  in /home/henon_t/gfx_tekpaint
**
** Made by Thomas Henon
** Login   <henon_t@epitech.net>
**
** Started on  Wed Jan 20 18:49:25 2016 Thomas Henon
** Last update Tue Jan 26 19:35:10 2016 Thomas Henon
*/

#include "tekpaint.h"

void			on_win_click_buttons(t_tekpaint *tekpaint,
					     t_bunny_event_state state)
{
  t_button		*button;
  t_bunny_position	*mouse_position;
  t_linkedlist		*buttons;

  buttons = tekpaint->toolbar.buttons;
  mouse_position = (t_bunny_position*)bunny_get_mouse_position();
  while (buttons)
    {
      button = (t_button*)buttons->data;
      if (
	  (mouse_position->x >= button->pos.x) &&
	  (mouse_position->x <= button->pos.x + button->width) &&
	  (mouse_position->y >= button->pos.y) &&
	  (mouse_position->y <= button->pos.y + button->height))
	{
	  if (state == GO_UP)
	    button->on_click(tekpaint);
	}
      buttons = buttons->next;
    }
}

t_bunny_response	on_win_click(t_bunny_event_state state,
				     t_bunny_mousebutton key,
				     void *datas)
{
  t_tekpaint		*tekpaint;
  t_bunny_position	*mouse_position;
  t_bunny_position	pos;

  tekpaint = (t_tekpaint*)datas;
  mouse_position = (t_bunny_position*)bunny_get_mouse_position();
  on_win_click_buttons(tekpaint, state);
  if (mouse_position->y > tekpaint->toolbar.height && state == GO_UP)
    {
      pos.x = mouse_position->x;
      pos.y = mouse_position->y - tekpaint->toolbar.height;
      if (tekpaint->tool.current_tool & BMP_LOAD_TOOL)
	paste_bmp(tekpaint, &pos);
    }
  return (GO_ON);
}

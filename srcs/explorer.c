/*
** explorer.c for gfx_tekpaint in /home/thomas/Documents/epitech/gfx_t
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Tue Jan 26 02:02:29 2016 Thomas HENON
** Last update Tue Jan 26 21:59:57 2016 thomas
*/

#include "tekpaint.h"

t_bunny_response	main_loop_explorer(void *data)
{
  t_tekpaint		*tekpaint;
  t_explorer		*explorer;
  t_bunny_position	pos;

  tekpaint = (t_tekpaint*) data;
  explorer = tekpaint->tool.explorer;
  pos.x = 0;
  pos.y = 0;
  if (explorer)
    {
      bunny_blit(&explorer->win->buffer, &explorer->buffer->clipable, &pos);
      bunny_display(explorer->win);
    }
  return (GO_ON);
}

char	explorer_on_enter(t_tekpaint *tekpaint,
			  t_explorer *explorer,
			  int *i)
{
  char	*path;
  char	*file_name;
  DIR	*dirp;

  if ((file_name = get_focused_file_name(explorer, *i)))
    {
      path = concat_path(explorer->current_path, file_name);
      if (NULL == (dirp = opendir(path)))
	{
	  closedir(dirp);
	  if (explorer_on_enter_file(file_name, path, explorer))
	    return (1);
	}
      else
	{
	  closedir(dirp);
	  explorer->current_path = path;
	  *i = 0;
	  read_files(explorer);
	  display_files(tekpaint, explorer, *i);
	}
  }
  else
    my_putstr("Ce fichier est incorrect !\n");
  return (0);
}

t_bunny_response	explorer_on_key(t_bunny_event_state state,
					t_bunny_keysym key,
					void *data)
{
  t_tekpaint		*tekpaint;
  t_explorer		*explorer;
  static int		i;
  char			*file_name;

  tekpaint = (t_tekpaint*) data;
  explorer = tekpaint->tool.explorer;
  read_files(explorer);
  if (key == BKS_UP && state == GO_UP && i > 0)
    i--;
  else if (key == BKS_DOWN && state == GO_UP)
    i++;
  else if (key == BKS_RETURN && state == GO_UP)
    {
      if (explorer_on_enter(tekpaint, explorer, &i))
	return (EXIT_ON_SUCCESS);
    }
  display_files(tekpaint, explorer, i);
  return (GO_ON);
}

char	explorer_reset(t_tekpaint *tekpaint, t_explorer *explorer)
{
  bunny_stop(explorer->win);
  bunny_set_key_response(NULL);
  bunny_set_loop_main_function((t_bunny_loop)main_loop);
  bunny_delete_clipable(&explorer->buffer->clipable);
  explorer->buffer = NULL;
  tekpaint->tool.explorer->win = NULL;
  tekpaint->tool.explorer = NULL;
}

char			explorer(t_tekpaint *tekpaint, t_explorer *explorer)
{
  tekpaint->tool.explorer = explorer;
  explorer->current_path = "./";
  explorer->img = NULL;
  explorer->win = bunny_start_style(EXPLORER_WIDTH,
			  EXPLORER_HEIGHT, TITLEBAR | CLOSE_BUTTON,
			  explorer->win_name);
  explorer->buffer = bunny_new_pixelarray(EXPLORER_WIDTH, EXPLORER_HEIGHT);
  if (explorer->buffer == NULL)
    return (0);
  fill_buffer(explorer->buffer, BLACK);
  read_files(explorer);
  display_files(tekpaint, explorer, 0);
  bunny_set_key_response(explorer_on_key);
  bunny_set_click_response(NULL);
  bunny_set_loop_main_function((t_bunny_loop)main_loop_explorer);
  bunny_loop(explorer->win, 50, tekpaint);
  explorer_reset(tekpaint, explorer);
  return (1);
}

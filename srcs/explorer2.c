/*
** explorer2.c for gfx_tekpaint in /home/thomas/Documents/epitech/gfx_tekpaint/srcs
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Tue Jan 26 04:28:26 2016 Thomas HENON
** Last update Tue Jan 26 21:59:52 2016 thomas
*/

#include "tekpaint.h"

char		read_files(t_explorer *explorer)
{
  DIR		*dirp;
  struct dirent	*dirent_p;

  explorer->files = NULL;
  dirp = NULL;
  if (NULL == (dirp = opendir(explorer->current_path)))
    return (0);
  while (NULL != (dirent_p = readdir(dirp)))
    {
      if (my_strcmp(dirent_p->d_name, "."))
	append_elem(&explorer->files, dirent_p->d_name);
    }
  return (1);
}

char			display_files(t_tekpaint *tekpaint,
				      t_explorer *explorer,
				      int start)
{
  t_linkedlist		*tmp;
  t_bunny_position	pos;
  int			i;

  tmp = explorer->files;
  pos.x = 10;
  pos.y = 10;
  i = -1;
  while (tmp && i++ < start)
    tmp = tmp->next;
  fill_buffer(explorer->buffer, BLACK);
  while (tmp)
    {
      font_putstr(tekpaint, explorer->buffer, &pos, (char*)tmp->data);
      pos.x = 10;
      pos.y = pos.y + ALPHA_HEIGHT;
      tmp = tmp->next;
      start++;
    }
  return (1);
}

char		*get_focused_file_name(t_explorer *explorer, int start)
{
  int		i;
  t_linkedlist	*tmp;

  i = 0;
  tmp = explorer->files;
  while (i <= start && tmp)
    {
      i++;
      tmp = tmp->next;
    }
  if (tmp)
    return ((char*)tmp->data);
  return (NULL);
}

char	explorer_on_enter_file(char *file_name, char *path, t_explorer *explorer)
{
  if (!my_strstr(file_name, explorer->extension))
    my_putstr("Ce fichier n'est pas au bon format !\n");
  else
    {
      explorer->img = path;
      return (1);
    }
  return (0);
}

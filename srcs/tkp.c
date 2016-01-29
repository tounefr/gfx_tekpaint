/*
** io.c for  in /home/thomas/Documents/epitech/gfx_tekpaint
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Sat Jan 23 16:46:55 2016 thomas
** Last update Tue Jan 26 20:11:00 2016 Thomas Henon
*/

#include "tekpaint.h"

char		save_pixelarray(char *file_path,
				t_bunny_pixelarray *buffer)
{
  int		fd;
  unsigned long	size;
  int		writev;
  unsigned long	i;

  if (0 == (fd = open(file_path, O_CREAT |  O_WRONLY, 0777)))
    return (0);
  size = buffer->clipable.clip_width * buffer->clipable.clip_height;
  i = 0;
  while (i < size)
    write(fd, &((t_color*)buffer->pixels)[i++], sizeof(unsigned int));
  return (1);
}

char	save_tkp(t_tekpaint *tekpaint)
{
  char	*buffer;
  int	readv;

  if (NULL == (buffer = bunny_malloc(sizeof(char)*101)))
    return (0);
  clean_buffer(buffer, 101);
  my_putstr("Entrez le chemin du fichier à sauvegarder : ");
  readv = read(0, buffer, 100);
  remove_carriage_return(buffer);
  buffer = my_strcat(buffer, ".tkp");
  if (save_pixelarray(buffer, tekpaint->workplan.buffer) && readv > 0)
    {
      my_putstr("Fichier sauvegardé vers : ");
      my_putstr(buffer);
      my_putchar('\n');
    }
  else
    my_putstr("Erreur durant la sauvegarde, try again\n");
  bunny_free(buffer);
  return (1);
}

t_bunny_pixelarray	*load_pixelarray(char *file_path,
					 int wp_width,
					 int wp_height)
{
  t_bunny_pixelarray	*pixelarray;
  int			fd;
  unsigned int		buffer;
  int			readv;
  int			i;

  if (NULL == (pixelarray = bunny_new_pixelarray(wp_width, wp_height)))
    return (NULL);
  if (-1 == (fd = open(file_path, O_RDONLY)))
    return (NULL);
  i = 0;
  while (i < wp_width * wp_height)
    {
      if (read(fd, &buffer, sizeof(unsigned int)) <= 0)
	return (NULL);
      ((t_color*)pixelarray->pixels)[i++].full = buffer;
    }
  close(fd);
  return (pixelarray);
}

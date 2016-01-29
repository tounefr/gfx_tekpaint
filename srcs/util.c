/*
** util.c for  in /home/henon_t/gfx_tekpaint/srcs
**
** Made by Thomas Henon
** Login   <henon_t@epitech.net>
**
** Started on  Sun Jan 24 23:08:41 2016 Thomas Henon
** Last update Tue Jan 26 20:09:44 2016 Thomas Henon
*/

#include "tekpaint.h"

void	clean_buffer(char *buffer, int size)
{
  int	i;

  i = 0;
  while (i < size)
    buffer[i++] = 0;
}

char	remove_carriage_return(char *buffer)
{
  int	i;

  i = 0;
  while (buffer[i])
  {
    if (buffer[i] == '\n')
    {
      buffer[i] = 0;
      return (1);
    }
    i++;
  }
  return (1);
}

char    *my_strcat(char *str1, char *str2)
{
  int   i;
  int   i2;
  char  *str3;

  if (0 == (str3 = bunny_malloc(my_strlen(str1) + my_strlen(str2) + 1)))
    return (NULL);
  i = 0;
  i2 = 0;
  while (str1 && str1[i2])
    str3[i++] = str1[i2++];
  i2 = 0;
  while (str2 && str2[i2])
    str3[i++] = str2[i2++];
  str3[i] = '\0';
  return (str3);
}

char	*concat_path(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i])
    i++;
  if (str1[i - 1] != '/')
      str1 = my_strcat(str1, "/");
  return (my_strcat(str1, str2));
}

int     my_strcmp(char *s1, char *s2)
{
  char  *curChar;
  char  i;

  i = 0;
  curChar = s1;
  while (*curChar != '\0')
    {
      if ((s1[i] - s2[i]) != 0)
        return (s1[i] - s2[i]);
      i = i + 1;
      curChar = curChar + 1;
    }
  return (0);
}

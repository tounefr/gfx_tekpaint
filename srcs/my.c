/*
** my.c for  in /home/thomas/Documents/epitech/gfx_tekpaint
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Sat Jan 23 16:47:29 2016 thomas
** Last update Tue Jan 26 20:03:29 2016 Thomas Henon
*/

#include "tekpaint.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    write(1, &str[i++], 1);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  if (!str)
    return (0);
  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*my_strstr(char *str, char *to_find)
{
  char	*curChar;
  char	i;
  char	length_to_find;

  curChar = str;
  length_to_find = my_strlen(to_find);
  i = 0;
  while (*curChar != '\0')
    {
      if (*curChar == to_find[i])
	{
	  if ((i + 1) == length_to_find)
	    return (curChar - i);
	  i = i + 1;
	}
      else
	i = 0;
      curChar = curChar + 1;
    }
  return (NULL);
}

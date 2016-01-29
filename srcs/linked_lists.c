/*
** linked_lists.c for  in /home/henon_t/gfx_tekpaint
**
** Made by Thomas Henon
** Login   <henon_t@epitech.net>
**
** Started on  Wed Jan 20 16:30:35 2016 Thomas Henon
** Last update Tue Jan 26 20:08:26 2016 Thomas Henon
*/

#include "tekpaint.h"

t_linkedlist	*create_elem(void *data)
{
  t_linkedlist	*elem;

  if (NULL == (elem = bunny_malloc(sizeof(t_linkedlist))))
    return (NULL);
  elem->next = NULL;
  elem->data = data;
  return (elem);
}

unsigned int	elem_count(t_linkedlist *list)
{
  unsigned int	i;

  i = 0;
  while (list)
    {
      i++;
      list = list->next;
    }
  return (i);
}

char		append_elem(t_linkedlist **head, void *data)
{
  t_linkedlist	*last;

  if (*head == NULL)
    {
      *head = create_elem(data);
      return (1);
    }
  last = *head;
  while (last->next)
    last = last->next;
  if (NULL == (last->next = create_elem(data)))
    return (0);
  return (1);
}

void		free_list(t_linkedlist **head)
{
  t_linkedlist	*prev;

  prev = *head;
  *head = (*head)->next;
  while (*head)
    {
      bunny_free(prev);
      prev = *head;
      *head = (*head)->next;
    }
  *head = NULL;
}

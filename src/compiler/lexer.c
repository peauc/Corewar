/*
** lexer.c for lexer in /home/arnaud_e/rendu/cpe/corewar/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Feb 28 16:03:05 2016 Arthur ARNAUD
** Last update Sun Mar 27 21:58:40 2016 Poc
*/

#include "asm.h"

void	test_action(t_action *action)
{
  while (action != NULL)
    {
      action = action->next;
    }
}

void	test_label(t_label *action)
{
  while (action != NULL)
    {
      action = action->next;
    }
}

void	init_struct(t_pos *pos, t_header *header, int *trick)
{
  pos->prog_size = 0;
  pos->line = 0;
  header->full = 0;
  header->prog_name[0] = 0;
  *trick = 0;
}

int	lexer(t_label *label, t_action *action, t_header *header, int fd)
{
  t_ftab	*ftab;
  t_pos		pos;
  char		*str;
  int		trick;

  ftab = NULL;
  init_struct(&pos, header, &trick);
  if (!(ftab = set_ftab(ftab)))
    return (1);
  while ((str = get_line_not_empty(fd, &pos.line)) != NULL)
    {
      if (!header->full && check_empty(str))
	if (get_header(str, header, &trick))
	  return (1);
      if (header->full && trick && check_empty(str))
	  if (!(str = check_label(str, label, &pos)) ||
	      (check_action(str, action, &pos, ftab)))
	    return (1);
      if (header->full)
	trick = 1;
      pos.line++;
    }
  header->prog_size = pos.prog_size;
  return (0);
}

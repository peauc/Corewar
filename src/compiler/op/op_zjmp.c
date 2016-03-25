/*
** op_zjmp.c for op_zjmp in CPE_2015_corewar/src/compiler/op
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Mar 24 01:16:27 2016 Arthur ARNAUD
** Last update Fri Mar 25 13:39:32 2016 Arthur ARNAUD
*/

#include "asm.h"

int	op_zjmp(t_action *action, char *str, t_pos *pos)
{
  int	i;
  char	type;
  char	**tab;
  char	**list_arg;

  pos->prog_size += 1;
  action->identifier = 0x09;
  i = -1;
  if (!(action->args = malloc(sizeof(t_arg *) * 2)) ||
      !(tab = str_to_word_tab(str, ',')) ||
      !(list_arg = str_to_word_tab("2", ' ')) ||
      init_args(action, 1))
    return (1);
  while (tab[++i])
    {
      if (i > 0 || (type = check_type(tab[i], pos)) == -1 ||
	  check_args(type, list_arg[i], pos) ||
	  fill_arg(type, tab[i], action->args[i], pos))
	return (1);
      action->args[0]->type = 4;
      add_prog_size(type, pos);
    }
  action->coding_byte = 0;
  return ((i < 1) ? 1 : 0);
}

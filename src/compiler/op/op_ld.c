/*
** op_ld.c for op_ld in /CPE_2015_corewar/src/compiler/op
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Mar 24 03:55:10 2016 Arthur ARNAUD
** Last update Sun Mar 27 20:21:50 2016 Poc
*/

#include "asm.h"

int	op_ld(t_action *action, char *str, t_pos *pos)
{
  int	i;
  char	c;
  char	type;
  char	**tab;
  char	**list_arg;

  if ((c = 0) || !(pos->prog_size += 2) || !(action->pos = pos->prog_size) ||
      !(i = -1) || !(action->identifier = 0x02) ||
      !(action->args = malloc(sizeof(t_arg *) * 3)) ||
      !(tab = str_to_word_tab(str, ',')) ||
      !(list_arg = str_to_word_tab("23 1", ' ')) ||
      init_args(action, 2))
    return (1);
  while (tab[++i])
    {
      if (i > 1 || (type = check_type(tab[i], pos)) == -1 ||
	  check_args(type, list_arg[i], pos) ||
	  fill_arg(type, tab[i], action->args[i], action->pos - 2))
	return (1);
      add_prog_size(type, pos);
      c += (type << (6 - (i * 2)));
    }
  action->coding_byte = c;
  return (free_tab(list_arg), free_tab(tab), (i < 2) ? 1 : 0);
}

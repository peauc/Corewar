/*
** op_ldi.c for op_ldi in /CPE_2015_corewar/src/compiler/op
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Mar 24 04:06:39 2016 Arthur ARNAUD
** Last update Fri Mar 25 19:06:52 2016 Arthur ARNAUD
*/

#include "asm.h"

int	op_ldi(t_action *action, char *str, t_pos *pos)
{
  int	i;
  char	c;
  char	type;
  char	**tab;
  char	**list_arg;

  if ((c = 0) || !(pos->prog_size += 2) ||
      !(i = -1) || !(action->identifier = 0x0A) ||
      !(action->args = malloc(sizeof(t_arg *) * 4)) ||
      !(tab = str_to_word_tab(str, ',')) ||
      !(list_arg = str_to_word_tab("123 12 1", ' ')) ||
      init_args(action, 3))
    return (1);
  while (tab[++i])
    {
      if (i > 2 || (type = check_type(tab[i], pos)) == -1 ||
	  check_args(type, list_arg[i], pos) ||
	  fill_arg(type, tab[i], action->args[i], pos))
	return (1);
      change_to_odds(action->args[i]);
      add_prog_size(type, pos);
      c += (type << (6 - (i * 2)));
    }
  action->coding_byte = c;
  return ((i < 3) ? 1 : 0);
}

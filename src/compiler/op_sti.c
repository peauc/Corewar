
/*
** op_sti.c for op_sti in /CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Mar 22 17:32:48 2016 Arthur ARNAUD
** Last update Tue Mar 22 18:23:07 2016 Poc
*/

#include "asm.h"

int	op_sti(t_action *action, char *str, t_pos *pos)
{
  int	i;
  int	type;
  char	**tab;
  char	**list_arg;

  action->identifier = 0x0B;
  i = -1;
  if (!(action->args = malloc(sizeof(t_arg) * 2)) ||
      !(tab = str_to_word_tab(str, ',')) ||
      !(list_arg = str_to_word_tab("1 123 123", ' ')))
    return (1);
  action->args[1] = NULL;
  while (tab[++i])
    {
      // nb arg de l'instruct - 1
      if (i > 0 || (type = check_type(tab[i], pos)) == -1)
	  /* check_args(tab[i], list_arg[i], pos)) */
	  return (1);
      /* fill_action(tab[i], action, i); */
    }
  if (i < 1) // nb arg de l'instruct
    return (1);
  return (0);
}

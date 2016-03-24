/*
** init_args.c for init_args in /CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Mar 24 00:15:32 2016 Arthur ARNAUD
** Last update Thu Mar 24 00:37:53 2016 Arthur ARNAUD
*/

#include "asm.h"

int	init_args(t_action *action, int size)
{
  int	i;

  i = -1;
  while (++i < size)
    if (!(action->args[i] = malloc(sizeof(t_arg))))
      return (1);
  action->args[i] = NULL;
  return (0);
}

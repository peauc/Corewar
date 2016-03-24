/*
** check_args.c for check_args in /CPE_2015_corewar/src/compiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Mar 22 20:00:24 2016 Arthur ARNAUD
** Last update Thu Mar 24 00:51:19 2016 Arthur ARNAUD
*/

#include "asm.h"

int	check_args(char type, char *str, t_pos *pos)
{
  int	i;

  i = -1;
  while (str[++i])
    if (str[i] == type)
      return (1);
  return (0);
}

/*
** my_putstrs.c for my_putstrs in /home /decompiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Mar  2 06:05:38 2016 Arthur ARNAUD
** Last update Wed Mar  2 11:39:03 2016 Arthur ARNAUD
*/

#include "decompiler.h"

int	my_putstr_instruct(char *str, int fd_s)
{
  int	i;

  i = -1;
  if (write(fd_s, "\t", 1) == -1)
    return (1);
  while (str[++i] != 0)
    if (write(fd_s, &str[i], 1) == -1)
      return (1);
  if (write(fd_s, " ", 1) == -1)
    return (1);
  return (0);
}

int	my_putstr_file(char *str, int fd_s)
{
  int	i;

  i = -1;
  printf("name = %s\n", str);
  while (str[++i] != 0)
    if (write(fd_s, &str[i], 1) == -1)
      return (1);
  return (0);
}

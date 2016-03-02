/*
** fill_file.c for fill_file in /home/arnaud_e/rendu/cpe/corewar/src/decompiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Mar  2 06:32:29 2016 Arthur ARNAUD
** Last update Wed Mar  2 10:48:07 2016 Arthur ARNAUD
*/

#include "decompiler.h"

int	fill_file(int fd_cor, int fd_s,
		  ftab tab)
{
  char	c;

  if (read(fd_cor, &c, 1) < 0)
    return (1);
  return (ftab[int(c) - 1](fd_cor, fd_s));
}

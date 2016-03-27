/*
** op_xor.c for op_xor in /CPE_2015_corewar/src/decompiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Fri Mar  4 23:41:01 2016 Arthur ARNAUD
** Last update Fri Mar  4 23:43:18 2016 Arthur ARNAUD
*/

#include "decompiler.h"

int	op_xor(int fd_cor, int fd_s)
{
  unsigned char	c;
  unsigned char buf[5];
  unsigned int	nb;
  int		i;
  int		size_read;

  if (my_putstr_instruct("xor", fd_s) ||
      read(fd_cor, &c, 1) == -1)
    return (1);
  i = -1;
  while (++i < 3)
    {
      if ((size_read = check_codage(&c, fd_s)) == -1 ||
	  my_memset(&buf, 0, size_read) ||
	  read(fd_cor, &buf, size_read) < 0)
	return (1);
      buf[size_read] = 0;
      nb = convert_to_nb(buf, size_read);
      my_putnbr_file(nb, fd_s);
      if ((i < 2 && write(fd_s, ",", 1) < 0) ||
	  (i == 2 && write(fd_s, "\n", 1) < 0))
	return (1);
    }
  return (0);
}
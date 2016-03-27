/*
** octet_codage.c for octet_codage in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 11:07:59 2016 Marwane
** Last update Sun Mar 27 01:10:10 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int	get_size(int opt)
{
  int	sizes[4];

  sizes[0] = 0;
  sizes[1] = T_REG;
  sizes[2] = T_DIR;
  sizes[3] = T_IND;
  return (sizes[opt]);
}

int	get_myint(t_vm *vm, t_champ *champ, int n_octets)
{
  int	c;
  int	p;
  char	s[n_octets + 1];
  int	nb;

  nb = 0;
  my_memset(s, 0, n_octets + 1);
  p = champ->pc;
  c = 0;
  while (c != 1)
    {
      s[c] = vm->arena[p];
      printf("s[c] = %d\nnb = %d\n", s[c], nb);
      p = (p + 1) % MEM_SIZE;
      c++;
    }
  nb = (s[0] << (8 * 3)) + (s[1] << (8 * 2)) + (s[2] << 8) + s[3];
      printf("nb = %d\n", nb);
  return (0);
}


int		get_size_octet_code(unsigned char codage)
{
  int		c;
  unsigned char	octet;
  int		nb;

  nb = 0;
  c = 0;
  while (c != 4)
    {
      octet = codage;
      octet = octet >> ((3 - c) * 2);
      octet = octet % 4;
      if (octet == 0)
	  return (nb);
      nb += get_size(octet);
      c++;
    }
  return (nb);
}

int		get_octet_code(int special_func, int parameter, char codage)
{
  unsigned char	c;

  if (special_func != 0)
    return (get_size_octet_code(codage));
  c = codage;
  c = c >> ((3 - parameter) * 2);
  c = c % 4;
  return (c);
}

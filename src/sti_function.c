/*
** sti_function.c for sti_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:50:29 2016 Marwane
** Last update Sun Mar 27 14:05:37 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

int	check_stioctet(int octet[])
{
  if (octet[0] != T_REG ||
      (octet[1] != T_REG && octet[1] != T_DIR &&
       octet[1] != T_IND) ||
      (octet[2] != T_DIR && octet[2] != T_REG) ||
      octet[3] != 0)
    return (1);
  return (0);
}

int	init_stiopeparams(t_vm *vm, t_champ *champ, int octet, int *p)
{
  if (get_spesize(octet) == 1)
    {
      *p = (char)(champ->registres[(get_myint(vm, champ->pc, 1) - 1) % 16]);
      return (1);
    }
  *p = (short)get_myint(vm, champ->pc, 2);
  return (2);
}

int	sti_function(t_vm *vm, t_champ *champ)
{
  int	octet[4];
  int	i;
  int	p1;
  int	p2;
  int	p3;

  i = 0;
  while (i != 4)
    {
      octet[i] = get_octet_code(0, i, vm->arena[champ->pc]);
      i++;
    }
  champ->cycles_to_wait += 25;
  champ->pc = (champ->pc + 1) % MEM_SIZE;
  i = init_opeparams(vm, champ, octet[0], &p1);
  champ->pc = (champ->pc + i) % MEM_SIZE;
  i = init_opeparams(vm, champ, octet[1], &p2);
  champ->pc = (champ->pc + i) % MEM_SIZE;
  i = init_opeparams(vm, champ, octet[2], &p3);
  champ->pc = (champ->pc + i) % MEM_SIZE;
  if (check_stioctet(octet) == 0)
    vm->arena[(p3 + p2) % MEM_SIZE] = p1;
  return (1);
}

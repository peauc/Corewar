/*
** check_champs_cors.c for check_champs in /home/da-fon_s/rendu/corewar
**
** Made by Da Fonseca Samuel
** Login   <da-fon_s@epitech.net>
**
** Started on  Tue Mar 22 15:55:37 2016 Da Fonseca Samuel
** Last update Sun Mar 27 20:02:35 2016 Marwane
*/

#include "vm_corewar.h"

int		check_prog_blocs(char *name, int size, int magic)
{
  if (my_strlen(name) == 0 ||
      size < 1 ||
      magic < 1)
    return (-1);
  return (0);
}

void		check_champs_error(t_vm *vm)
{
  t_champ	*tmp;
  int		i;

  i = 0;
  tmp = vm->champs;
  while (i < vm->progs_nb)
    {
      if (check_prog_blocs(tmp->name, tmp->size, tmp->magic) == -1)
      	{
	  tmp = tmp->next;
      	  del_prog(vm, i);
      	  del_champ(vm, i);
      	}
      else
	{
	  i++;
	  tmp = tmp->next;
	}
    }
}

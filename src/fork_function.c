/*
** fork_function.c for fork_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:50:44 2016 Marwane
** Last update Sun Mar 27 08:36:12 2016 Marwane
*/

#include "vm_corewar.h"

char		*get_current_prog_name(t_vm *vm, t_champ *champ)
{
  t_champ	*tmp_champ;
  t_prog	*tmp_prog;

  tmp_champ = vm->champs;
  tmp_prog = vm->progs;
  while (tmp_champ != champ && tmp_champ != NULL)
    {
      tmp_champ = tmp_champ->next;
      tmp_prog = tmp_prog->next;
    }
  if (tmp_champ)
    return (tmp_prog->prog_name);
  return (NULL);
}

int	fork_function(t_vm *vm, t_champ *champ)
{
  char	*file_path;

  if ((file_path = get_current_prog_name(vm, champ)) != NULL)
    {
      add_champ_to_list(vm, file_path,
			((champ->pc + get_myint(vm, champ->pc, 2)) % IDX_MOD)
			% MEM_SIZE);
      add_prog(vm, file_path);
    }
  champ->cycles_to_wait += 800;
  return (1);
}

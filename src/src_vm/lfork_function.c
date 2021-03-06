/*
** fork_function.c for fork_function in /home/khsime_m/rendu/projets/CPE/vm_corewar/src
**
** Made by Marwane
** Login   <khsime_m@epitech.net>
**
** Started on  Sat Mar 26 09:50:44 2016 Marwane
** Last update Sun Mar 27 19:42:31 2016 Da Fonseca Samuel
*/

#include "vm_corewar.h"

char		*get_current_prog_name_lfork(t_vm *vm, t_champ *champ)
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

void	init_son_values_lfork(t_prog *nprog, t_champ *nchamp,
		       t_prog *fprog)
{
  nprog->prog_number = fprog->prog_number;
  nprog->address = fprog->address;
  nprog->prog_name = my_strdup(fprog->prog_name);
  nchamp->pc = nprog->address;
  nchamp->cycles_to_wait = 1000;
  nchamp->registres[0] = nprog->prog_number;
}

void		init_son_lfork(t_vm *vm, t_champ *champ)
{
  t_champ	*tmp_champ;
  t_prog	*tmp_prog;
  t_prog	*tmp2_prog;

  tmp_champ = vm->champs;
  tmp_prog = vm->progs;
  tmp2_prog = vm->progs;
  while (tmp2_prog && tmp_champ != champ)
    {
      tmp2_prog = tmp2_prog->next;
      tmp_champ = tmp_champ->next;
    }
  tmp_champ = vm->champs;
  while (tmp_champ && tmp_champ->next)
    {
      tmp_prog = tmp_prog->next;
      tmp_champ = tmp_champ->next;
    }
  if (!tmp_champ)
    return ;
  init_son_values_lfork(tmp_prog, tmp_champ, tmp2_prog);
  tmp_champ->pc =
    (tmp_champ->pc + (get_myint(vm, champ->pc, 2))) % MEM_SIZE;
  tmp_prog->address = tmp_champ->pc;
}

int		lfork_function(t_vm *vm, t_champ *champ)
{
  char		*file_path;

  if ((file_path = get_current_prog_name_lfork(vm, champ)) != NULL)
    {
      add_champ_to_list(vm, file_path,
			((champ->pc + get_myint(vm, champ->pc, 2)))
			% MEM_SIZE, 0);
      add_prog(vm, file_path);
      champ->cycles_to_wait += 1000;
      init_son_lfork(vm, champ);
    }
  champ->pc = (champ->pc + 2) % MEM_SIZE;
  return (1);
}

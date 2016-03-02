/*
** set_ftab.c for set_ftab in /home/arnaud_e/rendu/cpe/corewar/src/decompiler
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Mar  2 07:11:29 2016 Arthur ARNAUD
** Last update Wed Mar  2 10:52:11 2016 Arthur ARNAUD
*/

#include "decompiler.h"

ftab	*set_ftab(ftab *tab)
{
  ftab[0] = op_live;
  ftab[1] = op_ld;
  ftab[2] = op_st;
  ftab[3] = op_add;
  ftab[4] = op_sub;
  ftab[5] = op_and;
  ftab[6] = op_or;
  ftab[7] = op_xor;
  ftab[8] = op_zjmp;
  ftab[9] = op_ldi;
  ftab[10] = op_sti;
  ftab[11] = op_fork;
  ftab[12] = op_lld;
  ftab[13] = op_lldi;
  ftab[14] = op_lfork;
  ftab[15] = op_aff;
  return (ftab);
}

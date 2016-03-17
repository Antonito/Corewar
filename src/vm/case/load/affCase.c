/*
** affCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Thu Mar 17 17:59:39 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"

int		affCase(t_hero *hero, t_instruct *new, unsigned char *map,
			int endianness)
{
  int		check;
  t_bytecode	byte;

#ifdef	DEBUG
  write(1, "[Inst] Aff\n", 11);
#endif
  (void)endianness;
  byte.bytecode = (char)map[(hero->loadAddress + hero->pc++) % MEM_SIZE];
  if (!(check = getByteCode(&byte)))
    new->args[0] =
      hero->reg[((map[(hero->loadAddress + hero->pc++) % MEM_SIZE]
		  - 1) % REG_SIZE)] % 256;
  new->time = AFF_TIME;
  return (0);
}

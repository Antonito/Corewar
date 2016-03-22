/*
** lldiCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Tue Mar 22 18:44:56 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"
#include "tools.h"

int	lldiCase(t_hero *hero, t_instruct *new, unsigned char *map,
		 int endianness)
{
  int		i;
  int		check;
  t_bytecode	byte;

#ifdef	DEBUG
  write(1, "[Inst] Lldi\n", 12);
#endif
  i = -1;
  byte.bytecode = (char)map[(hero->loadAddress + hero->pc++) % MEM_SIZE];
  while (++i < 2)
    {
      if (!(check = getByteCode(&byte)))
	new->args[i] =
	  hero->reg[((map[(hero->loadAddress + hero->pc++) % MEM_SIZE] - 1)
		     % REG_SIZE)];
      else if (i < 2 && check == 1)
	new->args[i] = readShort(hero, map, endianness) % MEM_SIZE;
      else if (!i && check == 2)
	new->args[i] = readShort(hero, map, endianness) % MEM_SIZE;
      byte.bytecode <<= 2;
    }
  new->args[2] = (map[(hero->loadAddress + hero->pc++) % MEM_SIZE] - 1)
    % REG_SIZE;
  new->time = LDI_TIME;
  return (0);
}

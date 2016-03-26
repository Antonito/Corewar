/*
** forkCase.c for Corewar in /CPE_2015_corewar/src/vm/case
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Mar 16 14:16:27 2016 Antoine Baché
** Last update Sat Mar 26 15:55:51 2016 Antoine Baché
*/

#include "corewar.h"
#include "bytecode.h"
#include "tools.h"
#include "errors.h"

void		cpyReg(t_hero *hero, t_hero *new)
{
  new->reg[0] = hero->reg[0];
  new->reg[1] = hero->reg[1];
  new->reg[2] = hero->reg[2];
  new->reg[3] = hero->reg[3];
  new->reg[4] = hero->reg[4];
  new->reg[5] = hero->reg[5];
  new->data = NULL;
  new->isAlone = hero->isAlone;
}

int		forkExec(t_hero *hero, t_instruct *new, unsigned char *map,
			 t_params *params)
{
  t_hero	*newHero;

#ifdef	DEBUG
  write(1, "[Exec] Fork\n", 12);
#endif
  (void)map;
  if (!(newHero = malloc(sizeof(t_hero))) ||
      !(my_bzero(newHero, sizeof(t_hero)),
	newHero->name = my_strndup(hero->name, 129)))
    return (errorMalloc());
  newHero->id = hero->id;
  newHero->loadAddress = hero->loadAddress;
  newHero->pc = (hero->loadAddress + hero->pc + new->args[0]) % IDX_MOD;
  newHero->size = hero->size;
  newHero->comment = NULL;
  newHero->customId = hero->customId;
  newHero->customAddress = hero->customAddress;
  newHero->isAlive = hero->isAlive;
  newHero->carry = hero->carry;
  newHero->inst = NULL;
  newHero->next = hero->next;
  hero->next = newHero;
  cpyReg(hero, newHero);
  ++params->process;
  return (0);
}

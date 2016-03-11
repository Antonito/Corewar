/*
** debug.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 11 10:59:10 2016 Antoine Baché
** Last update Fri Mar 11 11:20:47 2016 Antoine Baché
*/

#include "corewar.h"
#include "tools.h"

void		debugPrintHero(t_hero *heros, int i)
{
  write(1, "\n---- Hero ", 11);
  my_write_nb(i + 1, 1, 1);
  write(1, " ----\n", 6);
  write(1, "Id = ", 5);
  my_write_nb(heros->id, 1, 1);
  write(1, "\nloadAddress = ", 15);
  my_write_nb(heros->loadAddress, 1, 1);
  write(1, "\nname = ", 8);
  write(1, heros->name, my_strlen(heros->name));
  write(1, "\ncomment = ", 11);
  write(1, heros->comment, my_strlen(heros->comment));
  write(1, "\npc = ", 6);
  my_write_nb(heros->pc, 1, 1);
  write(1, "\nisAlive = ", 11);
  (heros->isAlive) ? write(1, "Yes\n", 4) : write(1, "No\n", 3);
}

void		debugInitVm(t_params *data, t_hero *heros)
{
  int		i;
  t_hero	*tmp;

  write(1, "\n---- Params ----\n", 18);
  write(1, "Cycle = ", 8);
  my_write_nb(data->cycle, 1, 1);
  write(1, "\ntotalCycle = ", 14);
  my_write_nb(data->totalCycle, 1, 1);
  write(1, "\ncycleToDie = ", 14);
  my_write_nb(data->cycleToDie, 1, 1);
  write(1, "\nProcess = ", 11);
  my_write_nb(data->process, 1, 1);
  write(1, "\nNbHeros = ", 11);
  my_write_nb(data->nbHeros, 1, 1);
  write(1, "\nnbrCycleDump = ", 16);
  my_write_nb(data->nbrCycleDump, 1, 1);
  write(1, "\nisRunning = ", 11);
  (data->isRunning) ? write(1, "Yes\n", 4) : write(1, "No\n", 3);
  i = 0;
  tmp = heros;
  while (i < data->nbHeros)
    {
      debugPrintHero(tmp, i++);
      tmp = tmp->next;
    }
}

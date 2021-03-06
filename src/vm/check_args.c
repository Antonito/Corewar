/*
** check_args.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Mar  7 14:43:06 2016 Antoine Baché
** Last update Sat Mar 26 20:14:53 2016 Antoine Baché
*/

#include "corewar.h"
#include "tools.h"

int		checkHerosLoading(int *i, char **av, t_hero *heros)
{
  if (av[*i][0] == '-')
    return (write(2, "Corewar executable missing\n", 27), 1);
  else if (++*i && loadHero(heros, av[*i - 1]))
    return (1);
  return (0);
}

int		checkHerosOptions(int ac, char **av, int *i, t_hero *heros)
{
  int		opt;
  int		nbHero;

  nbHero = 1;
  while (opt = 0, *i < ac)
    {
      if ((!my_strncmp_("-n", av[*i], 3) && (*i += 2) && (opt = N_OPTION) &&
	   nOption(heros, *i - 1, av)) ||
	  (!opt && !my_strncmp_("-a", av[*i], 3) && (*i += 2) &&
	   (opt = A_OPTION) && aOption(heros, *i - 1, av)))
	return (1);
      if (((opt == N_OPTION && !my_strncmp("-a", av[*i], 3) && (*i += 2) &&
	    aOption(heros, *i - 1, av)) ||
	   (opt == A_OPTION && !my_strncmp("-n", av[*i], 3) && (*i += 2) &&
	    nOption(heros, *i - 1, av))) || checkHerosLoading(i, av, heros))
	return (1);
      if (++nbHero, *i < ac)
	{
	  if (addHero(heros, nbHero))
	    return (1);
	  heros = heros->next;
	}
    }
  return (0);
}

int		checkOptions(int ac, char **av, t_params *data, t_hero *heros)
{
  int		i;
  t_hero	*tmp;
  int		count;

  i = 1;
  tmp = heros;
  if (!my_strncmp_("-dump", av[i], 6) && (i += 2) && dumpOption(av, data))
    return (1);
  if (checkHerosOptions(ac, av, &i, heros))
    return (1);
  count = 0;
  while (tmp && ++count)
    tmp = tmp->next;
  if (!(data->nbHeros = count))
    return (write(2, "Error : Invalid number of file\n", 31), 1);
#ifndef	BONUS
  if (data->nbHeros > 4)
    return (write(2, "Error : Invalid number of file\n", 31), 1);
#endif
  return (0);
}

int		check_args(int ac, char **av)
{
  t_params	data;
  t_hero	*heros;

  heros = NULL;
  initParams(&data);
  if (!(heros = initHero(heros)))
    return (1);
  if (ac < 2)
    return (writeUsage(av[0]), 1);
  if (checkOptions(ac, av, &data, heros) || initVm(&data, heros))
    return (freeHero(heros, data.process), 1);
  return (freeHero(heros, data.process), 0);
}

/*
** check_args.c for Corewar in /CPE_2015_corewar/src/vm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Mar  7 14:43:06 2016 Antoine Baché
** Last update Fri Mar 11 08:27:30 2016 Antoine Baché
*/

#include "corewar.h"
#include "tools.h"

int	checkHerosOptions(int ac, char **av, int *i, t_hero *heros)
{
  while (*i < ac)
    {
      if (!my_strncmp("-n", av[*i], 3) && (*i += 2) &&
	  nOption(heros, *i - 1, av))
	return (1);
      if (!my_strncmp("-a", av[*i], 3) && (*i += 2) &&
	  aOption(heros, *i - 1, av))
	return (1);
      if (av[*i][0] == '-')
	return (write(2, "Corewar executable missing\n", 27), 1);
      else if (++*i && loadHero(heros, av[*i - 1]))
	return (1);
      if (*i < ac)
	{
	  if (addHero(heros))
	    return (1);
	  heros = heros->next;
	}
    }
  return (0);
}

int	checkOptions(int ac, char **av, t_params *data, t_hero *heros)
{
  int	i;

  i = 1;
  if (!my_strncmp("-dump", av[i], 6) && (i += 2) && dumpOption(av, data))
    return (1);
  if (checkHerosOptions(ac, av, &i, heros))
    return (1);
  /* Penser a set data->nbHeros */
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
  if (checkOptions(ac, av, &data, heros))
    return (freeHero(heros), 1);
  return (freeHero(heros), 0);
}

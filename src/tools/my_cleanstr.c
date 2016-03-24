/*
** my_cleanstr.c for corewar in /CPE_2015_corewar
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Thu Mar 24 15:37:46 2016 Ludovic Petrenko
** Last update Thu Mar 24 16:14:26 2016 Ludovic Petrenko
*/

void	my_cleanstr(char *str)
{
  int	i;
  int	decal;

  i = 0;
  decal = 1;
  while (str[i + decal])
    {
      if ((str[i] == ' ' || str[i] == '\t') &&
	  (str[i + decal] == ' ' || str[i + decal] == '\t'))
	{
	  if ((str[i] == ' ' && str[i + decal] == '\t') ||
	      (str[i + decal] == ' ' && str[i] == '\t'))
	    str[i] = ' ';
	  decal++;
	}
      else
	{
	  str[i + 1] = str[i + decal];
	  i++;
	}
    }
  str[i] = 0;
}

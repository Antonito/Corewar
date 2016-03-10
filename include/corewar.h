/*
** corewar.h for Corewar in /CPE_2015_corewar/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 11:30:01 2016 Antoine Baché
** Last update Thu Mar 10 14:14:09 2016 Antoine Baché
*/

#ifndef	COREWAR_H_
# define COREWAR_H_

/*
** Arg parsing
*/
int		writeUsage(char *);
int		check_args(int, char **);

/*
** Status messages
*/
int	playerAlive(int, char *);
int	playerWins(int, char *);

#endif /* !COREWAR_H_ */

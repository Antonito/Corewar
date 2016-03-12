/*
** corewar.h for Corewar in /CPE_2015_corewar/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 11:30:01 2016 Antoine Baché
** Last update Sat Mar 12 06:14:36 2016 Antoine Baché
*/

#ifndef	COREWAR_H_
# define COREWAR_H_
# define MAX_HERO	4

#include <stdbool.h>

typedef struct		s_hero
{
  int			id;
  int			loadAddress;
  char			*name;
  char			*comment;
  char			*data;
  int			pc;
  int			size;
  bool			customId;
  bool			customAddress;
  bool			isAlive;
  struct s_hero		*next;
}			t_hero;

typedef	struct		s_params
{
  int			cycle;
  long int		totalCycle;
  int			cycleToDie;
  int			process;
  int			nbHeros;
  int			nbrCycleDump;
  bool			isRunning;
}			t_params;

int			vm(t_params *, t_hero *, char *);

/*
** Arg parsing
*/
int			writeUsage(char *);
int			check_args(int, char **);

/*
** Args
*/
int			loadHero(t_hero *, char *);
int			nOption(t_hero *, int, char **);
int			aOption(t_hero *, int, char **);
int			dumpOption(char **, t_params *);

/*
** Init
*/
int			addHero(t_hero *);
t_hero			*initHero(t_hero *);
void			initParams(t_params *);
int			initVm(t_params *, t_hero *);

/*
** Place
*/
int			placeHeros(t_hero *, int);

/*
** Free
*/
void			freeHero(t_hero *);

/*
** Status messages
*/
int			playerAlive(int, char *);
int			playerWins(int, char *);

/*
** Debug
*/
void			debugInitVm(t_params *, t_hero *);

#endif /* !COREWAR_H_ */

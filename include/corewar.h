/*
** corewar.h for Corewar in /CPE_2015_corewar/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 11:30:01 2016 Antoine Baché
** Last update Thu Mar 17 01:34:59 2016 Antoine Baché
*/

#ifndef	COREWAR_H_
# define COREWAR_H_
# define MAX_HERO	4
# define BUFF_SIZE	4096

# include <stdbool.h>
# include "common.h"
# ifdef	DEBUG
#  include <unistd.h>
# endif /* DEBUG */

typedef enum		e_options
  {
    N_OPTION		= 1,
    A_OPTION		= 2
  }			t_options;

typedef enum		e_time
  {
    AFF_TIME		= 2,
    LD_TIME		= 5,
    AND_TIME		= 6,
    OR_TIME		= AND_TIME,
    XOR_TIME		= AND_TIME,
    ST_TIME		= 8,
    LIVE_TIME		= 10,
    LLD_TIME		= LIVE_TIME,
    ADD_TIME		= LIVE_TIME,
    SUB_TIME		= LIVE_TIME,
    ZJMP_TIME		= 20,
    LDI_TIME		= 25,
    STI_TIME		= LDI_TIME,
    LLDI_TIME		= 50,
    FORK_TIME		= 800,
    LFORK_TIME		= 1000
  }			t_time;

typedef struct		s_instruct
{
  int			type;
  int			bytecode;
  int			args[3];
  int			time;
  struct s_instruct	*next;
}			t_instruct;

typedef struct		s_hero
{
  int			id;
  int			loadAddress;
  char			*name;
  char			*comment;
  unsigned char		*data;
  int			pc;
  char			reg[REG_NUMBER];
  bool			carry;
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

typedef	int (**ptrtab)(t_hero *, t_instruct *, unsigned char *, int);

int			vm(t_params *, t_hero *, unsigned char *, ptrtab);

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
** Exec
*/
int			executeOrders(t_hero *, unsigned char *, ptrtab, int);

/*
** Init
*/
ptrtab			selector(void);
int			addHero(t_hero *);
t_hero			*initHero(t_hero *);
void			initParams(t_params *);
int			initVm(t_params *, t_hero *);
int			placeHeros(t_hero *, int);
int			orderHeros(t_hero *);

/*
** Free
*/
void			freeHero(t_hero *, int);

/*
** Status messages
*/
int			playerAlive(int, char *);
int			playerWins(int, char *);

/*
** Dump
*/
int			dumpMem(unsigned char *);

/*
** Value
*/
int			readInt(t_hero *, unsigned char *, int);
short			readShort(t_hero *, unsigned char *, int);

/*
** Debug
*/
void			debugInitVm(t_params *, t_hero *);

/*
** Cases
*/
int			addCase(t_hero *, t_instruct *, unsigned char *,
				int);
int			affCase(t_hero *, t_instruct *, unsigned char *,
				int);
int			andCase(t_hero *, t_instruct *, unsigned char *,
				int);
int			forkCase(t_hero *, t_instruct *, unsigned char *,
				 int);
int			ldCase(t_hero *, t_instruct *, unsigned char *,
			       int);
int			ldiCase(t_hero *, t_instruct *, unsigned char *,
				int);
int			lforkCase(t_hero *, t_instruct *, unsigned char *,
				  int);
int			liveCase(t_hero *, t_instruct *, unsigned char *,
				 int);
int			lldCase(t_hero *, t_instruct *, unsigned char *,
				int);
int			lldiCase(t_hero *, t_instruct *, unsigned char *,
				 int);
int			orCase(t_hero *, t_instruct *, unsigned char *,
			       int);
int			stCase(t_hero *, t_instruct *, unsigned char *,
			       int);
int			stiCase(t_hero *, t_instruct *, unsigned char *,
				int);
int			subCase(t_hero *, t_instruct *, unsigned char *,
				int);
int			xorCase(t_hero *, t_instruct *, unsigned char *,
				int);
int			zjmpCase(t_hero *, t_instruct *, unsigned char *,
				 int);

#endif /* !COREWAR_H_ */

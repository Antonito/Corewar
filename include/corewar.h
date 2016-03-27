/*
** corewar.h for Corewar in /CPE_2015_corewar/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 11:30:01 2016 Antoine Baché
** Last update Sun Mar 27 18:07:09 2016 Antoine Baché
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
  unsigned int		pcSave;
  int			args[3];
  int			time;
  struct s_instruct	*next;
}			t_instruct;

typedef struct		s_hero
{
  int			id;
  unsigned int	       	loadAddress;
  char			*name;
  char			*comment;
  unsigned char		*data;
  unsigned int 		pc;
  unsigned int		reg[REG_NUMBER];
  bool			carry;
  unsigned int		size;
  bool			customId;
  bool			customAddress;
  bool			isAlive;
  struct s_instruct	*inst;
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
  int			nbrLive;
  int			endianness;
  bool			isRunning;
  bool			currentCycle;
  int			lastLive;
}			t_params;

typedef	int (**ptrtab)(t_hero *, t_instruct *, unsigned char *, int);
typedef	int (**insttab)(t_hero *, t_instruct *, unsigned char *,
			t_params *);

typedef struct		s_funcPtr
{
  ptrtab		load;
  insttab		exec;
}			t_funcPtr;

int			vm(t_params *, t_hero *, unsigned char *, t_funcPtr *);
void			cpyReg(t_hero *, t_hero *);
t_hero			*genLive(t_hero *, t_params *);

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
int			executeOrders(t_hero *, unsigned char *,
				      t_funcPtr *, t_params *);

/*
** Init
*/
ptrtab			selector(void);
insttab			selectorExec(void);
int			addHero(t_hero *, int);
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
unsigned int   		readInt(t_hero *, unsigned char *, int);
unsigned short	       	readShort(t_hero *, unsigned char *, int);

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

/*
** Execs
*/
int			addExec(t_hero *, t_instruct *, unsigned char *,
				t_params *);
int			affExec(t_hero *, t_instruct *, unsigned char *,
				t_params *);
int			andExec(t_hero *, t_instruct *, unsigned char *,
				t_params *);
int			forkExec(t_hero *, t_instruct *, unsigned char *,
				 t_params *);
int			ldExec(t_hero *, t_instruct *, unsigned char *,
			       t_params *);
int			ldiExec(t_hero *, t_instruct *, unsigned char *,
				t_params *);
int			lforkExec(t_hero *, t_instruct *, unsigned char *,
				  t_params *);
int			liveExec(t_hero *, t_instruct *, unsigned char *,
				 t_params *);
int			lldExec(t_hero *, t_instruct *, unsigned char *,
				t_params *);
int			lldiExec(t_hero *, t_instruct *, unsigned char *,
				 t_params *);
int			orExec(t_hero *, t_instruct *, unsigned char *,
			       t_params *);
int			stExec(t_hero *, t_instruct *, unsigned char *,
			       t_params *);
int			stiExec(t_hero *, t_instruct *, unsigned char *,
				t_params *);
int			subExec(t_hero *, t_instruct *, unsigned char *,
				t_params *);
int			xorExec(t_hero *, t_instruct *, unsigned char *,
				t_params *);
int			zjmpExec(t_hero *, t_instruct *, unsigned char *,
				 t_params *);

#endif /* !COREWAR_H_ */

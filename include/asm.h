/*
** asm.h for Corewar in /CPE_2015_corewar/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 11:30:01 2016 Antoine Baché
** Last update Tue Mar  1 03:50:36 2016 Antoine Baché
*/

#ifndef	ASM_H_
# define ASM_H_

# define OFFSETOF(TYPE, MEMBER)	((size_t) & ((TYPE *)0)->MEMBER)

# include <stdlib.h>
# include <endian.h>
# include "header.h"

/*
** Endian.h -> __BYTE__ORDER == LITTLE_ENDIAN or BIG_ENDIAN
**
** Ecriture (function + 1)
** Ecriture bytecode
** Ecriture sur 1 / 2 / 4 octets des values
*/
typedef	struct		s_parsing
{
  char			function;
  unsigned char		bytecode;
  int			value[3];
  char			reg[3];
  struct s_parsing	*next;
}			t_parsing;

typedef	struct		s_data
{
  int			fd;
  int			line;
  t_header		header;
  t_parsing		*elem;
  char			**ins;
  char			*str;
  int			(**list)(struct s_data *, t_parsing *, int *);
}			t_data;

typedef	int (**ptrtab)(t_data *, t_parsing *, int *);

typedef	int (**writetab)(int, t_parsing *);

writetab		selector_write(void);
ptrtab			selector(void);

int			getRegisterSti(t_data *, t_parsing *, int *, int);

/*
**  ________________________________________________________________________
** /                                                                        \
** | EpurStr -> Formate les lignes afin qu'elles correspondent à la syntaxe |
** |            attendue par le compilo                                     |
** | Si une ligne contient un label elle est formatée ainsi :               |
** | "label: instruction arg1 arg2 arg3"                                    |
** | Si une ligne ne contient pas de label elle est formatée ainsi :        |
** | "\tinstruction arg1 arg2 arg3"                                         |
** \________________________________________________________________________/
*/
void			epurStr(char *);

/*
** parser.c
*/
int			check_file(char *);

/*
** header.c
*/
int			prepareHeader(int, t_header *, int *);

/*
** write_file.c
*/
int			write_file(char *, t_data *);

/*
** get*.c
*/
int			getIndiValue(t_data *, t_parsing *, int *, int);
int			getLabel(t_data *, t_parsing *, int *, int);
int			getFunction(t_data *, t_parsing *);
int			getArgs(t_data *, t_parsing *, int);

/*
** free.c
*/
void			free_elems(t_data *);

/*
** Cases
*/
int			addCase(t_data *, t_parsing *, int *);
int			affCase(t_data *, t_parsing *, int *);
int			andCase(t_data *, t_parsing *, int *);
int			forkCase(t_data *, t_parsing *, int *);
int			ldCase(t_data *, t_parsing *, int *);
int			ldiCase(t_data *, t_parsing *, int *);
int			lforkCase(t_data *, t_parsing *, int *);
int			liveCase(t_data *, t_parsing *, int *);
int			lldCase(t_data *, t_parsing *, int *);
int			lldiCase(t_data *, t_parsing *, int *);
int			orCase(t_data *, t_parsing *, int *);
int			stCase(t_data *, t_parsing *, int *);
int			stiCase(t_data *, t_parsing *, int *);
int			subCase(t_data *, t_parsing *, int *);
int			xorCase(t_data *, t_parsing *, int *);
int			zjmpCase(t_data *, t_parsing *, int *);

/*
** Write
*/
int			writeSti(int, t_parsing *);
int			writeLd(int, t_parsing *);
int			writeZjmp(int, t_parsing *);
int			writeLive(int, t_parsing *);
int			writeFork(int, t_parsing *);
int			writeLfork(int, t_parsing *);
int			writeAdd(int, t_parsing *);
int			writeSub(int, t_parsing *);
int			writeLld(int, t_parsing *);
int			writeSt(int, t_parsing *);

#endif /* !ASM_H_ */

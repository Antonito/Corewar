/*
** asm.h for Corewar in /CPE_2015_corewar/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 11:30:01 2016 Antoine Baché
** Last update Fri Feb 26 15:00:13 2016 Antoine Baché
*/

#ifndef	ASM_H_
# define ASM_H_

# include "header.h"

/*
** Ecriture (function + 1)
** Ecriture bytecode
** Ecriture sur 1 / 2 / 4 octets des values
*/
typedef	struct		s_parsing
{
  char			function;
  char			bytecode;
  int			value1;
  int			value2;
  int			value3;
  struct s_parsing	*next;
}			t_parsing;

typedef	struct		s_data
{
  int			fd;
  int			line;
  t_header		header;
  t_parsing		*elem;
  char			**ins;
  int			(**list)(struct s_data *, char *, t_parsing *, int *);
}			t_data;

typedef	int (**ptrtab)(t_data *, char *, t_parsing *, int *);

ptrtab			selector(void);

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
int			getFunction(t_data *, char *, t_parsing *);
int			getArgs(t_data *, char *, t_parsing *, int);

/*
** free.c
*/
void			free_elems(t_parsing *, char **);

/*
** Cases
*/
int			addCase(t_data *, char *, t_parsing *, int *);
int			affCase(t_data *, char *, t_parsing *, int *);
int			andCase(t_data *, char *, t_parsing *, int *);
int			forkCase(t_data *, char *, t_parsing *, int *);
int			ldCase(t_data *, char *, t_parsing *, int *);
int			ldiCase(t_data *, char *, t_parsing *, int *);
int			lforkCase(t_data *, char *, t_parsing *, int *);
int			liveCase(t_data *, char *, t_parsing *, int *);
int			lldCase(t_data *, char *, t_parsing *, int *);
int			lldiCase(t_data *, char *, t_parsing *, int *);
int			orCase(t_data *, char *, t_parsing *, int *);
int			stCase(t_data *, char *, t_parsing *, int *);
int			stiCase(t_data *, char *, t_parsing *, int *);
int			subCase(t_data *, char *, t_parsing *, int *);
int			xorCase(t_data *, char *, t_parsing *, int *);
int			zjmpCase(t_data *, char *, t_parsing *, int *);

#endif /* !ASM_H_ */

/*
** decompiler.h for Corewar in /CPE_2015_corewar/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 15:57:16 2016 Antoine Baché
** Last update Sun Mar  6 04:48:01 2016 Antoine Baché
*/

#ifndef	DECOMPILER_H_
# define DECOMPILER_H_

# include "bytecode.h"

typedef	struct	s_read
{
  char		**inst;
  unsigned char	buff[5];
  t_bytecode	byte;
  int		fd;
  int		new;
  int		sum;
}		t_read;

typedef	int (**ptrtab)(t_read *);

ptrtab	selector(void);

/*
** check_file.c
*/
int	check_file(char *);

/*
** loader.c
*/
int	load(int, int);

/*
** load_champ.c
*/
int	load_champ(int, int);

/*
** free.c
*/
int	freeLoadChamp(char **, ptrtab);

/*
** write_instruction.c
*/
int	write_indirect(int, unsigned char *, int);
int	write_direct(int, unsigned char *, int);
int	write_params(int, unsigned char *, int);
int	write_instruction(int, unsigned char *, char **);

/*
** Cases
*/
int	addCase(t_read *);
int	affCase(t_read *);
int	andCase(t_read *);
int	forkCase(t_read *);
int	ldCase(t_read *);
int	ldiCase(t_read *);
int	lforkCase(t_read *);
int	liveCase(t_read *);
int	lldCase(t_read *);
int	lldiCase(t_read *);
int	orCase(t_read *);
int	stCase(t_read *);
int	stiCase(t_read *);
int	subCase(t_read *);
int	xorCase(t_read *);
int	zjmpCase(t_read *);

#endif /* !DECOMPILER_H_  */

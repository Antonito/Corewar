/*
** asm.h for Corewar in /CPE_2015_corewar/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 11:30:01 2016 Antoine Baché
** Last update Thu Feb 25 23:25:40 2016 Antoine Baché
*/

#ifndef	ASM_H_
# define ASM_H_

# include "header.h"

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
  int			line;
  t_header		header;
  t_parsing		*elem;
}			t_data;

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
** free.c
*/
void			free_elems(t_parsing *);

#endif /* !ASM_H_ */

/*
** tools.h for Corewar in /CPE_2015_corewar/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 16:04:32 2016 Antoine Baché
** Last update Tue Mar 22 14:03:49 2016 Antoine Baché
*/

#ifndef	TOOLS_H_
# define TOOLS_H_
# define ABS(X)		((X > 0) ? (X) : -(X))

# include <unistd.h>
# include <stdbool.h>
# include "get_next_line.h"

bool		isNum(const char *);
int		my_put_nbr(int);
char		*my_strncpy(char *, char *, int);
int		my_strncmp(const char *, const char *, int);
int		my_strcmp(const char *, const char *);
int		my_getnbr(char *);
char		*my_strdup(char *);
char		*my_strndup(char *, int);
void		my_putchar(char);
void		my_putstr(char *);
int		my_strlen(const char *);
char		*my_strncat(char *, char *, int);
char		*my_strcpy(char *, const char *);
void		my_bzero(void *, int);
int		my_write_nb(int, int, int);
int		my_write(char, int);
short		reverseShort(short *, int);
int		reverseInt(int *, int);
unsigned short	reverseUShort(unsigned short *, int);
unsigned int	reverseUInt(unsigned int *, int);

#endif	/* !TOOLS_H_ */

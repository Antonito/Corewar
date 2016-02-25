/*
** get_next_line.h for get_next_line in /CPE_2015_getnextline
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Jan  4 10:26:37 2016 Antoine Baché
** Last update Sun Jan 17 09:27:35 2016 Antoine Baché
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# ifndef READ_SIZE
#  define READ_SIZE (14)
# endif	/* !READ_SIZE */

# include <unistd.h>
# include <stdlib.h>

int	find_n(char [], int);
char	*buffToStr(char *, char *, char);
char	*my_realloc(char *, int);
char	*get_next_line(const int);
int	my_strlen1(char *);

#endif /* !GET_NEXT_LINE_H_ */

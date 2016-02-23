/*
** tools.h for Corewar in /CPE_2015_corewar/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 16:04:32 2016 Antoine Baché
** Last update Tue Feb 23 16:19:01 2016 Antoine Baché
*/

#ifndef	TOOLS_H_
# define TOOLS_H_

# include <unistd.h>

int	my_put_nbr(int);
char	*my_strncpy(char *, char *, int);
int	my_strncmp(char *, char *, int);
int	my_strcmp(char *, char *);
int	my_getnbr(char *);
char	*my_strdup(char *);
char	*my_strndup(char *, int);
void	my_putchar(char);
void	my_putstr(char *);
int	my_strlen(const char *);
char	*my_strncat(char *, char *, int);
char	*my_strcpy(char *, const char *);
void	my_bzero(void *, int);

#endif	/* !TOOLS_H_ */

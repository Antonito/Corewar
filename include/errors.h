/*
** errors.h for Corewar in /CPE_2015_corewar/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 19:45:15 2016 Antoine Baché
** Last update Thu Feb 25 19:53:08 2016 Antoine Baché
*/

#ifndef	ERRORS_H_
# define ERRORS_H_

# include <unistd.h>

/*
** Errors
*/
int	errorRegister(int);
int	errorLabel(char *, int);
int	errorSyntax(int);

/*
** Warnings
*/
int	warningTooBig(int);
int	warningIndirection(int);

/*
** Common Errors
*/
int	errorFileName(char *);
int	errorMalloc(void);

#endif /* ERRORS_H_ */

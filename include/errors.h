/*
** errors.h for Corewar in /CPE_2015_corewar/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Feb 25 19:45:15 2016 Antoine Baché
** Last update Wed Mar 16 19:08:53 2016 Antoine Baché
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
int	errorChamp(void);
int	errorName(int, char *);
int	errorFileType(const char *);
int	errorUsed(int);

/*
** Warnings
*/
int	warningTooBig(int);
int	warningIndirection(int);
int	warningComment(int, char *);

/*
** Common Errors
*/
int	errorFileName(const char *);
int	errorMalloc(void);

#endif /* ERRORS_H_ */

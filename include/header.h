/*
** header.h for Corewar in /CPE_2015_corewar/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 15:45:28 2016 Antoine Baché
** Last update Fri Mar 11 05:51:31 2016 Antoine Baché
*/

#ifndef	HEADER_H_
# define HEADER_H_

/*
** Magic = 0xF383EA00
*/
typedef	struct	s_header
{
  int		magic;
  char		name[129];
  int		prog_size;
  char		comment[2049];
}		t_header;

#endif /* !HEADER_H_ */

/*
** header.h for Corewar in /CPE_2015_corewar/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 15:45:28 2016 Antoine Baché
** Last update Tue Feb 23 15:52:05 2016 Antoine Baché
*/

#ifndef	HEADER_H_
# define HEADER_H_

typedef	struct	s_header
{
  char		head[4];
  char		name[129];
  char		empty6[6];
  char		id;
  char		comment[2050];
  char		empty2[2];
}		t_header;

#endif /* !HEADER_H_ */

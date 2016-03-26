/*
** endiannes.h for Corewar in /CPE_2015_corewar/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Mar  1 14:48:56 2016 Antoine Baché
** Last update Thu Mar 24 15:00:48 2016 Antoine Baché
*/

#ifndef	ENDIANNESS_H_
# define ENDIANNESS_H_

# include <stdint.h>

typedef	enum		e_endian
  {
    UNKNOWN		= -1,
    LITTLE_ENDIAN	= 0,
    BIG_ENDIAN		= 1
  }			t_endian;

typedef	union		u_endianness
{
  int32_t	       	intvalue;
  char			value[sizeof(int32_t)];
}			t_endianness;

int			findEndian(void);

#endif /* !ENDIANNESS_H_ */

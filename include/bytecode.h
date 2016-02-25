/*
** bytecode.h for Corewar in /CPE_2015_corewar/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Feb 24 19:24:20 2016 Antoine Baché
** Last update Thu Feb 25 01:19:56 2016 Antoine Baché
*/

#ifndef	BYTECODE_H_
# define BYTECODE_H_

typedef struct	s_bitfield
{
  unsigned int	one : 1;
  unsigned int	two : 1;
  unsigned int	three : 1;
  unsigned int	four : 1;
  unsigned int	five : 1;
  unsigned int	six : 1;
  unsigned int	seven : 1;
  unsigned int	eight : 1;
}		t_bitfield;

typedef	union	u_bytecode
{
  char		bytecode;
  t_bitfield	bits;
}		t_bytecode;

int		getByteCode(t_bytecode *);

#endif /* !BYTECODE_H_  */

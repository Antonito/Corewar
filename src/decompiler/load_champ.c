/*
** load_champ.c for Corewar in /CPE_2015_corewar/src/decompiler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Feb 24 16:53:31 2016 Antoine Baché
** Last update Thu Feb 25 01:52:51 2016 Antoine Baché
*/

#include <unistd.h>
#include <stdlib.h>
#include "decompiler.h"
#include "tools.h"

int	errorChamp(void)
{
  write(2, "Error while loading champion\n", 29);
  return (1);
}

int	prepare_ins(char **inst)
{
  inst[16] = NULL;
  if (!(inst[0] = my_strdup("live ")) || !(inst[1] = my_strdup("ld ")) ||
      !(inst[2] = my_strdup("st ")) || !(inst[3] = my_strdup("add ")) ||
      !(inst[4] = my_strdup("sub ")) || !(inst[5] = my_strdup("and ")) ||
      !(inst[6] = my_strdup("or ")) || !(inst[7] = my_strdup("xor ")) ||
      !(inst[8] = my_strdup("zjmp ")) || !(inst[9] = my_strdup("ldi ")) ||
      !(inst[10] = my_strdup("sti ")) || !(inst[11] = my_strdup("fork ")) ||
      !(inst[12] = my_strdup("lld ")) || !(inst[13] = my_strdup("lldi ")) ||
      !(inst[14] = my_strdup("lfork ")) || !(inst[15] = my_strdup("aff ")))
    return (1);
  return (0);
}

/*
** Tant que READ != 0
**   Lecture de 1 pour savoir instruction
**   Tableau de pointeur sur fonction pour chaque fonction
**     Lecture du nombre de caractere apres instruction
**     Ecriture
**
**/
int		load_champ(int fd, int new)
{
  t_read	data;
  ptrtab	array;

  data.fd = fd;
  data.new = new;
  if (!(data.sum = 1) || !(data.inst = malloc(sizeof(char *) * 17)) ||
      prepare_ins(data.inst) || !((array = selector())))
    return (errorChamp());
  while (data.sum)
    {
      my_bzero(&data.buff, 5);
      if (!(data.sum = read(fd, &data.buff, 1)))
	break;
      if (write(data.new, "\t", 1) < 0 ||
	  array[((data.buff[0] < 0 || data.buff[0] > 16)
		 ? 16 : data.buff[0] - 1)](&data) ||
	  write(data.new, "\n", 1) < 0)
	return (errorChamp());
    }
  freeLoadChamp(data.inst);
  return (0);
}

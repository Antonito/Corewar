/*
** get_label.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 05:41:59 2016 Antoine Baché
** Last update Fri Mar  4 00:43:43 2016 Antoine Baché
*/

#include "asm.h"
#include "tools.h"
#include "errors.h"

/*
** On donne la ligne actuelle, on cherche la ligne de la premiere fonction du
** label, si elle existe
** /!\  Lseek pour save offset actuel du FD, lseek au debut du fichier pour
**      recherche
** Si la ligne du label est plus grande et qu'il contient une fonction:
**  Save de cette ligne, lseek a l'ancienne position "actuelle" sauvegardee
**  Read jusqu'a la ligne du label en checkant le bytecode a chaque fois
**  Nb de byte = nb d'instruction +
**               bytecode * nb d'instruction ou il est present +
**               nb de byte par args, precise par le bytecode
** Si la ligne du label est plus petite et qu'il contient une fonction:
**  Save nb de ligne + lecture jusqu'a l'ancienne position "actuelle"
**  sauvegardee, tout en faisaint la somme des bytes
**
** La somme des bytes est la valeur a mettre a la place du label
*/
int	getLabelLine(int fd, char *label)
{
  int	saved_pos;
  char	*line;
  int	nb_line;
  int	size;

  if ((saved_pos = lseek(fd, 0, SEEK_CUR)) < 0 ||
      lseek(fd, 0, SEEK_END) < 0 ||
      (free(get_next_line(fd)), lseek(fd, 0, SEEK_SET) < 0))
    return (1);
  nb_line = 0;
  size = my_strlen(label);
  while (++nb_line && (line = get_next_line(fd)))
    {
      epurStr(line);
      if (nb_line > 1 && !my_strncmp(line, label, size))
	return (free(line), (lseek(fd, saved_pos, SEEK_CUR) < 0) ? 1 : nb_line);
      free(line);
    }
  if (lseek(fd, saved_pos, SEEK_CUR) < 0)
    return (1);
  return (1);
}

int		getLowerLabel(t_data *data, t_parsing *elem, int line, int i)
{
  t_parsing	*tmp;

  tmp = data->elem;
  while (tmp != NULL)
    {
      if (line == tmp->line)
	break;
      tmp = tmp->next;
    }
  if (!tmp)
    return (1);
  elem->value[i] = calcOffset(tmp, elem, 1);
  return (0);
}

int	getLabel(t_data *data, char *label, t_parsing *elem, int i)
{
  int	line;

  if ((line = getLabelLine(data->fd, label)) == 1)
    return (1);
  if (line < data->line && getLowerLabel(data, elem, line, i))
    return (1);
  else
    printf("Label is after inst\n");
  printf("Instruction line = %d\n", line);
  printf("Label = %s\n", label);
  printf("Value = %d\n", elem->value[i]);
  free(label);
  return (0);
}

/*
** get_label.c for Corewar in /CPE_2015_corewar/src/asm
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 05:41:59 2016 Antoine Baché
** Last update Thu Mar  3 17:46:48 2016 Antoine Baché
*/

#include "asm.h"
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
int	getLabel(t_data *data, char *label, t_parsing *elem, int i)
{
  printf("Find label !!\n");
  printf("Instruction line = %d\n", data->line);
  printf("Label = %s\n", label);
  return (0);
}

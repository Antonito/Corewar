/*
** get_next_line.c for get_next_line in /CPE_2015_getnextline
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Jan  4 10:26:17 2016 Antoine Baché
** Last update Sun Jan 17 09:25:27 2016 Antoine Baché
*/

#include "get_next_line.h"

int	my_strlen1(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (*str)
    {
      str++;
      i++;
    }
  return (i);
}

char	*my_realloc(char *str, int size)
{
  char	*res;
  int	i;
  int	len;

  if (size == 0)
    return (str);
  if (str != NULL)
    {
      len = my_strlen1(str);
      if ((res = malloc(len + size + 1)) == NULL)
	return (NULL);
      i = -1;
      while (++i < len && (res[i] = str[i]));
      res[i] = '\0';
      free(str);
      return (res);
    }
  return (str);
}

int	find_n(char buff[], int toggle)
{
  int	i;
  int	j;

  i = 0;
  while (buff[i] != '\0'  && buff[i] != '\n' && (++i));
  if (i > -1 && buff[i] == '\n' && toggle == 0)
    return (i);
  if (toggle == 1)
    {
      i++;
      j = 0;
      while (buff[i] != '\0')
	buff[j++] = buff[i++];
      buff[j] = '\0';
      return (i);
    }
  return (-1);
}

char	*buffToStr(char *s1, char *s2, char car)
{
  int	i;

  i = -1;
  while (s2[++i] != car)
    s1[i] = s2[i];
  s1[i] = '\0';
  return (s1);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE + 1] = {0};
  char		*res;
  int		i[2];

  if ((i[0] = find_n(buff, 0)) > -1 &&
      ((res = malloc(sizeof(char) * (i[0] + 1))) != NULL && !(res[0] = 0) &&
       (res = buffToStr(res, buff, '\n')) != NULL && find_n(buff, 1) != -2))
    return (res);
  else if (buff[0] != '\0')
    {
      if ((res = malloc(sizeof(char) * (my_strlen1(buff) + 1))) == NULL)
	return (NULL);
      res = buffToStr(res, buff, '\0');
    }
  else if ((res = malloc(sizeof(char))) == NULL || (res[0] = '\0'))
    return (NULL);
  while (fd >= 0 && (i[1] = read(fd, &buff, READ_SIZE)) > 0 &&
	 !(buff[i[1]] = '\0') && (i[0] = find_n(buff, 0)) > -2)
    if (i[0] > -1 && (res = my_realloc(res, i[0])) &&
	buffToStr(res + my_strlen1(res), buff, '\n') && find_n(buff, 1 ) > -1)
      return (res);
    else if ((res = my_realloc(res, i[1])) != NULL)
      buffToStr(res + my_strlen1(res), buff, '\0');
  return (NULL);
}

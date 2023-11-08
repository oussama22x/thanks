#include "file.h"
void init_all(t_all **all)
{
    (*all)->x = 0;
    (*all)->y = 0;
    (*all)->x_of_map = 0;
    (*all)->y_of_map = 0;;
    (*all)->player_angel = 0;
    (*all)->map = NULL;
    (*all)->longest_line = 0;
}

void count_x_y_of_the_map(t_all **all)
{
    while((*all)->map[(*all)->y_of_map])
    {
        (*all)->x_of_map = 0;
        while ((*all)->map[(*all)->y_of_map][(*all)->x_of_map])
            (*all)->x_of_map++;
        (*all)->y_of_map++;
    }
}
int updatemap(t_all *all)
{
    int x; 
    int i;
    int len;

    len = 0;
    i = 0;  
    x = 0;
    len = ft_strlen(all->map[0]);
    while(all->map[i])
    {
        x = 0;
        while (all->map[i][x])
            x++;
        if(x > len)
            len = x;
        i++;
    }
    return(len);
}

int check_if_close(char **map)
{
  int i;
  int x;

  i = 0;
  x  = 0;
   if(i == 0 && (ft_strnstr(map[i], "0", strlen(map[i]) - 1) ||  ft_strnstr(map[i], "N", strlen(map[i]) - 1) ||\
   ft_strnstr(map[i], "S", strlen(map[i]) - 1) || ft_strnstr(map[i], "E", strlen(map[i]) - 1) || ft_strnstr(map[i], "W", strlen(map[i]) - 1)))
   {
    printf("not close - \n");
    return -1;
    }
  while (map[i])
  {
    x = 0;

    while (map[i][x])
    {
       if(map[i][0] == 'N' || map[i][0] == 'E' || map[i][0] == 'S' || map[i][0] == 'W' || map[i][0] == '0')
       {
            printf("not closex\n");
            return(-1);
       }
       if(map[i][ft_strlen(map[i]) - 1] == 'N' || map[i][ft_strlen(map[i]) - 1] == 'E' ||\
       map[i][ft_strlen(map[i]) - 1] == 'S' || map[i][ft_strlen(map[i]) - 1] == 'W' || map[i][ft_strlen(map[i]) - 1] == '0')
       {
            printf("not closex\n");
            return(-1);
       }
        x++;
    }
    i++;
  }
  i--;
  if((ft_strnstr(map[i], "0", strlen(map[i])) ||  ft_strnstr(map[i], "N", strlen(map[i])) ||\
   ft_strnstr(map[i], "S", strlen(map[i])) || ft_strnstr(map[i], "E", strlen(map[i])) || ft_strnstr(map[i], "W", strlen(map[i]))))
   {
    printf("not close \n");
    return -1;
    }
  return (0);
}

int check_extionts(char *argv)
{
    int i;
    i = 0;
    if(argv[0] == '.')
        i++;
    if(argv[1] == '.')
        i++;
    while(argv[i])
    {
        if(argv[i] == '.')
            if(strcmp((argv + i + 1), "cub"))
            {
                printf("unvalid exti");
                return -1;
            }
            i++;
    }
    return(0);
}
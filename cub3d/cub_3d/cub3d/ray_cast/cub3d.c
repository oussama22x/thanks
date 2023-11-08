/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:11:15 by otamrani          #+#    #+#             */
/*   Updated: 2023/09/29 23:11:21 by otamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int count_pinter(char **ptr)
{
    int i;
    i = 0;
    while(ptr[i])
    {
        i++;
    }
    return(i);
}
int count(char **str)
{
    int i;
    int x;
    int l;

    l = 0;
    i = 0;
    x = 0;
    if(strcmp(str[0], "F") && strcmp(str[0], "C"))
    {
        return (-1);
    }
    else
        i = 1;
    while(str[i][l])
    {
        if(str[i][l] == ',')
            x++;
        if (str[i][l] != ',' && (str[i][l] < '0' || str[i][l] > '9'))
        {
             return (-1);
        }
        l++;
    }
    if(x > 2)
        return (-1);
    return(0);
}

int check_final(t_textr *txtr)
{
    if(count_pinter(txtr->color_c) > 2 || count_pinter(txtr->color_f) > 2)
        return(-1);
    if(count(txtr->color_c) == -1 || count(txtr->color_f) == -1)
        return (-1);
    return(0);
}
int helper(unsigned int *arr, char *str)
{
    char **spl;
    int i;

    i = 0;
    spl = ft_split(str, ',');
    while(spl[i])
    {
        arr[i] = ft_atoi(spl[i]);
        if(arr[i] > 255)
        {
            i = 0;
            while(spl[i])
            {
                free(spl[i]);
                i++;
            }
            return (-1);
        }

        i++;
    }
    return 0;
}
void  get_longest_line(t_all *all)
{
    char **tmp;
    int i;
    int x;

    x  = 0;
    tmp = all->map;
    i = 0;
    all->longest_line = ft_strlen(all->map[0]);
    while(tmp[x])
    {
        i = 0;
        while(tmp[x][i])
        {
            i++;
        }
        if(i > all->longest_line)
            all->longest_line = i;
        x++;
    }
}
int main(int argc, char *argv[])
{
    t_all *all;
    t_textr *txtr;
    t_garbage *garb;

    garb = malloc(sizeof(t_garbage));
    garb->next = NULL;
    int len;
    len = 0;
   if(argc > 1)
   {
   if (check_extionts(argv[1]) == -1 || all_in_one(&all, &txtr, argv, &garb) == -1)
   {
        printf("ERROR\n");
        return(0);
   }
   len = updatemap(all);
   all->garb = garb;
   count_x_y_of_the_map(&all);
   fix_map(&all, len);
    if(check_final(txtr) == -1)
    {
       printf("ERROR3\n");
        return (-1);
    }
    if(ft_atoi_num(txtr) ==  -1)
    {
        printf("ERROR4\n");
        return(-1);
    }
    get_colers(txtr);
    get_longest_line(all);
    show_map(all, txtr);
   }
   else 
    printf("messing file map ☠️ 👽\n");
    return 0;
}

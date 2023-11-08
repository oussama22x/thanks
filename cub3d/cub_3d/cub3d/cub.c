
#include "file.h"
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
        {   i = 0;
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

// void    draw_square(int i, int j, t_all *all, int color)
// {
//     int x = 0;
//     int y = 0;

//     while (y < 64 - 1)
//     {
//         x = 0;
//         while (x < 64 - 1)
//         {
//             mlx_pixel_put(all->mlx,all->win, i * 64 + y + 1 , j * 64 + x + 1, color);
//             x++;
//         }
//         y++;
//     }
// }
// void open_window(t_all **all)
// {
//     int i;
//     int x;
//     int color;


//     i = 0;
//     x = 0;
//     (*all)->mlx = mlx_init();
//     (*all)->win = mlx_new_window((*all)->mlx, 66, (*all)->y_of_map * 64, "CUB3D");
//     (*all)->img = mlx_new_image((*all)->mlx, 896, (*all)->y_of_map * 64);
//     (*all)->addrs = mlx_get_data_addr((*all)->img, &(*all)->bits_per_pixel, &(*all)->size_line, &(*all)->endian);
//     while((*all)->map[x])
//     {
//         i = 0;
//         while((*all)->map[x][i])
//         {
//             if((*all)->map[x][i] == '1')
//             {
//                 color = 0xFF5B38;
//                 draw_square(x, i,(*all), color);
//             }
//             if((*all)->map[x][i] == '0')
//             {
//                 color = 0xB5B5B0;
//                 draw_square(x, i,(*all), color);
//             }
//             if((*all)->map[x][i] == 'N')
//             {
//                 color = 0xB5B5B0;
//                 draw_square(x, i,(*all), color);
//             }
//             i++;
//         }
//         x++;
//     }
//     mlx_loop((*all)->mlx);
// }
// int main(int argc, char *argv[])
// {
//     t_all *all;
//     t_textr *txtr;
//     int len;
//     len = 0;
    
//    if(argc > 1)
//    {
//    if (check_extionts(argv[1]) == -1 || all_in_one(&all, &txtr, argv) == -1)
//    {
//         printf("ERROR\n");
//         return(0);
//    }
//     len = updatemap(all);
//     count_x_y_of_the_map(&all);
//     fix_map(&all, len);
//     if((check_if_close(all->map)) == -1)
//     {
//         printf("ERROR1\n");
//         return -1;
//     }
//     if(check_for_valid_map(all->map) == -1)
//     {
//         printf("ERROR2\n");
//         return(-1);
//     }
//     if(check_final(txtr) == -1)
//     {
//        printf("ERROR3\n");
//         return (-1);
//     }
//     if(ft_atoi_num(txtr) ==  -1)
//     {
//         printf("ERROR4\n");
//         return(-1);
//     }
//     get_colers(txtr);
//    }
//    else 
//     printf("messing file map ☠️ 👽\n");
//     return(0);
// }


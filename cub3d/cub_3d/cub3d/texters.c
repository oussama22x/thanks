#include "file.h"


void fill_the_rest_of_the_map(t_all **all)
{
    int i;
    int x;
    i = 0;
    x = 0;
   get_longest_line(*all);
    while(i < (*all)->y_of_map)
    {
        x = 0;
        while (x < (*all)->longest_line)
        {
            if((*all)->map[i][x] == 32 || (*all)->map[i][x] == 0)
                (*all)->map[i][x] = '1';
            x++;
        }
        i++;
    }
}
void fix_map(t_all **all, int len)
{
    char **new_map;
    int i;
    int x;
    i = 0;
    x = 0; 
    
    new_map =  calloc(sizeof(char *) ,  (*all)->y_of_map + 2);
    while(i <  (*all)->y_of_map)
    {
        new_map[i] = calloc(sizeof(char) , len + 2);
        i++;
    }
    i = 0;
    while(i < (*all)->y_of_map)
    {
        x  = 0;
        while((*all)->map[i][x])
        {
            new_map[i][x] = (*all)->map[i][x];
            x++;
        }
       new_map[i][x] = '\0';
        i++;
    }
    new_map[i] = NULL;
     (*all)->map = new_map;
    if(check_if_close((*all)->map) != -1 && check_for_valid_map((*all)->map) != -1)
    {
       fill_the_rest_of_the_map(all);
    }
    else 
       exit(1);
}

int check_for_valid_map(char **map)
{
    int i;
    int x;
    i = 0;
    x = 0;
    
    while(map[i])
    {
        x = 0;
        while (map[i][x])
        {
            if(map[i][x] == '0')
            {
                if(i > 0 && (map[i - 1][x] == '\0' || map[i + 1][x] == '\0' || map[i - 1][x] == ' ' || map[i + 1][x] == ' '))
                {
                    printf("unvalid ;)\n");
                    return(-1);
                }
                if(x > 0 && (map[i][x - 1] == '\0' ||map[i][x + 1] == '\0' || map[i][x - 1] == ' ' ||map[i][x + 1] == ' '))
                {
                    printf("unvalid :)\n");
                    return(-1);
                }
            }
            x++;
        }
        i++;
    }
    if(ft_strchr(map[i - 1], '0'))
    {
        printf("unvalid ;)\n");
        return -1;
    }
    return(0);
}

int ft_atoi_num(t_textr *txt)
{
   if(helper(txt->F, txt->color_f[1]) == -1 || helper(txt->C, txt->color_c[1]) == -1)
        return (-1);
    return 0;
}

unsigned int RGBtoUint8(int R, int G, int B) 
{
    return ((0xFF << 24) | (R << 16) | (G << 8) | B);
}

void get_colers(t_textr *txtr)
{
    txtr->C_CLOR = RGBtoUint8(txtr->C[0], txtr->C[1], txtr->C[2]);
    txtr->F_CLOR = RGBtoUint8(txtr->F[0], txtr->F[1], txtr->F[2]);
}
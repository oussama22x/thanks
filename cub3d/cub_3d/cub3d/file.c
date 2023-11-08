#include <stdio.h>
#include "file.h"

void get_map(t_all **all, int fd)
{
    char *line;
    char *tmp;

    tmp = NULL;
    line = NULL;
    tmp = get_next_line(fd);
    ft_lst_add_back(&(*all)->garb, ft_lst_new(tmp));
    if(!tmp)
        exit(4);
    while(tmp)
    {
        tmp = ft_strjoin(line, tmp);
        ft_lst_add_back(&(*all)->garb, ft_lst_new(tmp));
        line = ft_strdup(tmp);
        ft_lst_add_back(&(*all)->garb, ft_lst_new(line));
        tmp = get_next_line(fd);
        ft_lst_add_back(&(*all)->garb, ft_lst_new(tmp));
    }
    (*all)->map = ft_split(line, '\n');
    ft_lst_add_back(&(*all)->garb, ft_lst_new((*all)->map));
}
void init_befor_init_hh(t_textr **txtr)
{
    (*txtr)->color_c = NULL;
    (*txtr)->color_f = NULL;
    (*txtr)->EA = NULL;
    (*txtr)->NO = NULL;
    (*txtr)->SO = NULL;
    (*txtr)->WE = NULL;
    (*txtr)->C = calloc(sizeof(int) , 3);
    (*txtr)->F = calloc(sizeof(int) , 3);
}
int start_reading_map(char *line)
{
    if(!ft_strnstr(line, "NO", ft_strlen(line)) && !ft_strnstr(line, "SO", ft_strlen(line)) &&\
    !ft_strnstr(line, "WE", ft_strlen(line)) && !ft_strnstr(line, "EA", ft_strlen(line)) &&\
    !ft_strnstr(line, "F", ft_strlen(line)) && !ft_strnstr(line, "C", ft_strlen(line)))
        return (-1);
    return(0);
}








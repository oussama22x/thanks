#include "cub3d.h"
t_garbage *ft_lst_new(void *ptr)
{
    t_garbage *new;
    if(!ptr)
        return(NULL);
    new = malloc(sizeof(t_garbage));
    new->ptr = ptr;
    new->next = NULL;
    return(new);
}
void ft_lst_add_back(t_garbage **head, t_garbage *new)
{
    t_garbage *tmp;

    if(!(*head))
    {
        *head = new;
        return ;
    }
    tmp = *head;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}
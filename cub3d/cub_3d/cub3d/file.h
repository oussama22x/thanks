#ifndef FILE_H
# define FILE_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include "get_line/get_next_line.h"
#include <mlx.h>
typedef struct s_garbage
{
    void *ptr;
    struct s_garbage *next;
}               t_garbage;
t_garbage *ft_lst_new(void *ptr);
void ft_lst_add_back(t_garbage **head, t_garbage *new);
typedef struct s_textr
{
    char **NO;
    char **SO;
    char **WE;
    char **EA;
    char **S;
    char **color_f;
    char **color_c;
    unsigned int *F;
    unsigned int *C;
    unsigned int C_CLOR;
    unsigned int F_CLOR;
} t_textr;

typedef struct s_all
{
    char **map;
    void *img;
    char *addrs;
    void *mlx;
    void *win;
    int bits_per_pixel;
    int size_line;
    int endian;
    int player_angel;
    int fd;
    int y;
    int x;
    int x_of_map;
    int y_of_map;
    int longest_line;
    t_textr *txt;
    t_garbage *garb;
} t_all;
void get_map(t_all **all, int fd);
int check_errors(char **map);
void init_txters(t_textr **txtr, t_all *all);
int all_in_one(t_all **all, t_textr **txtr,  char **argv, t_garbage **garb);
void init_all(t_all **all);
void count_x_y_of_the_map(t_all **all);
int updatemap(t_all *all);
void fix_map(t_all **all, int len);
int check_if_close(char **map);
int check_for_valid_map(char **map);
int check_extionts(char *argv);
int count_pinter(char **ptr);
int count(char **str);
int check_final(t_textr *txtr);
int helper(unsigned int *arr, char *str);
int ft_atoi_num(t_textr *txt);
unsigned int RGBtoUint8(int R, int G, int B);
void get_colers(t_textr *txtr);
void init_befor_init_hh(t_textr **txtr);
int start_reading_map(char *line);
void init_txters(t_textr **txtr, t_all *all);
int check_errors(char **map);
void get_x_y_of_the_player(t_all **all);
void  get_longest_line(t_all *all);
#endif
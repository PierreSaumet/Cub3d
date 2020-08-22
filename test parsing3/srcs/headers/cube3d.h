#ifndef CUB3D_H
# define CUB3D_H

// Libriries used
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# include "get_next_line.h"
# include "libft.h"

// Structure for datas
typedef struct      s_data
{
    int             param_h;            //lignes necessaire pour valider nb_data
    int             map_h;      // lignes de la map
    int             map_w;
    int             character;    //verifie si le carac est la
    int             nb_data;            // valeur 8 = les parametres
    int             tt_line;        // 1gnl, compte toute les lignes
    int             nb_empty; //empty line pour trouver nb_data
    int             tt_empty;   //total des lignes vides
    int             rx;
    int             ry;
    char            *pt_no;
    char            *pt_so;
    char            *pt_we;
    char            *pt_ea;
    char            *pt_sp;
    int             fr;
    int             fg;
    int             fb;
    int             cr;
    int             cg;
    int             cb;
    char            **map;
    char            *index;     
}                   t_data;

//      structure pour la resolution
typedef struct      s_map
{
    int             x_c;
    int             y_c;
    int             x_ob;
    int             y_ob;
    char            **map2;
}                   t_map;


// Functions used

void                quit(char *error_msg);
void                check_arg(char *argv);

// PARSING DATA
//  init_params.c
void                init_params(t_data *data);
void                init_map(t_map *map);
// change_space.c
void                change_sp_map(t_data *data);
// parsing_params.c
void                parsing_param(char *argv, t_data *data);
// parsing_map.c
void                check_index_map(t_data *data);
void                get_map(char *argv, t_data *data);


void                ft_check_map(t_data *data);

//  GET PARAMS
// ceiling.c
void                get_ceilling(t_data *data, char *line);
void                get_floor(t_data *data, char *line);

// texture.c
void                get_str(t_data *data, char *line, char c, char *pt);

// resolution .c
void                get_r(t_data *data, char *line);




//  ALGORITHM
//  obecjt-charact  ft_resolve.c et ft_object_back.c
void                find_object(t_map *map, t_data *data);
void                cpy_tab(t_map *map, t_data *data);
// resoleve
void                ft_resolve(t_map *map, t_data *data);



// OTHER FONCTIONS
// free_struct.c
void                ft_free_map(t_map *map, t_data *data);
void                ft_free_struct(t_data *data);

//  display.c
void                ft_display_params(t_data *data);
void                ft_display_map(t_data *data);
void                printf_tab(t_map *map, t_data *data);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*
**   Structure for the parsing
*/
typedef struct		s_data
{
	int				param_h;
	int				map_h;
	int				map_w;
	int				character;
	int				nb_data;
	int				tt_line;
	int				nb_empty;
	int				tt_empty;
	int				rx;
	int				ry;
	char			*pt_no;
	char			*pt_so;
	char			*pt_we;
	char			*pt_ea;
	char			*pt_sp;
	int				fr;
	int				fg;
	int				fb;
	int				cr;
	int				cg;
	int				cb;
	char			**map;
	char			*index;
	int				c_x;
	int				c_y;
	char			charac;
}					t_data;

/*
**  Structure for the resolution
*/
typedef struct		s_map
{
	int				x_c;
	int				y_c;
	int				x_ob;
	int				y_ob;
	char			**map2;
}					t_map;

/*
**  quit_game.c
*/
void				quit(char *error_msg);
void				ft_puterror(char *str);
int					ft_puterror2(char *str);
int					ft_check_empty(char **argv);

/*
**	check_arg.c
*/
void				check_arg(char *argv);

/*
**  init_params.c
*/
void				init_params(t_data *data);
void				init_map(t_map *map);

/*
**  change_space.c
*/
void				change_sp_map(t_data *data);
int					change_sp(t_data *data, int i, int j);

/*
**  parsing_params.c
*/
void				parsing_param(char *argv, t_data *data);
int					check_line(t_data *data, char *line);
void				count_map(t_data *data, char *line);

/*
**	end_parsing.c
*/
int					ft_get_data_end(void);
int					ft_ret_gnl_pars_param(int fd, int ret,
						t_data *data);
int					ft_final_check_c_f(t_data *d, int ret);

/*
** parsing_map.c
*/
void				get_map(char *argv, t_data *data);
void				check_index_map(t_data *data);

/*
** ceiling.c
*/
int					get_ceilling(t_data *data, char *line);
int					get_floor(t_data *data, char *line);

/*
** texture.c
*/
int					get_str(t_data *data, char *line, char c, char *pt);

/*
** resolution .c
*/
int					get_r(t_data *data, char *line);

/*
**  ft_object_back.c
*/
int					find_object(t_map *map, t_data *data);

/*
** resolve
*/
void				ft_resolve(t_map *map, t_data *data);
void				cpy_tab(t_map *map, t_data *data);

/*
** free_struct.c
*/
void				ft_free_map(t_map *map, t_data *data);
void				ft_free_struct(t_data *data);
void				ft_free_ptr(t_data *data);
void				ft_error_map(t_data *data, char *str);
/*
**  ft_check_map.c
*/
void				ft_check_map(t_data *data);
#endif

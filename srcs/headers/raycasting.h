/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "parsing.h"

/*
**  Global variables used for the raycasting
*/
# define MOVESPEED 0.010
# define ROTSPEED 0.005
# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4

/*
**  Structure for the textures
*/
typedef struct			s_texture
{
	void				*id;
	void				*addr;
	int					*img;
	int					h;
	int					w;
}						t_texture;

/*
**  Structure for the mlx graphic
*/
typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	void				*img_data;
	int					*img_i_data;
	int					size_l;
	int					bpp;
	int					endian;
	void				*img_ptr2;
	void				*img_data2;
	int					size_l2;
	int					bpp2;
	int					endian2;
}						t_mlx;

/*
**  Structure for the movements
*/
typedef struct			s_mvt
{
	int					forward;
	int					backward;
	int					left;
	int					right;
	int					cam_l;
	int					cam_r;
}						t_mvt;

/*
**  Structure for the DDA
*/
typedef struct			s_dda
{
	double				camerax;
	double				raydirx;
	double				raydiry;
	int					mapx;
	int					mapy;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				perpwalldist;
	int					lineheight;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	int					drawstart;
	int					drawend;
	double				wallx;
}						t_dda;

/*
**  Structure for the sprites's location
*/
typedef struct			s_sprite
{
	double				sp_x;
	double				sp_y;
	double				sp_dist;
}						t_sprite;

/*
**  Structure of the sprite's informations
*/
typedef struct			s_sp_params
{
	int					invdet;
	double				transformx;
	double				transformy;
	int					screenx;
	int					sp_h;
	int					drawstarty;
	int					drawendy;
	int					sp_w;
	int					drawstartx;
	int					drawendx;
	int					texx;
}						t_sp_params;

/*
**  Global structure used for all the raycasting algorithm
*/
typedef struct			s_parsing
{
	int					screenh;
	int					screenw;
	int					maph;
	int					mapw;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	int					ceiling;
	int					floor;
	int					refresh;
	char				**map;
	int					nsp;
	t_sprite			*ssp;
	t_mlx				mlx_val;
	t_mvt				mvt;
	t_dda				dda;
	t_texture			n_texture;
	t_texture			s_texture;
	t_texture			w_texture;
	t_texture			e_texture;
	t_texture			sp_texture;
}						t_parsing;

/*
**  ft_raycasting_algo.c
*/
int						ft_raycasting(t_parsing pars_val);

/*
** ft_init_mlx.c
*/
void					ft_init_structure(t_parsing *p_st);

/*
**  ft_init_parsingstruct.c
*/
void					ft_init_parsing(t_parsing *parsing_val);
void					ft_init_mvt(t_parsing *parsing_val);
void					ft_init_dda(t_dda *dda_val);

/*
** mvt_algo.c
*/
void					ft_event(t_parsing *p_val);

/*
**  mvt_charac.c
*/
void					ft_forward(t_parsing *p_val);
void					ft_backward(t_parsing *p_val);
void					ft_right(t_parsing *p_val);
void					ft_left(t_parsing *p_val);

/*
**  mvt_cam.c
*/
void					ft_cam_r(t_parsing *p_val);
void					ft_cam_l(t_parsing *p_val);
int						ft_key_release(int keycode, t_parsing *p_val);
int						ft_key_push(int keycode, t_parsing *p_val);

/*
**  ft_texture.c
*/
void					ft_init_texture(t_parsing *pars_val, t_data *data);

/*
**  ft_sprite.c
*/
void					ft_init_sprite(t_parsing *p_val);
int						ft_get_texy(t_parsing *p_val, t_sp_params *sp, int j);
int						ft_get_texx(t_sp_params *sp_p, int w);

/*
**  ft sprites.c
*/
void					ft_draw_sprite(t_parsing *p_val, double *z_buff);

/*
**  ft_put_pix.c
*/
void					ft_my_mlx_pixel_put(t_parsing *p_val, int x,
							int y, int color);

/*
**  ft_dda.c
*/
void					ft_init_raycast(t_parsing *pars_val, int x);
void					ft_calc_stepx_y(t_parsing *pars_val);
void					ft_dda(t_parsing *pars_val);
void					ft_calc_perp_draw(t_parsing *pars_val, double *z_buff);
void					ft_put_txt_buff(t_parsing *p_val, int x);

/*
**  ft_draw.c
*/
t_texture				ft_choose_texture(int i, t_parsing *p_val);
void					ft_draw_ceiling(t_parsing *p_val, int *i, int x);
void					ft_draw_floor(t_parsing *p_val, int *i, int x);
void					ft_draw_wall(t_parsing *p_val, t_texture text,
							int x, int *i);

/*
**  ft_bmp.c
*/
void					ft_write_bmp(t_parsing *p_val, int fd);

/*
**  ft_free_structure.c
*/
void					ft_free_map_raycasting(t_parsing *p_val);
void					ft_destroy_texture(t_parsing *p_val);
void					ft_free_mlx_ptr(void *mlx_ptr);
void					ft_free_sprite(t_parsing *p_val);

/*
**	ft_copy_parsing_raycasting.c
*/
void					ft_cpy_structure(t_data *data, t_parsing *p_val);
void					ft_cpy_map(t_data *data, t_parsing *p_val);
#endif

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
typedef struct          texture_s
{
    void                *id;
    void                *addr;
    int                *img;    
    int                 h;
    int                 w;
}                       texture_t;

/*
**  Structure for the mlx graphic
*/
typedef struct          mlx_s
{
    void                *mlx_ptr;
    void                *win_ptr;
    void                *img_ptr;
    void                *img_data;
    int                 *img_i_data;
    int                 size_l;
    int                 bpp;
    int                 endian;
    void                *img_ptr2;
    void                *img_data2;
    int                 size_l2;
    int                 bpp2;
    int                 endian2;
}                       mlx_t;

/*
**  Structure for the movements
*/
typedef struct          mvt_s
{
  int                   forward;
  int                   backward;
  int                   left;
  int                   right;
  int                   cam_l;
  int                   cam_r;
}                       mvt_t;

/*
**  Structure for the DDA
*/
typedef struct          dda_s
{
    double              cameraX;
    double              rayDirX;
    double              rayDirY;
    int                 mapX;
    int                 mapY;
    double              sideDistX;
    double              sideDistY;
    double              deltaDistX;
    double              deltaDistY;
    double              perpWallDist;
    int                 lineHeight;
    int                 stepX;
    int                 stepY;
    int                 hit;
    int                 side;
    int                 drawstart;
    int                 drawend;
    double              wallx;
}                       dda_t;

/*
**  Structure for the sprites's location
*/
typedef struct          sprite_s
{
    double              sp_x;
    double              sp_y;
    double              sp_dist;
}                       sprite_t;

/*
**  Structure of the sprite's informations
*/
typedef struct          sp_params_s
{
    int                 invdet;
    double              transformx;
    double              transformy;
    int                 screenx;
    int                 sp_h;
    int                 drawstarty;
    int                 drawendy;
    int                 sp_w;
    int                 drawstartx;
    int                 drawendx;
    int                 texx;
}                       sp_params_t;

/*
**  Global structure used for all the raycasting algorithm
*/
typedef struct          parsing_s      
{
    int                 screenH;
    int                 screenW;
    int                 mapH;
    int                 mapW;
    double              posX;
    double              posY;
    double              dirX;
    double              dirY;
    double              planeX;
    double              planeY;
    int                 ceiling;
    int                 floor;
    int                 refresh;
    char                **map;
    int                 nsp;
    sprite_t            *ssp;
    mlx_t               mlx_val;
    mvt_t               mvt;
    dda_t               dda;
    texture_t           n_texture;
    texture_t           s_texture;
    texture_t           w_texture;
    texture_t           e_texture;
    texture_t           sp_texture;
}                       parsing_t;


/*
**  ft_raycasting_algo.c
*/
int                     ft_raycasting(parsing_t pars_val);


/*
** ft_init_mlx.c
*/
void                    ft_init_structure(parsing_t *p_st);

/*
**  ft_init_parsingstruct.c
*/
void                    ft_init_parsing(parsing_t *parsing_val);
void                    ft_init_mvt(parsing_t *parsing_val);
void                    ft_init_dda(dda_t *dda_val);

/*
** mvt_algo.c
*/
void                    ft_event(parsing_t *p_val);


/*
**  mvt_charac.c
*/
void                    ft_forward(parsing_t *p_val);
void                    ft_backward(parsing_t *p_val);
void                    ft_right(parsing_t *p_val);
void                    ft_left(parsing_t *p_val);

/*
**  mvt_cam.c
*/
void                    ft_cam_r(parsing_t *p_val);
void                    ft_cam_l(parsing_t *p_val);
int                     ft_key_release(int keycode, parsing_t *p_val);
int                     ft_key_push(int keycode, parsing_t *p_val);

/*
**  ft_texture.c
*/
void                    ft_init_texture(parsing_t *pars_val, t_data *data);


/*
**  ft_sprite.c
*/
void                    ft_init_sprite(parsing_t *p_val);
int                     ft_get_texy(parsing_t *p_val, sp_params_t *sp, int j);
int                     ft_get_texx(sp_params_t *sp_p, int w);

/*
**  ft sprites.c
*/
void                    ft_draw_sprite(parsing_t *p_val, double *z_buff);

/*
**  ft_put_pix.c
*/
void	                ft_my_mlx_pixel_put(parsing_t *p_val, int x, int y, int color);


/*
**  ft_dda.c
*/
void                    ft_init_raycast(parsing_t *pars_val, int x);
void                    ft_calc_stepx_y(parsing_t *pars_val);
void                    ft_dda(parsing_t *pars_val);
void                    ft_calc_perp_draw(parsing_t *pars_val, double *z_buff);
void                    ft_put_txt_buff(parsing_t *p_val, int x);


/*
**  ft_draw.c
*/
texture_t               ft_choose_texture(int i, parsing_t *p_val);
void                    ft_draw_ceiling(parsing_t *p_val, int *i, int x);
void                    ft_draw_floor(parsing_t *p_val, int *i, int x);
void                    ft_draw_wall(parsing_t *p_val, texture_t text, int x, int *i);



/*
**  ft_bmp.c
*/
void                    ft_write_bmp(parsing_t *p_val, int fd);

/*
**  ft_free_structure.c
*/
void                    ft_free_map_raycasting(parsing_t *p_val);
void                    ft_destroy_texture(parsing_t *p_val);
void	                ft_free_mlx_ptr(void *mlx_ptr);
void                    ft_free_sprite(parsing_t *p_val);


// FT_COPY_PARSING_RAYCASTING
void            ft_cpy_structure(t_data *data, parsing_t *p_val);
void            ft_cpy_map(t_data *data, parsing_t *p_val);
#endif

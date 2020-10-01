/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
**  This file contains 3 functions:
**  - 'ft_init_texture(parsing_t *pars_val, t_data *data)': main loop for
**  initializing the textures.
**  - 'ft_init_t(parsing_t *p_val)':    put all the variables to zero or NULL.
**  - 'ft_set_txt(parsing_t *p_val, texture_t *t, char *src)':  load the
**  texture's pointer.
*/

static void            ft_set_txt(parsing_t *p_val, texture_t *t, char *src)
{
    int         i[3];
    
    if (t->id)
    {
        printf("texture deja Ok -%s-\n", src);
        exit(EXIT_FAILURE);
    }
    t->id = mlx_xpm_file_to_image(p_val->mlx_val.mlx_ptr, src, &(t->w), &(t->h));
    if (t->id == NULL)
    {
        printf("erreur ne peut pas ouvrir la texture\n");
    }
    t->img = (int *)mlx_get_data_addr(t->id, &i[0], &i[1], &i[2]);
}

static void            ft_init_t(parsing_t *p_val)
{
    p_val->n_texture.img = NULL;
    p_val->n_texture.id = NULL;
    p_val->n_texture.h = 0;
    p_val->n_texture.w = 0;
    p_val->s_texture.img = NULL;
    p_val->s_texture.id = NULL;
    p_val->s_texture.h = 0;
    p_val->s_texture.w = 0;
    p_val->w_texture.img = NULL;
    p_val->w_texture.id = NULL;
    p_val->w_texture.h = 0;
    p_val->w_texture.w = 0;
    p_val->e_texture.img = NULL;
    p_val->e_texture.id = NULL;
    p_val->e_texture.h = 0;
    p_val->e_texture.w = 0;
    p_val->sp_texture.img = NULL;
    p_val->sp_texture.id = NULL;
    p_val->sp_texture.h = 0;
    p_val->sp_texture.w = 0;
}

void            ft_init_texture(parsing_t *pars_val, t_data *data)
{
    ft_init_t(pars_val);
    ft_set_txt(pars_val, &(pars_val->n_texture), data->pt_no);
    free(data->pt_no);
    ft_set_txt(pars_val, &(pars_val->s_texture), data->pt_so);
    free(data->pt_so);
    ft_set_txt(pars_val, &(pars_val->w_texture), data->pt_we);
    free(data->pt_we);
    ft_set_txt(pars_val, &(pars_val->e_texture), data->pt_ea);
    free(data->pt_ea);
    ft_set_txt(pars_val, &(pars_val->sp_texture), data->pt_sp);
    free(data->pt_sp);
}
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
**  - 'ft_init_texture(t_parsing *pars_val, t_data *data)': main loop for
**  initializing the textures.
**  - 'ft_init_t(t_parsing *p_val)':    put all the variables to zero or NULL.
**  - 'ft_set_txt(t_parsing *p_val, t_texture *t, char *src)':  load the
**  texture's pointer.
*/

static void		ft_err_txt(t_parsing *pars_val, t_data *data)
{
	if (pars_val->mlx_val.img_ptr != NULL)
		mlx_destroy_image(pars_val->mlx_val.mlx_ptr, pars_val->mlx_val.img_ptr);
	if (pars_val->mlx_val.img_ptr2 != NULL)
		mlx_destroy_image(pars_val->mlx_val.mlx_ptr, pars_val->mlx_val.img_ptr2);
	mlx_clear_window(pars_val->mlx_val.mlx_ptr, pars_val->mlx_val.win_ptr);
	mlx_destroy_window(pars_val->mlx_val.mlx_ptr, pars_val->mlx_val.win_ptr);
	ft_free_mlx_ptr(pars_val->mlx_val.mlx_ptr);
	//printf("LA\n");
	free(data->pt_no);
	free(data->pt_so);
	free(data->pt_we);
	free(data->pt_ea);
	free(data->pt_sp);
	int i = 0;
	while (i < data->map_h + 1)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	exit(EXIT_FAILURE);
}

int				ft_check_empty2(char *argv)
{
	int			fd;
	int			ret;
	char		*buf;
	int			count;

	fd = open(argv, O_RDONLY);
	buf = NULL;
	ret = 0;
	count = 0;
	while ((ret = get_next_line(fd, &buf)) >= 1)
	{
		free(buf);
		count++;
	}
	free(buf);
	buf = NULL;
	if (count == 0)
		return (ft_puterror2("The texture file is empty\n"));
	return (0);
}

static int		ft_set_txt(t_parsing *p_val, t_texture *t, char *src)
{
	int			i[3];

	//ft_check_empty2(src);
	if (t->id)
	{
		ft_puterror("texture deja Ok -%s-\n");
		return (1);
	}
	t->id = mlx_xpm_file_to_image(p_val->mlx_val.mlx_ptr,
			src, &(t->w), &(t->h));
	if (t->id == NULL)
	{
		ft_puterror("2) erreur ne peut pas ouvrir la texture\n");
		return (1);
	}
	t->img = (int *)mlx_get_data_addr(t->id, &i[0], &i[1], &i[2]);
	return (0);
}

static void		ft_init_t(t_parsing *p_val)
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

void			ft_check_txt_empty(t_parsing *p, t_data *d)
{
	if (ft_check_empty2(d->pt_no) == 1)
		ft_err_txt(p, d);
	if (ft_check_empty2(d->pt_so) == 1)
		ft_err_txt(p, d);
	if (ft_check_empty2(d->pt_ea) == 1)
		ft_err_txt(p, d);
	if (ft_check_empty2(d->pt_we) == 1)
		ft_err_txt(p, d);
	if (ft_check_empty2(d->pt_sp) == 1)
		ft_err_txt(p, d);
}


void			ft_init_texture(t_parsing *pars_val, t_data *data)
{
	ft_init_t(pars_val);
	ft_check_txt_empty(pars_val, data);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
** This file contains 4 functions mainly used for saving the bmp file.
**	- 'ft_bmp_exit(t_parsing p_val)':	allows the program to exit correctly.
**  - ' ft_write_bmp(t_parsing *p_val, int fd)':    the main function, uses
**  the two others and write into the file descriptor.
**  - 'ft_bmp_header(t_parsing *p_val,
**       t_bmp_file *bfh, bmp_image_t *bih, unsigned short *bmp_type)':
**  creates the header for the bmp file.
**  - 'ft_bmp_draw(t_parsing *p_val, bmp_image_t *bih, int fd, char *img)':
**  find the color of the pixel and write it in the file descriptor.
*/

void					ft_bmp_exit(t_parsing p_val)
{
	if (p_val.mlx_val.img_ptr != NULL)
		mlx_destroy_image(p_val.mlx_val.mlx_ptr, p_val.mlx_val.img_ptr);
	if (p_val.mlx_val.img_ptr2 != NULL)
		mlx_destroy_image(p_val.mlx_val.mlx_ptr, p_val.mlx_val.img_ptr2);
	mlx_clear_window(p_val.mlx_val.mlx_ptr, p_val.mlx_val.win_ptr);
	mlx_destroy_window(p_val.mlx_val.mlx_ptr, p_val.mlx_val.win_ptr);
	ft_free_mlx_ptr(p_val.mlx_val.mlx_ptr);
}

static void				ft_bmp_header(t_parsing *p_val,
		t_bmp_file *bfh, t_bmp_image *bih, unsigned short *bmp_type)
{
	*bmp_type = 0x4d42;
	bfh->reserved1 = 0;
	bfh->reserved2 = 0;
	bfh->file_size = 2 + sizeof(t_bmp_file) + sizeof(t_bmp_image) +
		p_val->screenw * p_val->screenh * 4;
	bfh->offset_bits = 0x36;
	bih->size_header = sizeof(t_bmp_image);
	bih->width = p_val->screenw;
	bih->height = p_val->screenh;
	bih->planes = 1;
	bih->bpp = 32;
	bih->compression = 0;
	bih->image_size = 0;
	bih->ppm_x = 5000;
	bih->ppm_y = 5000;
	bih->color_usr = 0;
	bih->color_important = 0;
}

static void				ft_bmp_draw(t_parsing *p_val,
		t_bmp_image *bih, int fd, char *img)
{
	int					i;
	int					y;
	int					color;

	i = bih->height - 1;
	y = 0;
	color = 0;
	while (i >= 0)
	{
		y = 0;
		while (y < bih->width)
		{
			color = p_val->mlx_val.img_i_data[bih->width * i + y];
			write(fd, &color, 4);
			y++;
		}
		i--;
	}
}

void					ft_write_bmp(t_parsing *p_val, int fd)
{
	t_bmp_file			bfh;
	t_bmp_image			bih;
	unsigned short		bmp_type;

	ft_bmp_header(p_val, &bfh, &bih, &bmp_type);
	write(fd, &bmp_type, sizeof(bmp_type));
	write(fd, &bfh, sizeof(bfh));
	write(fd, &bih, sizeof(bih));
	ft_bmp_draw(p_val, &bih, fd, p_val->mlx_val.img_data);
}

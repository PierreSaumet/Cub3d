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
** This file contains 3 functions mainly used for saving the bmp file.
**  - ' ft_write_bmp(parsing_t *p_val, int fd)':    the main function, uses
**  the two others and write into the file descriptor.
**  - 'ft_bmp_header(parsing_t *p_val,
**       bmp_file_t *bfh, bmp_image_t *bih, unsigned short *bmp_type)':
**  creates the header for the bmp file.
**  - 'ft_bmp_draw(parsing_t *p_val, bmp_image_t *bih, int fd, char *img)':
**  find the color of the pixel and write it in the file descriptor.
*/

static void				ft_bmp_header(parsing_t *p_val,
		bmp_file_t *bfh, bmp_image_t *bih, unsigned short *bmp_type)
{
	*bmp_type = 0x4d42;
	bfh->reserved1 = 0;
	bfh->reserved2 = 0;
	bfh->file_size = 2 + sizeof(bmp_file_t) + sizeof(bmp_image_t) +
		p_val->screenW * p_val->screenH * 4;
	bfh->offset_bits = 0x36;
	bih->size_header = sizeof(bmp_image_t);
	bih->width = p_val->screenW;
	bih->height = p_val->screenH;
	bih->planes = 1;
	bih->bpp = 32;
	bih->compression = 0;
	bih->image_size = 0;
	bih->ppm_x = 5000;
	bih->ppm_y = 5000;
	bih->color_usr = 0;
	bih->color_important = 0;
}

static void				ft_bmp_draw(parsing_t *p_val,
		bmp_image_t *bih, int fd, char *img)
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

void					ft_write_bmp(parsing_t *p_val, int fd)
{
	bmp_file_t			bfh;
	bmp_image_t			bih;
	unsigned short		bmp_type;

	ft_bmp_header(p_val, &bfh, &bih, &bmp_type);
	write(fd, &bmp_type, sizeof(bmp_type));
	write(fd, &bfh, sizeof(bfh));
	write(fd, &bih, sizeof(bih));
	ft_bmp_draw(p_val, &bih, fd, p_val->mlx_val.img_data);
}

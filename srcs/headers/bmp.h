/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

/*
**  Structure for BMP header file.
*/

typedef struct              bmp_file_s
{
    unsigned int            file_size;      
    unsigned short          reserved1;      
    unsigned short          reserved2;      
    unsigned int            offset_bits;    
}                           bmp_file_t;

/*
**  Structure for BMP information file.
*/

typedef struct              bmp_image_s
{
    unsigned int            size_header;    
    int                     width;          
    int                     height;         
    unsigned short          planes;         
    unsigned short          bpp;      
    unsigned int            compression;    
    unsigned int            image_size;     
    int                     ppm_x;          
    int                     ppm_y;          
    unsigned int            color_usr;       
    unsigned int            color_important;    
}                           bmp_image_t;

#endif
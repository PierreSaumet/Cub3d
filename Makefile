# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             #
#   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME	=	cub3D

##################################### PATH ###################################

#------------RAYCASTING-----------#
INIT	= srcs/initialize/
MVT		= srcs/movements/
DRAW	= srcs/draw_mlx/
RAY		= srcs/raycasting/

#-------------PARSING-------------#
PARSING	= srcs/parsing/
RESOLVE	= srcs/resolve/

#--------------LIBFT--------------#
LIBFT	= librairies/libft/

#---------------GNL---------------#
GNL		= librairies/gnl/

#-------------HEADERS-------------#
HDS		= srcs/headers/

################################### SOURCES ##################################

#---------------MAIN--------------#
SRCS	=	main.c

#------------RAYCASTING-----------#
SRCS	+=	$(INIT)ft_init_mlx.c							\
			$(INIT)ft_init_parsingstruct.c					\
			$(INIT)ft_copy_parsing_raycasting.c				\
			$(MVT)mvt_algo.c								\
			$(MVT)mvt_charac.c								\
			$(MVT)mvt_cam.c									\
			$(DRAW)ft_put_pix.c								\
			$(DRAW)ft_draw.c								\
			$(RAY)ft_texture.c								\
			$(RAY)ft_sprite.c								\
			$(RAY)ft_sprites.c								\
			$(RAY)ft_raycasting_algo.c						\
			$(RAY)ft_dda.c									\
			srcs/bmp/ft_bmp.c								\
			srcs/free/ft_free_structure.c

#-------------PARSING-------------#
SRCS	+=	$(PARSING)check_arg.c							\
			$(PARSING)init_params.c							\
			$(PARSING)get_map/change_space.c				\
			$(PARSING)get_map/ft_check_map.c				\
			$(PARSING)get_map/parsing_map.c					\
			$(PARSING)get_params/ceiling.c					\
			$(PARSING)get_params/parsing_params.c			\
			$(PARSING)get_params/end_parsing.c				\
			$(PARSING)get_params/resolution.c				\
			$(PARSING)get_params/texture.c					\
			$(PARSING)other_fcts/free_struct.c				\
			$(RESOLVE)quit_game.c							\
			$(RESOLVE)ft_resolve.c							\
			$(RESOLVE)ft_object_back.c						\
			$(PARSING)get_map/ft_end.c

#--------------LIBFT--------------#
SRCS	+=	$(LIBFT)ft_atoi.c								\
			$(LIBFT)ft_isalnum.c							\
			$(LIBFT)ft_isalpha.c							\
			$(LIBFT)ft_isdigit.c							\
			$(LIBFT)ft_isspace.c							\
			$(LIBFT)ft_strchrsp.c							\
			$(LIBFT)ft_strcpy.c

#---------------GNL---------------#
SRCS	+=	$(GNL)get_next_line_utils.c						\
			$(GNL)get_next_line.c


################################### HEADERS ##################################

HEADER	+=	$(HDS)cub3d.h									\
			$(HDS)raycasting.h								\
			$(HDS)parsing.h									\
			$(HDS)bmp.h										\
			$(HDS)get_next_line.h							\
			$(HDS)libft.h									\
			$(HDS)linux_key.h

################################# VARIABLES ##################################

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
OBJS	=	$(SRCS:.c=.o)
MLX		=	minilibx-linux/libmlx.a
INC		=	srcs/headers/
################################### RULES ####################################

all: compmlx $(NAME)

$(OBJS): %.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -I $(INC) -c $< -o $@ -g

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -lm -lXext -lX11 -o $@

compmlx:
	$(MAKE) -C minilibx-linux all

#--------------CLEAN--------------#

cleangnl:
	rm -rf $(GNL)*.o

cleanlibft:
	rm -rf $(LIBFT)*.o

cleanlibraries:
	rm -rf $(GNL)*.o && rm -rf $(LIBFT)*.o


cleanmlx:
	$(MAKE) -C minilibx-linux clean

cleanpgm:
	rm -rf srcs/*/*.o && rm -rf srcs/parsing/*/*.o && rm -rf main.o

clean:	cleanlibraries cleanmlx cleanpgm

fclean:	clean
		rm -rf $(NAME)

#---------------RE---------------#
re: fclean all

.PHONY:	all clean fclean re
.SILENT:
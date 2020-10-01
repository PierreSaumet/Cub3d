/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_final_check(char **s, char **line, int ret, int fd);
int		ft_gnl(char **s, char **line);
int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
int		ft_check_ret(char **line, int ret);

char	*ft_strchr(char *s);
char	*ft_strdup(char *s1);
char	*ft_substr(char *src, int s, int len);
char	*ft_strjoin(char *s1, char *s2);

void	ft_free(char **str);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 09:15:15 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/04/29 16:45:30 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
ssize_t ft_write(int fd, const void *buf, size_t nbyte);
char    *ft_strcpy(char *dest, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_read(int fd, void *buf, size_t count);
char    *ft_strdup(const char *s);

#endif
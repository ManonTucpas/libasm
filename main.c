/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:19:00 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/04/29 19:15:11 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int		ft_strcmp_c(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static void check_strlen(char *s)
{
	int res1;
	int res2;

	res1 = ft_strlen(s);
	res2 = strlen(s);
	printf("----------FT_STRLEN----------\n\n");
	printf("My   output: %d\n", res1);
	printf("Real output: %d\n", res2);
	if (res1 == res2)
		printf("OK\n");
	else 
		printf("FALSE\n");
	printf("-----------------------------\n");
}

static int check_strcpy(char *s)
{
	char *dest;
	
	if (!(dest = malloc(sizeof(char) * strlen(s) + 1)))
		return (-1);
	printf("----------FT_STRCPY----------\n\n");
	printf("My   output: %s\n", ft_strcpy(dest, s));
	printf("Real output: %s\n", strcpy(dest, s));
	if (ft_strcpy(dest, s) == strcpy(dest, s))
		printf("OK\n");
	else 
		printf("FALSE\n");
	printf("-----------------------------\n");
	free(dest);
    return (0);
}

static void	check_write(int fd, char *s)
{
	int err_tmp;
    int r1;
    int r2;
    
	errno = 0;
	err_tmp = 0;
    r1 = ft_write(fd, s, strlen(s));
    err_tmp = errno;
    r2 = write(fd, s, strlen(s));
    printf("\n");
	printf("My   output: res = %i  |  err = %i\n", r1, err_tmp);
	printf("Real output: res = %i  |  err = %i\n\n", r2, errno);
	if (r1 == r2)
		printf("OK\n");
	else 
		printf("FALSE\n");

	printf("-----------------------------\n");
}

static void check_strcmp(char *s1, char *s2)
{
	int res1;
	int res2;
	
	res1 = ft_strcmp(s1, s2);
	res2 =	ft_strcmp_c(s1, s2);
	printf("----------FT_STRCMP----------\n\n");
	printf("My   output: %d\n", res1);
	printf("Real output: %d\n", res2);
	if (res1 == res2)
		printf("OK\n");
	else 
		printf("FALSE\n");
	printf("-----------------------------\n");
}

static void	check_read(void)
{
	char	buff1[512];
	char 	buff2[512];
	int		fd;
	size_t	ret1;
	size_t	ret2;
	int		err_tmp;
	
	bzero(buff1, 512);
	bzero(buff2, 512);
	errno = 0;
	fd = open("filetest/test.txt", O_RDONLY);
	ret1 = ft_read(fd, buff1, 512);
	buff1[ret1] = 0;
	close(fd);
	err_tmp = errno;
	errno = 0;
	fd = open("filetest/test.txt", O_RDONLY);
	ret2 = read(fd, buff2, 512);
	buff2[ret2] = 0;
	close(fd);

    printf("----------FT_READ VALID FILE----------\n\n");
	printf("My   output: %zu\n", ret1);
	printf("Real output: %zu\n", ret2);
	if (ret1 == ret2)
		printf("OK\n");
	else 
		printf("Return FALSE\n");
	if (strcmp(buff1, buff2) == 0)
		printf("OK    |   buff1  = %s <---> buff2 = %s\n", buff1, buff2);
	else 
		printf("FALSE |   buff1  = %s <---> buff2 = %s\n", buff1, buff2);
	if (errno == err_tmp)
		printf("OK    | my errno = %d <---> errno = %d\n", err_tmp, errno);
	else
		printf("FALSE | my errno = %d <---> errno = %d\n\n", err_tmp, errno);
    bzero(buff1, 512);
    bzero(buff2, 512);
    errno = 0;
	ret1 = ft_read(-1, buff1, 512);
    err_tmp = errno;
	errno = 0;
	ret2 = read(-1, buff2, 512);
    printf("----------FT_READ INVALID FILE -1 ----------\n\n");
	printf("My   output: %zu\n", ret1);
	printf("Real output: %zu\n", ret2);
	if (ret1 == ret2)
		printf("OK\n");
	else 
		printf("Return FALSE\n");
	if (strcmp(buff1, buff2) == 0)
		printf("OK    |   buff1  = %s <---> buff2 = %s\n", buff1, buff2);
	else 
		printf("FALSE |   buff1  = %s <---> buff2 = %s\n", buff1, buff2);
	if (errno == err_tmp)
		printf("OK    | my errno = %d <---> errno = %d\n", err_tmp, errno);
	else
		printf("FALSE | my errno = %d <---> errno = %d\n\n", err_tmp, errno);
    bzero(buff1, 512);
	bzero(buff2, 512);
    errno = 0;
    fd = open("filetest/test2.txt", O_RDONLY);
	ret1 = ft_read(-1, buff1, 512);
    close(fd);
    err_tmp = errno;
	errno = 0;
    fd = open("filetest/test2.txt", O_RDONLY);
	ret2 = read(-1, buff2, 512);
    close(fd);
    printf("----------FT_READ EMPTY FILE----------\n\n");
	printf("My   output: %zu\n", ret1);
	printf("Real output: %zu\n", ret2);
	if (ret1 == ret2)
		printf("OK\n");
	else 
		printf("Return FALSE\n");
	if (strcmp(buff1, buff2) == 0)
		printf("OK |      buff1  = %s <---> buff2 = %s\n", buff1, buff2);
	else 
		printf("FALSE |   buff1  = %s <---> buff2 = %s\n", buff1, buff2);
	if (errno == err_tmp)
		printf("OK |    my errno = %d <---> errno = %d\n", err_tmp, errno);
	else
		printf("FALSE | my errno = %d <---> errno = %d\n\n", err_tmp, errno);

    printf("-----------------------------\n");
}

static int	check_strdup(char *s)
{

	char *s1;
	char *s2;

	s1 = ft_strdup(s);
	s2 = strdup(s);
	printf("----------FT_STRDUP----------\n\n");
	printf("My   output: %s\n", ft_strdup(s));
	printf("Real output: %s\n", strdup(s));
	if (strcmp(s1, s2) == 0)
		printf("OK\n");
	else 
		printf("FALSE\n");
	printf("-----------------------------\n");
    return (0);
}

int main(int argc, char **argv)
{
    int check;
    
    check = 0;
	if (argc == 2 || argc == 3)
	{
		check_strlen(argv[1]);
		check = check_strcpy(argv[1]);
        if (check == -1)
        {   
            printf("error malloc\n");
            return (-1);
        }
		check_strdup(argv[1]);
        printf("----------FT_WRITE----------\n\n");
		printf("FD = 0\n");
        check_write(0, argv[1]);
        printf("FD = 1\n");
        check_write(1, argv[1]);
        printf("FD = 150\n");
        check_write(150, argv[1]);
        printf("FD = -1\n");
        check_write(-1, argv[1]);
		check_read();
		if (argv[2])
		{
			check_strcmp(argv[1], argv[2]);
			check_strlen(argv[2]);
			check_strcpy(argv[2]);
			check_write(0, argv[2]);
			check_strdup(argv[2]);
		}
        printf("-------------END-------------\n");
	}
	else
	{
		printf("(: You need to enter 1 or 2 arguements to check the functions :)\n");
		return (-1);
	}
	return (0);
}

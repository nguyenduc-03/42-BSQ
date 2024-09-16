/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:48:20 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/16 19:25:44 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>    // for open
#include <stdlib.h>

#define BUFFER_SIZE 128

ssize_t	ft_how_long_dict(char *filename)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	ssize_t	total_bytes;

	total_bytes = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			close(fd);
			return (-1);
		}
		if (bytes_read == 0)
			break ;
		total_bytes += bytes_read;
	}
	close(fd);
	return (total_bytes);
}

void	display_file_content(int fd, ssize_t length)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	ssize_t	total_read;

	total_read = 0;
	while (total_read < length)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			write(2, "Cannot read file.\n", 19);
			return ;
		}
		if (bytes_read == 0)
			break ;
		write(1, buffer, bytes_read);
		total_read += bytes_read;
	}
}

void	display_map(const char *filename)
{
	int		fd;
	ssize_t	length;

	length = ft_how_long_dict((char *)filename);
	if (length < 0)
	{
		write(2, "Cannot read file.\n", 19);
		return ;
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 19);
		return ;
	}
	display_file_content(fd, length);
	close(fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 05:27:29 by bchytter          #+#    #+#             */
/*   Updated: 2022/02/12 05:27:29 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_width(char *line)
{
	int		i;
	char	**words;

	i = 0;
	words = ft_split(line, ' ');
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (i);
}

void	alloc_matrix(t_fdf *data)
{
	int	i;

	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (!(data->z_matrix))
	{
		free(data->z_matrix);
		error_alloc();
	}
	i = data->height;
	while (i > 0)
		data->z_matrix[--i] = (int *)malloc(sizeof(int) * (data->width));
}

void	set_cord(int *z_line, char *line)
{
	int		i;
	char	**nums;

	i = 0;
	nums = ft_split(line, ' ');
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free (nums[i]);
		i++;
	}
	free (nums);
}

void	initial_matrix(t_fdf *data, char *filename)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (y != data->height)
	{
		set_cord(data->z_matrix[y], line);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	close(fd);
}

void	readmap(t_fdf *data, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (!(fd))
		ft_error_fd();
	data->width = get_width((line = get_next_line(fd)));
	free(line);
	data->height++;
	line = get_next_line(fd);
	while (line)
	{
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	alloc_matrix(data);
	close(fd);
	initial_matrix(data, filename);
}

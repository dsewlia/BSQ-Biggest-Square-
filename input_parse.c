/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:17:34 by dsewlia           #+#    #+#             */
/*   Updated: 2025/01/13 11:44:41 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	get_input_char(char *first_line, int *data, int i)
{
	int		j;
	int		th;

	th = 1;
	data[ROW] = 0;
	while (first_line[i] >= '0' && first_line[i] <= '9')
		i++;
	j = i;
	while (--i >= 0)
	{
		data[ROW] = data[ROW] + ((first_line[i] - '0') * th);
		th = th * 10;
	}
	data[PLANE] = first_line[j++];
	data[OBJ] = first_line[j++];
	data[SQUARE] = first_line[j++];
	if (first_line[j] != '\n' || first_line[j + 1] != '\0' || data[ROW] <= 0
		|| data[PLANE] == data[OBJ] || data[OBJ] == data[SQUARE]
		|| data[SQUARE] == data[PLANE])
	{
		write(2, "First line not in the right format\n", 35);
		free (first_line);
		exit (1);
	}
}

int	line_len(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	check_map(char **map, int *map_data, int i)
{
	int		j;

	if (i == map_data[ROW])
	{
		map_data[COL] = line_len(map[0]);
		i = 0;
		while (i < map_data[ROW])
		{
			j = line_len(map[i]);
			if (j != map_data[COL])
				return (1);
			if ((i < (map_data[ROW] - 1))
				&& (map[i][j] != '\n' || map[i][j + 1] != '\0'))
				return (1);
			if (i == map_data[ROW] - 1 && map[i][j] != '\0')
				return (1);
			while (j-- > 0)
				if (map[i][j] != map_data[OBJ] && map[i][j] != map_data[PLANE])
					return (1);
			i++;
		}
	}
	else
		return (1);
	return (0);
}

void	get_map(char **map, int *map_data, int fd)
{
	int		i;

	i = -1;
	while (++i < map_data[ROW])
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
		{
			while (i-- > 0)
				free (map[i]);
			free (map);
			exit (1);
		}
	}
	if (fd == 0)
		map[i - 1][line_len(map[0])] = '\0';
	if (check_map(map, map_data, i) == 1
		|| (fd != 0 && get_next_line(fd) != NULL))
	{
		write (2, "map error\n", 10);
		while (i-- > 0)
			free (map[i]);
		free (map);
		exit (1);
	}
}

void	input_parse(int fd)
{
	int		map_data[8];
	char	**map;
	char	*first_line;

	first_line = get_next_line(fd);
	if (first_line == NULL)
	{
		write (2, "error reading file\n", 19);
		exit (1);
	}
	get_input_char(first_line, map_data, 0);
	free (first_line);
	map = (char **)malloc(sizeof(char *) * (map_data[ROW] + 1));
	if (map == NULL)
	{
		write (2, "Error allocating memory\n", 24);
		exit (1);
	}
	get_map(map, map_data, fd);
	map_data[X_AXIS] = 0;
	map_data[Y_AXIS] = 0;
	map_data[LENGTH] = 0;
	initiate_solve(map, map_data);
	print_solution(map, map_data);
}

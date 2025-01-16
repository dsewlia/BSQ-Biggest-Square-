/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:45:35 by dsewlia           #+#    #+#             */
/*   Updated: 2025/01/13 10:41:15 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_square(char **map, int *map_data, int x, int y)
{
	int		i;
	int		max_len;

	max_len = 0;
	while (max_len < map_data[ROW] - x && max_len < map_data[COL] - y)
	{
		i = 0;
		while (i <= max_len && x + i < map_data[ROW]
			&& y + max_len < map_data[COL])
		{
			if (map[x + i][y + max_len] == map_data[OBJ])
				return (max_len - 1);
			i++;
		}
		i = 0;
		while (i <= max_len && y + i < map_data[COL]
			&& x + max_len < map_data[ROW])
		{
			if (map[x + max_len][y + i] == map_data[OBJ])
				return (max_len - 1);
			i++;
		}
		max_len++;
	}
	return (max_len - 1);
}

void	check_largest_square(char **map, int *map_data, int x, int y)
{
	int		i;
	int		j;
	int		max_len;

	i = 0;
	j = 0;
	max_len = check_square(map, map_data, x, y);
	if (max_len > map_data[LENGTH])
	{
		map_data[X_AXIS] = x;
		map_data[Y_AXIS] = y;
		map_data[LENGTH] = max_len;
	}
}

void	place_single_square(char **map, int *map_data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map_data[ROW])
	{
		j = -1;
		while (++j < map_data[COL])
		{
			if (map[i][j] == map_data[PLANE])
			{
				map[i][j] = map_data[SQUARE];
				return ;
			}
		}
	}
}

void	place_square(char **map, int *map_data)
{
	int		i;
	int		j;
	int		x;
	int		y;

	x = map_data[X_AXIS];
	y = map_data[Y_AXIS];
	i = -1;
	if (map_data[LENGTH] > 0)
	{
		while (++i <= map_data[LENGTH])
		{
			j = -1;
			while (++j <= map_data[LENGTH])
				if (map[x + i][y + j] != map_data[OBJ])
					map[x + i][y + j] = map_data[SQUARE];
		}
	}
	else
		place_single_square(map, map_data);
}

void	initiate_solve(char **map, int *map_data)
{
	int		x;
	int		y;

	x = 0;
	while ((x + map_data[LENGTH]) < map_data[ROW])
	{
		y = 0;
		while ((y + map_data[LENGTH]) < map_data[COL])
		{
			if (map[x][y] != map_data[OBJ])
				check_largest_square(map, map_data, x, y);
			y++;
		}
		x++;
	}
	place_square(map, map_data);
}

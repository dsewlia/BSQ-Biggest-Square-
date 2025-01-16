/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:15:40 by dsewlia           #+#    #+#             */
/*   Updated: 2025/01/12 17:18:19 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_solution(char **map, int *map_data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map_data[ROW])
	{
		j = 0;
		while (j < map_data[COL])
		{
			write (1, &map[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
	while (i-- > 0)
		free (map[i]);
	free (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:06:30 by dsewlia           #+#    #+#             */
/*   Updated: 2025/01/13 10:45:24 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;

	if (argc == 1)
		input_parse(0);
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
			{
				write (2, "error opening file\n", 19);
				return (1);
			}
			input_parse(fd);
			i++;
			if (i < argc)
				write (1, "\n", 1);
		}
	}
	return (0);
}

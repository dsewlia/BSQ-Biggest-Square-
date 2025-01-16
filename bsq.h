/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:17:14 by dsewlia           #+#    #+#             */
/*   Updated: 2025/01/13 11:45:40 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define ROW 0
# define COL 1
# define OBJ 2
# define PLANE 3
# define SQUARE 4
# define LENGTH 5
# define X_AXIS 6
# define Y_AXIS 7

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*reset_fd_2(char *new_fd);
char	*reset_fd(char **fd_log, int fd, size_t i, size_t j);
char	*get_the_line_2(char **fd_log, char *new_line, int fd, size_t i);
char	*get_the_line(char **fd_log, int fd, size_t i, size_t j);
char	*get_next_line_2(char **fd_log, int fd, size_t i, size_t j);
char	*get_next_line(int fd);
void	print_solution(char **map, int *map_data);
int		check_square(char **map, int *map_data, int x, int y);
void	check_largest_square(char **map, int *map_data, int x, int y);
void	place_square(char **map, int *map_data);
void	initiate_solve(char **map, int *map_data);
void	get_input_char(char *first_line, int *data, int i);
int		line_len(char *s);
int		check_map(char **map, int *map_data, int i);
void	get_map(char **map, int *map_data, int fd);
void	input_parse(int fd);
int		main(int argc, char **argv);

#endif

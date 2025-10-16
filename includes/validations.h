/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostafa <mostafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:38:07 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/10 18:42:33 by mostafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATIONS_H
# define VALIDATIONS_H

# include "utils.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
}	t_colors;

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_data
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	t_colors	*f;
	t_colors	*c;
	t_map		*map;
}	t_data;

int		ft_map_length(char **map);
void	free_map(char **map);
int		is_valid_map_char(char c);
int		validate_map_characters(char **map);
int		validate_map_border(char **map);
int		data_filled(t_data *data);
void	free_all_data_node(t_data *data);
int		fill_data(char *file_name, t_data *data, char *direction);
int		check_data_file_name(char *file_name, t_data *data, char *direction);
int		fill_colors(char **array, t_data *data, char *direction);
int		check_if_color(char *colors, t_data *data, char *color_type);
int		check_extension(char *file_name, char *extension);
int		check_existing_file(char *file_name);
int		check_line_and_fill(char *line, t_data *data);
int		fill_map(int fd, char *line, t_data *data);
int		valid_file_content(char *str, t_data *data);
int		check_all_validation(char *str, t_data *data);
void	clean_and_exit(char *line, char **map, t_data *data, int fd);
int		check_empty_line(char *line, t_data *data, int fd);
char	**initialize_map(int *capacity);
int		check_trailing_content(int fd);
int		expand_map_capacity(char ***map, int *capacity);
int		allocate_map_struct(t_data *data, char **map, int fd);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostafa <mostafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:53:36 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/10 18:41:27 by mostafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validations.h"

static int	process_map_line(char *line, char ***map, int *i, int *capacity)
{
	ft_trim(line);
	ft_clean_line_from_spaces(line);
	if (line[0] == '\0')
		return (-1);
	if (*i >= *capacity)
	{
		if (!expand_map_capacity(map, capacity))
			return (0);
	}
	(*map)[(*i)++] = line;
	return (1);
}

static int	read_map_lines(int fd, char ***map, int *i, int *capacity)
{
	char	*line;
	int		result;

	line = get_next_line(fd);
	while (line)
	{
		result = process_map_line(line, map, i, capacity);
		if (result == -1)
		{
			free(line);
			return (check_trailing_content(fd));
		}
		if (result == 0)
			return (free(line), 0);
		line = get_next_line(fd);
	}
	return (1);
}

static int	finalize_map_array(char ***map, int i, int capacity)
{
	char	**new_map;

	if (i >= capacity)
	{
		new_map = realloc(*map, (i + 1) * sizeof(char *));
		if (!new_map)
			return (0);
		*map = new_map;
	}
	(*map)[i] = NULL;
	return (1);
}

static int	validate_map(char **map, t_data *data, int fd)
{
	if (!validate_map_characters(map))
		return (clean_and_exit(NULL, map, data, fd), 0);
	if (!validate_map_border(map))
		return (clean_and_exit(NULL, map, data, fd), 0);
	return (1);
}

int	fill_map(int fd, char *line, t_data *data)
{
	char	**map;
	int		i;
	int		capacity;

	i = 0;
	if (!check_empty_line(line, data, fd))
		return (0);
	map = initialize_map(&capacity);
	if (!map)
		return (clean_and_exit(line, NULL, data, fd), 0);
	ft_clean_line_from_spaces(line);
	map[i++] = line;
	if (!read_map_lines(fd, &map, &i, &capacity))
		return (clean_and_exit(NULL, map, data, fd), 0);
	if (!finalize_map_array(&map, i, capacity) || i == 0)
		return (clean_and_exit(NULL, map, data, fd), 0);
	if (!validate_map(map, data, fd))
		return (0);
	if (!allocate_map_struct(data, map, fd))
		return (0);
	data->map->map = map;
	return (close(fd), 1);
}

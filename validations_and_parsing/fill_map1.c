/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostafa <mostafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:52:42 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/10 18:41:22 by mostafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validations.h"

int	check_empty_line(char *line, t_data *data, int fd)
{
	ft_trim(line);
	if (line[0] == '\0')
	{
		printf("Error: empty line in map\n");
		clean_and_exit(line, NULL, data, fd);
		return (0);
	}
	return (1);
}

char	**initialize_map(int *capacity)
{
	char	**map;

	*capacity = 10;
	map = calloc(*capacity, sizeof(char *));
	return (map);
}

int	check_trailing_content(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		ft_trim(line);
		if (line[0] != '\0')
		{
			printf("Error: content found after map\n");
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	expand_map_capacity(char ***map, int *capacity)
{
	int		old_capacity;
	int		j;
	char	**new_map;

	old_capacity = *capacity;
	*capacity *= 2;
	new_map = ft_realloc(*map, old_capacity * sizeof(char *),
			*capacity * sizeof(char *));
	if (!new_map)
		return (0);
	*map = new_map;
	j = old_capacity;
	while (j < *capacity)
		(*map)[j++] = NULL;
	return (1);
}

int	allocate_map_struct(t_data *data, char **map, int fd)
{
	if (!data->map)
	{
		data->map = malloc(sizeof(t_map));
		if (!data->map)
			return (clean_and_exit(NULL, map, data, fd), 0);
	}
	return (1);
}

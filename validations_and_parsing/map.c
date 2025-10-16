/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:45:55 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 11:51:46 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validations.h"

int	ft_map_length(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ');
}

int	validate_map_characters(char **map)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_map_char(map[i][j]))
				return (printf("Error: invalid character '%c' in map\n",
						map[i][j]), 0);
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (printf("Error: map must have exactly one player\n"), 0);
	return (1);
}

int	check_border_cell(char **map, int i, int j, int map_length)
{
	if (i == 0 || i == map_length - 1)
	{
		if (map[i][j] != '1')
		{
			printf("Error: all borders should be '1'\n");
			return (0);
		}
	}
	else
	{
		if (j == 0 || j == (int)ft_strlen(map[i]) - 1)
		{
			if (map[i][j] != '1')
			{
				printf("Error: all borders should be '1'\n");
				return (0);
			}
		}
	}
	return (1);
}

int	validate_map_border(char **map)
{
	int	i;
	int	j;
	int	map_length;

	i = 0;
	map_length = ft_map_length(map);
	while (i < map_length)
	{
		j = 0;
		while (map[i][j])
		{
			if (!check_border_cell(map, i, j, map_length))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

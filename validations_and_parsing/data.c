/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:35:06 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 15:19:15 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validations.h"

int	data_filled(t_data *data)
{
	if (data->ea == NULL || data->no == NULL
		|| data->so == NULL || data->we == NULL
		|| data->c == NULL || data->f == NULL)
		return (0);
	return (1);
}

void	free_all_data_node(t_data *data)
{
	if (!data)
		return ;
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->ea)
		free(data->ea);
	if (data->we)
		free(data->we);
	if (data->f)
		free(data->f);
	if (data->c)
		free(data->c);
	if (data->map)
	{
		if (data->map->map)
			free_map(data->map->map);
		free(data->map);
	}
	free(data);
}

int	fill_data(char *file_name, t_data *data, char *direction)
{
	if (ft_strcmp(direction, "NO") == 0 && data->no == NULL)
		return (data->no = ft_strdup(file_name), 1);
	else if (ft_strcmp(direction, "SO") == 0 && data->so == NULL)
		return (data->so = ft_strdup(file_name), 1);
	else if (ft_strcmp(direction, "WE") == 0 && data->we == NULL)
		return (data->we = ft_strdup(file_name), 1);
	else if (ft_strcmp(direction, "EA") == 0 && data->ea == NULL)
		return (data->ea = ft_strdup(file_name), 1);
	return (printf("Error : duplication occured\n"), 0);
}

int	check_data_file_name(char *file_name, t_data *data, char *direction)
{
	char	*trimmed;

	trimmed = ft_trim(file_name);
	if (!check_extension(trimmed, ".xpm"))
		return (0);
	if (!check_existing_file(trimmed))
		return (0);
	if (!fill_data(trimmed, data, direction))
		return (0);
	return (1);
}

int	check_if_color(char *colors, t_data *data, char *color_type)
{
	char	**colors_array;

	ft_trim(colors);
	colors_array = ft_split_and_trim(colors, ',');
	if (!validate_array_length(colors_array))
		return (free_split(colors_array), 0);
	if (!check_number_in_array(colors_array))
	{
		printf("Error: all should be numbers <0, 255>\n");
		return (free_split(colors_array), 0);
	}
	if (!fill_colors(colors_array, data, color_type))
		return (free_split(colors_array), 0);
	free_split(colors_array);
	return (1);
}

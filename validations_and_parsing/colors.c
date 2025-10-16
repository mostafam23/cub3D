/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:41:08 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 12:08:25 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validations.h"

static int	validate_color_range(char **array)
{
	if (ft_atoi(array[0]) < 0 || ft_atoi(array[0]) > 255)
		return (printf("Error : color number not in range\n"), 0);
	if (ft_atoi(array[1]) < 0 || ft_atoi(array[1]) > 255)
		return (printf("Error : color number not in range\n"), 0);
	if (ft_atoi(array[2]) < 0 || ft_atoi(array[2]) > 255)
		return (printf("Error : color number not in range\n"), 0);
	return (1);
}

static int	assign_color_values(t_colors *color, char **array)
{
	color->r = ft_atoi(array[0]);
	color->g = ft_atoi(array[1]);
	color->b = ft_atoi(array[2]);
	return (1);
}

static int	fill_floor_color(char **array, t_data *data)
{
	if (data->f != NULL)
		return (printf("Error : duplication occured\n"), 0);
	if (!validate_color_range(array))
		return (0);
	data->f = malloc(sizeof(t_colors));
	if (!data->f)
		return (0);
	return (assign_color_values(data->f, array));
}

static int	fill_ceiling_color(char **array, t_data *data)
{
	if (data->c != NULL)
		return (printf("Error : duplication occured\n"), 0);
	if (!validate_color_range(array))
		return (0);
	data->c = malloc(sizeof(t_colors));
	if (!data->c)
		return (0);
	return (assign_color_values(data->c, array));
}

int	fill_colors(char **array, t_data *data, char *direction)
{
	if (ft_strcmp(direction, "F") == 0)
		return (fill_floor_color(array, data));
	else if (ft_strcmp(direction, "C") == 0)
		return (fill_ceiling_color(array, data));
	return (0);
}

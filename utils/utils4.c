/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:32:32 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 12:08:34 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_number_in_array(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (!ft_isdigit(array[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	size_t	i;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	handle_empty_line(char *line)
{
	if (line[0] == '\n' && line[1] == '\0')
	{
		free(line);
		return (1);
	}
	return (0);
}

int	validate_array_length(char **colors_array)
{
	int	check_length;

	check_length = 0;
	while (colors_array && colors_array[check_length] != NULL)
		check_length++;
	if (check_length != 3)
	{
		printf("Error: rgb should have 3 numbers\n");
		return (0);
	}
	return (1);
}

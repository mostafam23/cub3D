/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostafa <mostafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:46:58 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/10 18:34:29 by mostafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validations.h"

static int	process_data_line(char *line, t_data *data, int fd)
{
	ft_trim(line);
	if (!check_line_and_fill(line, data))
	{
		free(line);
		free_all_data_node(data);
		close(fd);
		return (0);
	}
	free(line);
	return (1);
}

static int	check_missing_data(t_data *data, int fd)
{
	if (!data_filled(data))
	{
		printf("Error: missing data\n");
		free_all_data_node(data);
		close(fd);
		return (0);
	}
	return (1);
}

static int	handle_no_map_error(t_data *data, int fd)
{
	printf("Error: no map found\n");
	free_all_data_node(data);
	close(fd);
	return (0);
}

int	valid_file_content(char *str, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (handle_empty_line(line))
		{
			line = get_next_line(fd);
			continue ;
		}
		if (data_filled(data))
			return (fill_map(fd, line, data));
		if (!process_data_line(line, data, fd))
			return (0);
		line = get_next_line(fd);
	}
	if (!check_missing_data(data, fd))
		return (0);
	return (handle_no_map_error(data, fd));
}

int	check_all_validation(char *str, t_data *data)
{
	if (!check_extension(str, ".cub"))
		return (free_all_data_node(data), 0);
	if (!check_existing_file(str))
	{
		free_all_data_node(data);
		return (printf("Error: file does not exist\n"), 0);
	}
	if (!valid_file_content(str, data))
		return (0);
	return (1);
}

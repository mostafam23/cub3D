/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:45:46 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 15:20:18 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validations.h"

int	check_extension(char *file_name, char *extension)
{
	file_name = file_name + (ft_strlen(file_name) - 4);
	if (ft_strncmp(file_name, extension, 4))
		return (printf("Error: Wrong file extension\n"), 0);
	return (1);
}

int	check_existing_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	check_line_and_fill(char *line, t_data *data)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (check_data_file_name(&line[3], data, "NO"));
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (check_data_file_name(&line[3], data, "SO"));
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (check_data_file_name(&line[3], data, "WE"));
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (check_data_file_name(&line[3], data, "EA"));
	else if (line[0] == 'F' && line[1] == ' ')
		return (check_if_color(&line[2], data, "F"));
	else if (line[0] == 'C' && line[1] == ' ')
		return (check_if_color(&line[2], data, "C"));
	return (printf("Error: Invalid data\n"), 0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	clean_and_exit(char *line, char **map, t_data *data, int fd)
{
	if (line)
		free(line);
	if (map)
		free_map(map);
	free_all_data_node(data);
	close(fd);
}

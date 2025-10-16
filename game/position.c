/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:32:46 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 12:32:49 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	is_valid_position(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;
	int	line_len;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0)
		return (0);
	if (!game->data->map->map[map_y])
		return (0);
	line_len = ft_strlen(game->data->map->map[map_y]);
	if (map_x >= line_len)
		return (0);
	if (game->data->map->map[map_y][map_x] == '1')
		return (0);
	if (game->data->map->map[map_y][map_x] == ' ')
		return (0);
	return (1);
}

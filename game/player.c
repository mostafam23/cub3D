/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:39:51 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 12:39:52 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	set_player_direction(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (dir == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (dir == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (dir == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
}

static void	finalize_player_init(t_game *game, t_data *data, int x, int y)
{
	double	fov;

	fov = 0.66;
	game->player.plane_x = -game->player.dir_y * fov;
	game->player.plane_y = game->player.dir_x * fov;
	data->map->map[y][x] = '0';
	game->data = data;
}

static int	check_and_set_player(t_game *game, t_data *data, int x, int y)
{
	char	dir;

	dir = data->map->map[y][x];
	if (dir == 'N' || dir == 'S' || dir == 'E' || dir == 'W')
	{
		game->player.x = x + 0.5;
		game->player.y = y + 0.5;
		set_player_direction(game, dir);
		finalize_player_init(game, data, x, y);
		return (1);
	}
	return (0);
}

void	init_player(t_game *game, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (check_and_set_player(game, data, x, y))
				return ;
			x++;
		}
		y++;
	}
}

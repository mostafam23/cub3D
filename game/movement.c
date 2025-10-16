/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:33:01 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 12:33:06 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	move_speed;

	move_speed = 0.05;
	new_x = game->player.x + game->player.dir_x * move_speed;
	new_y = game->player.y + game->player.dir_y * move_speed;
	if (is_valid_position(game, new_x, game->player.y))
		game->player.x = new_x;
	if (is_valid_position(game, game->player.x, new_y))
		game->player.y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	move_speed;

	move_speed = 0.05;
	new_x = game->player.x - game->player.dir_x * move_speed;
	new_y = game->player.y - game->player.dir_y * move_speed;
	if (is_valid_position(game, new_x, game->player.y))
		game->player.x = new_x;
	if (is_valid_position(game, game->player.x, new_y))
		game->player.y = new_y;
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;
	double	move_speed;

	move_speed = 0.05;
	new_x = game->player.x - game->player.plane_x * move_speed;
	new_y = game->player.y - game->player.plane_y * move_speed;
	if (is_valid_position(game, new_x, game->player.y))
		game->player.x = new_x;
	if (is_valid_position(game, game->player.x, new_y))
		game->player.y = new_y;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;
	double	move_speed;

	move_speed = 0.05;
	new_x = game->player.x + game->player.plane_x * move_speed;
	new_y = game->player.y + game->player.plane_y * move_speed;
	if (is_valid_position(game, new_x, game->player.y))
		game->player.x = new_x;
	if (is_valid_position(game, game->player.x, new_y))
		game->player.y = new_y;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostafa <mostafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:33:10 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/10 17:47:23 by mostafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game, game->data);
	else if (keycode == KEY_W)
		game->keys.w = 1;
	else if (keycode == KEY_S)
		game->keys.s = 1;
	else if (keycode == KEY_A)
		game->keys.a = 1;
	else if (keycode == KEY_D)
		game->keys.d = 1;
	else if (keycode == KEY_LEFT)
		game->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 0;
	else if (keycode == KEY_S)
		game->keys.s = 0;
	else if (keycode == KEY_A)
		game->keys.a = 0;
	else if (keycode == KEY_D)
		game->keys.d = 0;
	else if (keycode == KEY_LEFT)
		game->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 0;
	return (0);
}

void	process_movement(t_game *game)
{
	if (game->keys.w)
		move_forward(game);
	if (game->keys.s)
		move_backward(game);
	if (game->keys.a)
		move_left(game);
	if (game->keys.d)
		move_right(game);
	if (game->keys.left)
		rotate_left(game);
	if (game->keys.right)
		rotate_right(game);
}

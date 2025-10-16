/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:40:13 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 12:44:54 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	cast_ray(t_game *game, int x)
{
	t_raycast	ray;

	init_ray(game, &ray, x);
	perform_dda(game, &ray);
	calculate_wall_distance(game, &ray);
	select_texture(game, &ray);
	calculate_texture_x(game, &ray);
	draw_floor_ceiling(game, x, ray.draw_start, ray.draw_end);
	draw_vertical_line(game, x, &ray);
}

int	render_frame(t_game *game)
{
	int	x;

	process_movement(game);
	x = 0;
	while (x < WIN_W)
	{
		cast_ray(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

void	init_keys(t_game *game)
{
	game->keys.w = 0;
	game->keys.s = 0;
	game->keys.a = 0;
	game->keys.d = 0;
	game->keys.left = 0;
	game->keys.right = 0;
}

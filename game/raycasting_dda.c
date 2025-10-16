/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:40:53 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 12:40:54 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	is_valid_map_position(t_game *game, int map_x, int map_y)
{
	int	line_len;

	if (map_y < 0 || !game->data->map->map[map_y])
		return (0);
	line_len = ft_strlen(game->data->map->map[map_y]);
	if (map_x < 0 || map_x >= line_len)
		return (0);
	return (1);
}

static int	check_wall_hit(t_game *game, t_raycast *ray)
{
	if (!is_valid_map_position(game, ray->map_x, ray->map_y))
		return (1);
	if (game->data->map->map[ray->map_y][ray->map_x] == '1')
		return (1);
	if (game->data->map->map[ray->map_y][ray->map_x] == ' ')
		return (1);
	return (0);
}

void	perform_dda(t_game *game, t_raycast *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (check_wall_hit(game, ray))
			hit = 1;
	}
}

void	calculate_wall_distance(t_game *game, t_raycast *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->line_height = (int)(WIN_H / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_H / 2;
	if (ray->draw_end >= WIN_H)
		ray->draw_end = WIN_H - 1;
}

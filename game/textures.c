/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:39:35 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 12:39:41 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	load_single_texture(void *mlx, t_texture *tex, char *path)
{
	if (!path)
		return (printf("Error: Missing texture path\n"), 0);
	tex->img = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height);
	if (!tex->img)
		return (printf("Error: Failed to load texture: %s\n", path), 0);
	tex->addr = mlx_get_data_addr(tex->img,
			&tex->bpp, &tex->line_len, &tex->endian);
	if (!tex->addr)
	{
		printf("Error: Failed to get data address for texture: %s\n", path);
		return (0);
	}
	return (1);
}

int	load_textures(t_game *game, t_data *data)
{
	if (!load_single_texture(game->mlx, &game->tex.north, data->no))
		return (0);
	if (!load_single_texture(game->mlx, &game->tex.south, data->so))
		return (0);
	if (!load_single_texture(game->mlx, &game->tex.east, data->ea))
		return (0);
	if (!load_single_texture(game->mlx, &game->tex.west, data->we))
		return (0);
	return (1);
}

int	get_texture_color(t_texture *tex, int tex_x, int tex_y)
{
	char	*dst;

	if (tex_x < 0 || tex_x >= tex->width)
		return (0);
	if (tex_y < 0 || tex_y >= tex->height)
		return (0);
	dst = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

void	select_texture(t_game *game, t_raycast *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			ray->tex = &game->tex.east;
		else
			ray->tex = &game->tex.west;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			ray->tex = &game->tex.south;
		else
			ray->tex = &game->tex.north;
	}
}

void	calculate_texture_x(t_game *game, t_raycast *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = game->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * (double)ray->tex->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = ray->tex->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = ray->tex->width - ray->tex_x - 1;
}

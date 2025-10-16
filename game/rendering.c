/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:41:06 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 12:41:22 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_vertical_line(t_game *game, int x, t_raycast *ray)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;

	step = 1.0 * ray->tex->height / ray->line_height;
	tex_pos = (ray->draw_start - WIN_H / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (ray->tex->height - 1);
		tex_pos += step;
		color = get_texture_color(ray->tex, ray->tex_x, tex_y);
		my_mlx_pixel_put(&game->img, x, y, color);
		y++;
	}
}

static int	get_ceiling_color(t_game *game)
{
	int	color;

	color = (game->data->c->r << 16)
		| (game->data->c->g << 8)
		| game->data->c->b;
	return (color);
}

static int	get_floor_color(t_game *game)
{
	int	color;

	color = (game->data->f->r << 16)
		| (game->data->f->g << 8)
		| game->data->f->b;
	return (color);
}

void	draw_floor_ceiling(t_game *game, int x, int draw_start, int draw_end)
{
	int	y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = get_ceiling_color(game);
	floor_color = get_floor_color(game);
	y = 0;
	while (y < draw_start)
	{
		my_mlx_pixel_put(&game->img, x, y, ceiling_color);
		y++;
	}
	y = draw_end;
	while (y < WIN_H)
	{
		my_mlx_pixel_put(&game->img, x, y, floor_color);
		y++;
	}
}

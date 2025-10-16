/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostafa <mostafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:37:07 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/10 19:11:54 by mostafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "Cub3D");
	if (!game->win)
		return (0);
	return (1);
}

static int	init_image(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	if (!game->img.img)
		return (0);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.line_len, &game->img.endian);
	if (!game->img.addr)
		return (0);
	return (1);
}

int	init_game(t_game *game, t_data *data)
{
	if (!init_mlx(game))
		return (ft_putstr_fd("Error: mlx_init failed\n", 2), 0);
	if (!init_image(game))
		return (ft_putstr_fd("Error: image creation failed\n", 2), 0);
	if (!load_textures(game, data))
		return (ft_putstr_fd("Error: texture loading failed\n", 2), 0);
	init_player(game, data);
	return (1);
}

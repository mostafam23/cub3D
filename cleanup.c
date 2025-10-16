/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:39:11 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 12:46:55 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_textures(t_game *game)
{
	if (game->tex.north.img)
		mlx_destroy_image(game->mlx, game->tex.north.img);
	if (game->tex.south.img)
		mlx_destroy_image(game->mlx, game->tex.south.img);
	if (game->tex.east.img)
		mlx_destroy_image(game->mlx, game->tex.east.img);
	if (game->tex.west.img)
		mlx_destroy_image(game->mlx, game->tex.west.img);
}

void	cleanup_and_exit(t_game *game, t_data *data)
{
	if (!game)
		exit(1);
	destroy_textures(game);
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_all_data_node(data);
	ft_putstr_fd("Game cleaned up successfully.\n", 1);
	exit(0);
}

int	close_game(t_game *game, t_data *data)
{
	cleanup_and_exit(game, data);
	return (0);
}

int	handle_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	cleanup_and_exit(game, game->data);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

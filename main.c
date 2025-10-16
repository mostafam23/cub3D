/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostafa <mostafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:35:37 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/10 19:18:14 by mostafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 3, 1L << 1, handle_keyrelease, game);
	mlx_hook(game->win, 17, 0, handle_close, game);
	mlx_loop_hook(game->mlx, render_frame, game);
}

static int	validate_args(int argc, char *argv[], t_data *data)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error: invalid args\n", 2);
		return (0);
	}
	if (!check_all_validation(argv[1], data))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	t_data	*data;

	ft_bzero(&game, sizeof(t_game));
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (ft_putstr_fd("Error: allocation failed\n", 2), 1);
	if (!validate_args(argc, argv, data))
		return (1);
	game.data = data;
	if (!init_game(&game, data))
	{
		cleanup_and_exit(&game, data);
		return (1);
	}
	setup_hooks(&game);
	mlx_loop(game.mlx);
	free_all_data_node(data);
	return (0);
}

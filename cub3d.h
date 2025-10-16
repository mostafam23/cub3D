/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:38:47 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 12:54:01 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "utils.h"
# include "get_next_line.h"
# include "validations.h"
# include "game.h"

int		init_game(t_game *game, t_data *data);
int		handle_close(void *param);
int		close_game(t_game *game, t_data *data);
void	cleanup_and_exit(t_game *game, t_data *data);
void	ft_putstr_fd(char *s, int fd);

#endif
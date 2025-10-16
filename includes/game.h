/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:36:16 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 12:53:47 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "validations.h"
# include "mlx.h"
# include <math.h>

# define WIN_W 1280
# define WIN_H 720
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65363
# define KEY_RIGHT 65361

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

typedef struct s_tex
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
}	t_tex;

typedef struct s_raycast
{
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	t_texture	*tex;
	int			tex_x;
}	t_raycast;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	player;
	t_tex		tex;
	t_data		*data;
	t_keys		keys;
}	t_game;

int		load_textures(t_game *game, t_data *data);
int		load_single_texture(void *mlx, t_texture *tex, char *path);
void	init_player(t_game *game, t_data *data);
int		render_frame(t_game *game);
void	cast_ray(t_game *game, int x);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		get_texture_color(t_texture *tex, int tex_x, int tex_y);
void	init_ray(t_game *game, t_raycast *ray, int x);
void	perform_dda(t_game *game, t_raycast *ray);
void	calculate_wall_distance(t_game *game, t_raycast *ray);
void	select_texture(t_game *game, t_raycast *ray);
void	calculate_texture_x(t_game *game, t_raycast *ray);
void	draw_vertical_line(t_game *game, int x, t_raycast *ray);
void	draw_floor_ceiling(t_game *game, int x, int draw_start, int draw_end);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
int		is_valid_position(t_game *game, double x, double y);
int		handle_keypress(int keycode, t_game *game);
int		handle_keyrelease(int keycode, t_game *game);
void	process_movement(t_game *game);
int		close_game(t_game *game, t_data *data);
void	cleanup_and_exit(t_game *game, t_data *data);

#endif

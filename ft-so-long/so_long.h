/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:46:42 by ngonzale          #+#    #+#             */
/*   Updated: 2022/09/27 22:31:24 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include "MLX42.h"

# define TEXTURE_SIZE 256
# define PLAYER_TEXTURE "textures/player.png"
# define COIN_TEXTURE "textures/collectible.png"
# define WALL_TEXTURE "textures/wall.png"
# define FLOOR_TEXTURE "textures/floor.png"
# define EXIT_TEXTURE "textures/exit.png"

# define UP -1
# define LEFT -1
# define DOWN 1
# define RIGHT 1

typedef struct s_map {
	size_t	width;
	size_t	height;
	size_t	n_c;
	size_t	n_p;
	char	**map;
}				t_map;

typedef struct s_player {
	mlx_image_t	*img;
	size_t		x;
	size_t		y;
	int			render;
}				t_player;

typedef struct s_game {
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_map			*map;
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	size_t			movements;
	size_t			n_c;
	size_t			n_p;
	int				mov_x;
	int				mov_y;
	t_player		**players;
}				t_game;

// Init
t_game		*create_game(char *mapfile);

// Player
t_player	**create_players(t_game *game);
t_player	*find_player(t_player **players, size_t x, size_t y);
int			move_player(t_game *game, t_player *player);
t_player	*create_player(t_game *game, size_t x, size_t y);
void		get_collectible(t_game *game, int x, int y);

// Parser
t_map		*parse_map(char *mapfile);

// Checker
int			check_map(t_map *map);
int			ft_check_args(int argc, char **argv);

// Checker utils
int			char_is_wall(size_t i, char c);
int			char_is_position(size_t i, char c);
int			char_is_exit(size_t i, char c);
int			char_is_collectible(size_t i, char c);
int			char_is_valid(size_t i, char c);

// Utils
mlx_image_t	*create_img_from_png(t_game *game, char *pngfile);

// Movement
void		move_players(t_game *game);
void		move_players_reverse(t_game *game);

// Render
void		render_game(t_game *game);

// Events
void		end_game(t_game *game);
void		close_hook(void *param);
void		keys_hook(mlx_key_data_t keydata, void *param);

// Free
void		free_game(t_game **game_p);
void		free_map(t_map *map);
void		free_players(mlx_t *mlx, t_player **players);

#endif

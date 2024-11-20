/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:11:44 by matomas           #+#    #+#             */
/*   Updated: 2024/11/20 16:54:21 by matomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

// Dimensiones del mundo
# define TILE_SIZE 64

// Teclas (adaptar según sistema operativo)
# ifdef __APPLE__
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_ESC 53
# else
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_ESC 65307
# endif

// Elementos del mapa
# define WALL '1'
# define FLOOR '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define ENEMY 'V'

// Estructura principal del juego
typedef struct s_game
{
	void	*mlx;// Conexión con la MiniLibX
	void	*win;// Ventana del juego
	int		width;// Anchura del mapa (en tiles)
	int		height;// Altura del mapa (en tiles)
	char	**map;// Representación 2D del mapa
	int		player_x;// Posición X del jugador
	int		player_y;// Posición Y del jugador
	int		collectibles;// Número total de objetos coleccionables
	int		moves;// Contador de movimientos
	void	*img_wall;// Sprite de muro
	void	*img_floor;// Sprite de suelo
	void	*img_player;// Sprite del jugador
	void	*img_exit;// Sprite de salida
	void	*img_collectible;// Sprite de coleccionables
	void	*img_enemy;// Sprite de enemigos
}	t_game;

// Prototipos de funciones

// Inicialización y configuración
void	init_game(t_game *game, char *map_file);
void	load_sprites(t_game *game);

// Lectura y validación del mapa
void	read_map(t_game *game, char *map_file);
void	validate_map(t_game *game);

// Renderizado del mundo
void	render_map(t_game *game);
void	render_tile(t_game *game, int x, int y, void *sprite);

// Controles del jugador
int		handle_keypress(int keycode, t_game *game);
void	move_player(t_game *game, int x_offset, int y_offset);

// Enemigos
void	update_enemies(t_game *game);

// Finalización del juego
void	end_game(t_game *game, const char *message);

// Utilidades
void	free_map(char **map);
void	error_exit(const char *message);

#endif

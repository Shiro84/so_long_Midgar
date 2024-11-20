/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:14:42 by matomas           #+#    #+#             */
/*   Updated: 2024/11/20 17:38:01 by matomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	width, height;
	
	game->images = malloc(sizeof(t_images));
	game->images->player = mlx_xpm_file_to_image(game->mlx, PLAYER, &width, &height);
	game->images->wall = mlx_xpm_file_to_image(game->mlx, WALL, &width, &height);
	game->images->empty = mlx_xpm_file_to_image(game->mlx, EMPTY, &width, &height);
	game->images->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &width, &height);
	game->images->collect = mlx_xpm_file_to_image(game->mlx, COLLECT, &width, &height);
}

void	initialize_game(t_game *game, char *map_filename)
{
	game->mlx = mlx_init();
	game->map = load_map(map_filename);
	game->width = get_map_width(game->map);
	game->height = get_map_height(game->map);
	game->player_x = 0;
	game->player_y = 0;
	game->collect_count = 0;
	game->exit_reached = 0;
	game->step_count = 0;
	load_images(game);
	validate_map(game);
}

void validate_map(t_game *game)
{
    check_outline(game);
    check_format(game);
    check_map_objects(game);
    check_map_is_possible(game);
}

int handle_key(int key, t_game *game)
{
    if (key == KEY_EXIT)
    {
        exit_game(game);  // Función para salir del juego
    }
    if (key == KEY_LEFT)
    {
        move_player_left(game);
    }
    if (key == KEY_RIGHT)
    {
        move_player_right(game);
    }
    if (key == KEY_UP)
    {
        move_player_up(game);
    }
    if (key == KEY_DOWN)
    {
        move_player_down(game);
    }
    return 0;
}

int game_frame(t_game *game)
{
    mlx_clear_window(game->mlx, game->win);
    draw_map(game);  // Dibuja el mapa actualizado
    if (game->exit_reached && game->player_x == game->exit_x && game->player_y == game->exit_y)
    {
        display_victory(game);  // Mostrar mensaje de victoria
    }
    return 0;
}

void clean_up(t_game *game)
{
    free(game->map);  // Liberar el mapa
    free(game->images);  // Liberar las imágenes cargadas
    mlx_destroy_window(game->mlx, game->win);  // Cerrar la ventana
}

int main(int argc, char **argv)
{
    t_game game;

    if (argc == 2)
    {
        initialize_game(&game, argv[1]);  // Inicializar el juego
        game.win = mlx_new_window(game.mlx, game.width * TILE_SIZE, game.height * TILE_SIZE, "So Long");
        mlx_hook(game.win, 17, 0, ft_exit, &game);  // Manejar el cierre de la ventana
        mlx_hook(game.win, 2, 0, handle_key, &game);  // Manejar teclas
        mlx_loop_hook(game.mlx, game_frame, &game);  // Actualizar el juego
        mlx_loop(game.mlx);  // Iniciar el loop de MiniLibX
        clean_up(&game);  // Limpiar antes de salir
    }
    return 0;
}

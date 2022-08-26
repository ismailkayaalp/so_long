/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayaalp <ikayaalp@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:25:23 by ikayaalp          #+#    #+#             */
/*   Updated: 2022/08/11 21:25:23 by ikayaalp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	keypress(int keycode, t_game *solong)
{
	if (keycode == KEY_ESC)
		exit_game(solong);
	else if (keycode == KEY_A || keycode == KEY_D
		|| keycode == KEY_S || keycode == KEY_W)
	{
		game_events(keycode, solong);
		printf("Moves: %d\n", solong->moves);
	}
	return (0);
}

void	game_events(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->y_player -= 1;
		player_w(game);
	}
	else if (keycode == KEY_S)
	{
		game->y_player += 1;
		player_s(game);
	}
	else if (keycode == KEY_D)
	{
		game->x_player += 1;
		player_d(game);
	}
	else if (keycode == KEY_A)
	{
		game->x_player -= 1;
		player_a(game);
	}
}

void	gameplay(t_game *solong)
{
	mlx_hook(solong->window, 2, 0, keypress, solong);
	mlx_hook(solong->window, 17, 0, exit_game, solong);
}

int	exit_game(t_game *solong)
{
	free_map(solong->map);
	mlx_destroy_image(solong->mlx, solong->img_floor);
	mlx_destroy_image(solong->mlx, solong->img_wall);
	mlx_destroy_image(solong->mlx, solong->img_player);
	mlx_destroy_image(solong->mlx, solong->img_coin);
	mlx_destroy_image(solong->mlx, solong->img_exit);
	mlx_destroy_window(solong->mlx, solong->window);
	free(solong->mlx);
	exit(0);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

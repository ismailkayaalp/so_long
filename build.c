/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayaalp <ikayaalp@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:24:24 by ikayaalp          #+#    #+#             */
/*   Updated: 2022/08/11 21:24:24 by ikayaalp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	img_draw(t_game *solong, void *image, int x, int y)
{
	mlx_put_image_to_window(solong->mlx, solong->window, image, x * 64, y * 64);
}

void	player_draw(t_game *solong, void *image, int x, int y)
{
	solong->x_player = x;
	solong->y_player = y;
	img_draw(solong, image, x, y);
}

int	map_draw(t_game *solong)
{
	int	y;
	int	x;

	y = 0;
	while (solong->map[y])
	{
		x = 0;
		while (solong->map[y][x])
		{
			if (solong->map[y][x] == '1')
				img_draw(solong, solong->img_wall, x, y);
			else if (solong->map[y][x] == '0')
				img_draw(solong, solong->img_floor, x, y);
			else if (solong->map[y][x] == 'P')
				player_draw(solong, solong->img_player, x, y);
			else if (solong->map[y][x] == 'C')
				img_draw(solong, solong->img_coin, x, y);
			else if (solong->map[y][x] == 'E')
				img_draw(solong, solong->img_exit, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

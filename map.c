/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayaalp <ikayaalp@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:25:11 by ikayaalp          #+#    #+#             */
/*   Updated: 2022/08/11 21:25:11 by ikayaalp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"solong.h"

int	map_check(t_game *solong)
{
	if (line_len_check(solong->map) && wall_check(solong->map)
		&& char_check(solong) && is_char_check(solong->map))
		return (1);
	return (0);
}

int	line_len_check(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (exprintf("ERROR!!!\nMap uzunlukları eşit değil\n"));
		i++;
	}
	return (1);
}

int	wall_check(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (map[i] != NULL)
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (exprintf("ERROR!!!\nMap'in duvarlarında açıklık var\n"));
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (exprintf("ERROR!!!\nMap'in duvarlarında açıklık var\n"));
		i++;
	}
	return (1);
}

int	char_check(t_game *solong)
{
	int	i;
	int	j;

	i = 0;
	while (solong->map[i] != NULL)
	{
		j = 0;
		while (solong->map[i][j] != '\0')
		{
			if (solong->map[i][j] == 'P')
				solong->player++;
			else if (solong->map[i][j] == 'E')
				solong->exit++;
			else if (solong->map[i][j] == 'C')
				solong->coin++;
			j++;
		}
		i++;
	}
	if (solong->player != 1 || solong->exit == 0 || solong->coin == 0)
	{
		printf("ERROR!!!\nHaritadaki karakter sayısı yanlış\n");
		return (0);
	}
	return (1);
}

int	is_char_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1')
			{
				printf("ERROR!!!\nHaritada geçersiz karakter var\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

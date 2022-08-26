/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayaalp <ikayaalp@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:24:51 by ikayaalp          #+#    #+#             */
/*   Updated: 2022/08/11 21:24:51 by ikayaalp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"solong.h"

int	argv_check(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b'
		&& argv[i - 3] == '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	solong;

	if (argc == 2)
	{	
		solong.coin = 0;
		solong.player = 0;
		solong.exit = 0;
		solong.map = read_map(argv[1]);
		if (map_check(&solong) && argv_check(argv[1]))
		{
			game_init(&solong);
			gameplay(&solong);
			mlx_loop(solong.mlx);
		}
	}
	else
		printf("ERROR!!!\n2 adet argüman girmelisiniz!!!\n");
}

char	**read_map(char *path)
{
	int		fd;
	char	*line;
	char	*holder;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	holder = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = ft_strjoin(holder, line);
		free(line);
	}
	map = ft_split(holder, '\n');
	free(holder);
	close(fd);
	return (map);
}

int	exprintf(char *s)
{
	printf("%s", s);
	return (0);
}

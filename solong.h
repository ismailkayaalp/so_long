/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayaalp <ikayaalp@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:25:40 by ikayaalp          #+#    #+#             */
/*   Updated: 2022/08/11 21:25:40 by ikayaalp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# include"minilibx/mlx.h"
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>
# include<string.h>

typedef struct solong
{
	void	*mlx;
	void	*window;
	char	**map;
	int		x_player;
	int		y_player;
	int		size_x;
	int		size_y;
	int		player;
	int		coin;
	int		exit;
	int		moves;
	int		bos;
	void	*img_player;
	void	*img_wall;
	void	*img_floor;
	void	*img_coin;
	void	*img_exit;
}	t_game;

void	free_map(char **map);
void	gameplay(t_game *solong);
void	game_init(t_game *solong);
void	ft_window_size(t_game *solong);
void	player_w(t_game *game);
void	player_s(t_game *game);
void	player_d(t_game *game);
void	player_a(t_game *game);
void	game_events(int keycode, t_game *game);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);
char	*ft_itoa(int n);
char	*get_next_line(int fd);
char	*ft_read_to_left_str(int fd, char *left_str);
char	*ft_strdup(const char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
char	**ft_split(char const *s, char c);
char	**read_map(char *path);
int		map_draw(t_game *solong);
int		exprintf(char *s);
int		is_char_check(char **map);
int		char_check(t_game *solong);
int		wall_check(char **map);
int		map_check(t_game *solong);
int		line_len_check(char **map);
int		exit_game(t_game *solong);
size_t	ft_strlen(const char *s);

#endif

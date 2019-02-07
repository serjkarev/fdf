/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:06:50 by skarev            #+#    #+#             */
/*   Updated: 2019/01/31 19:06:50 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <math.h>

# define WIN_SIZE_X 1000
# define WIN_SIZE_Y 1000

# define USAGE "[ Usage ] : ./fdf exemple_map.fdf"
# define ER01 "Bad input\n"
# define ER02 "Invalid coordinates\n"
# define ER03 "Not uniform map width\n"
# define ER04 "Memory allocation failed\n"

# define ABS(n) (n >= 0 ? n : (n * -1))

typedef struct		s_d
{
	int				dx;
	int				dy;
	double			drx;
	double			dry;
	double			drz;
	double			ds;
	int				help;
}					t_d;

typedef struct		s_e
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_e		*next;
	struct s_e		*tail;
}					t_e;

typedef struct		s_m
{
	int				width;
	int				length;
	int				curr_pos;
	t_e				*elem;
	int				**array;
	int				arr_len;
	void			*ptr;
	void			*window;
	int				scale;
	struct s_d		*delta;
	int				project;
}					t_m;

void	parce(int fd, t_m *map);
void	valid(t_m *map, char *str, int flag);
void	ft_error(char *er_str, char *str, char **arr);
int		check_point(t_m *map, char *point);
void	init_map(t_m *map);
void	create_elem(t_m *map, char *point);
void	create_color_elem(t_m *map, char *point);
void	in_to_int_array(t_m *map);
void	draw(t_m *map);
void	brazenhaime(int x1, int y1, int x2, int y2, t_m *map);
void	scale_calc(t_m *map);

void	controls(t_m *map);
int		keypress(int key, void *param);
// int		close(void *param);
void	xyz_moving(int key, t_m *map);
void	rotating(int key, t_m *map);
void	z_change(int key, t_m *map);
// void	choose_projection(int key,  t_m *map);




#endif
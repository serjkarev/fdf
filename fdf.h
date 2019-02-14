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

# define WIN_SIZE_X 1920
# define WIN_SIZE_Y 1080

# define USAGE "[ Usage ] : ./fdf exemple_map.fdf"
# define ER01 "Bad input\n"
# define ER02 "Invalid coordinates\n"
# define ER03 "Not uniform map width\n"
# define ER04 "Memory allocation failed\n"

# define ABS(n) (n >= 0 ? n : (n * -1))
# define roundf(x) floor(x + 0.5f)

typedef struct		s_b
{
	int				dx;
	int				dy;
	int				lengthX;
	int				lengthY;
	int				length;
	int				color;
}					t_b;

typedef struct		s_d
{
	int				dx;
	int				dy;
	float			dz;
	double			drx;
	double			dry;
	double			drz;
	int				ds;
	int				help;
	int				dc;
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
	void			*img;
	char			*data_adr;
	int				bit_per_pix;
	int				line_size;
	int				endian;
	int				custom_color;
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

void	brazenhaime(int *point1, int *point2, t_m *map, int color);
void	init_braz(t_b *braz, int *point1, int *point2, int color);
void	braz_helper(t_m *map, t_b *braz, int *point1, int flag);
int		*change(int x, int y, int z, t_m *map);

void	controls(t_m *map);
int		keypress(int key, void *param);
void	xy_moving(int key, t_m *map);
void	rotating(int key, t_m *map);
void	z_change(int key, t_m *map);
void	choose_projection(int key,  t_m *map);
void	scaling(int key, t_m *map);
void	help_switch(t_m *map);

int		*rot_x(int *point, t_m *map);
int		*rot_y(int *point, t_m *map);
int		*rot_z(int *point, t_m *map);
int		*isometric(int *point);

void	print_help_menu(t_m *map);
void	change_color(t_m *map);

void	pixel_put(t_m *map, int x, int y, int color);

#endif
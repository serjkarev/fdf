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

# define USAGE "\x1b[32m[ Usage ] : ./fdf exemple_map.fdf \033[0m\n"
# define ER01 "\x1B[31m[ ERROR ] : Bad input \033[0m\n"
# define ER02 "\x1B[31m[ ERROR ] : Invalid coordinates \033[0m\n"
# define ER03 "\x1B[31m[ ERROR ] : Not uniform map width \033[0m\n"
# define ER04 "\x1B[31m[ ERROR ] : Memory allocation failed \033[0m\n"
# define ER05 "\x1B[31m[ ERROR ] : Invalid color \033[0m\n"
# define ER06 "\x1B[31m[ ERROR ] : Not enough input or empty file \033[0m\n"

typedef struct	s_b
{
	int			dx;
	int			dy;
	int			lengthx;
	int			lengthy;
	int			length;
	int			color;
}				t_b;

typedef struct	s_d
{
	int			dx;
	int			dy;
	float		dz;
	double		drx;
	double		dry;
	double		drz;
	int			ds;
	int			help;
	int			dc;
	int			sound;
}				t_d;

typedef struct	s_e
{
	int			x;
	int			y;
	int			z;
	int			color;
	struct s_e	*next;
	struct s_e	*tail;
}				t_e;

typedef struct	s_m
{
	int			width;
	int			length;
	int			curr_pos;
	t_e			*elem;
	int			**array;
	int			arr_len;
	void		*ptr;
	void		*window;
	void		*img;
	char		*data_adr;
	int			bit_per_pix;
	int			line_size;
	int			endian;
	int			custom_color;
	struct s_d	*delta;
	int			project;
	int			special;
}				t_m;

void			parce(int fd, t_m *map);
void			valid(t_m *map, char *str, int flag);
void			ft_error(char *er_str, char *str, char **arr);
int				check_point(t_m *map, char *point);
void			init_map(t_m *map, char *av);
void			create_elem(t_m *map, char *point);
void			create_color_elem(t_m *map, char *point);
void			atoi_color_and_z(char *point, char **arr, t_e *elem);
void			in_to_int_array(t_m *map);
void			draw(t_m *map);
void			brazenhaime(int *point1, int *point2, t_m *map, int color);
void			init_braz(t_b *braz, int *point1, int *point2, int color);
void			braz_helper(t_m *map, t_b *braz, int *point1, int flag);
int				*change(int x, int y, int z, t_m *map);
int				keypress(int key, void *param);
void			xy_moving(int key, t_m *map);
void			rotating(int key, t_m *map);
void			z_change(int key, t_m *map);
void			choose_projection(int key, t_m *map);
void			scaling(int key, t_m *map);
void			help_switch(t_m *map);
int				*rot_x(int *point, t_m *map);
int				*rot_y(int *point, t_m *map);
int				*rot_z(int *point, t_m *map);
int				*isometric(int *point);
void			sound(int key, t_m *map);
void			rotating_2(int key, t_m *map);
void			print_help_menu(void *ptr, void *window);
void			change_color(t_m *map);
void			pixel_put(t_m *map, int x, int y, int color);
int				close_icon(void *param);
int				lgnl(int fd, char **line);
void			free_arr(char **arr);
void			escape(t_m *map);

#endif

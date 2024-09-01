/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:26:38 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/26 11:18:50 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define KEY_ESC 53
# define KEY_R 15
# define ITER_MAX 1000
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define MANDEL 1
# define JULIA 2
# define DESTROYMASK 17

typedef struct s_img{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}	t_img;

typedef struct s_var
{
	double	c_re;
	double	c_im;
	double	scale;
	double	real_min;
	double	image_min;
	double	x;
	double	y;
	double	width;
	double	height;
	int		location_x;
	int		location_y;
	int		map;
	int		(*set)(double, double, struct s_var *self);
}	t_var;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	t_img	img;
	t_var	var;
}	t_mlx;

size_t	ft_strlen(const char *s);
void	put_pixel(t_img *img, t_var *var, int (*set)());
void	init_var(t_var *var);
void	zoom_in(t_var *var, double width, double height);
void	zoom_out(t_var *var, double width, double height);
void	print_argument(void);
void	input_check(int argc, char **argv, t_var *var);
int		press_winx(t_mlx *mlx);
int		mandelbrot(double width, double height, t_var *var);
int		julia(double width, double height, t_var *var);
int		set_color(int iter);
int		close_win(int keycode, t_mlx *mlx);
int		before_putimg(t_mlx *mlx);
int		zoom(int code, int x, int y, t_mlx *mlx);
int		set_hook(t_mlx *mlx);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		main(int argc, char **argv);
#endif

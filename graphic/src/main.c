/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:22:42 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/26 11:13:18 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_var(t_var *var)
{
	var->scale = 4.0;
	var->real_min = -2.0;
	var->image_min = -2.0;
	var->x = 0;
	var->y = 0;
	var->width = 0;
	var->height = 0;
	var->location_x = 0;
	var->location_y = 0;
}

int	before_putimg(t_mlx *mlx)
{
	mlx->init = mlx_init();
	if (!mlx->init)
		return (0);
	mlx->win = mlx_new_window(mlx->init, WIN_WIDTH, WIN_HEIGHT, "fractol");
	if (!mlx->win)
		return (0);
	mlx->img.ptr = mlx_new_image(mlx->init, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img.ptr)
		return (0);
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp, \
			&mlx->img.length, &mlx->img.endian);
	if (!mlx->img.addr)
		return (0);
	return (1);
}

void	print_argument(void)
{
	write(2, "can use next argument\n", 22);
	write(2, "m - mandelbrot\n", 15);
	write(2, "j - julia\n", 10);
	write(2, "j - julia [double] [double]\n", 28);
	write(2, "ex) ./fractol m\n", 16);
	write(2, "ex) ./fractol julia 0.375 0.5\n", 30);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	init_var(&mlx.var);
	input_check(argc, argv, &mlx.var);
	if (!before_putimg(&mlx))
		return (1);
	put_pixel(&mlx.img, &mlx.var, mlx.var.set);
	mlx_put_image_to_window(mlx.init, mlx.win, mlx.img.ptr, 0, 0);
	set_hook(&mlx);
	mlx_loop(mlx.init);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:37:55 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/24 15:36:57 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	zoom_in(t_var *var, double width, double height)
{
	var->real_min += 0.25 * (width / WIN_WIDTH * var->scale);
	var->image_min += 0.25 * (height / WIN_HEIGHT * var->scale);
	var->scale *= 0.75;
}

void	zoom_out(t_var *var, double width, double height)
{
	var->real_min -= (1.0 / 3.0) * (width / WIN_WIDTH * var->scale);
	var->image_min -= (1.0 / 3.0) * (height / WIN_HEIGHT * var->scale);
	var->scale *= (4.0 / 3.0);
}

int	zoom(int code, int x, int y, t_mlx *mlx)
{
	if (code == SCROLL_UP)
	{
		mlx_mouse_get_pos(mlx->win, &mlx->var.location_x, &mlx->var.location_y);
		zoom_in(&mlx->var, mlx->var.location_x, mlx->var.location_y);
		put_pixel(&mlx->img, &mlx->var, mlx->var.set);
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->img.ptr, 0, 0);
	}
	else if (code == SCROLL_DOWN)
	{
		if (mlx->var.scale == 1)
			return (0);
		mlx_mouse_get_pos(mlx->win, &mlx->var.location_x, &mlx->var.location_y);
		zoom_out(&mlx->var, mlx->var.location_x, mlx->var.location_y);
		put_pixel(&mlx->img, &mlx->var, mlx->var.set);
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->img.ptr, 0, 0);
	}
	return (x + y);
}

int	close_win(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx->init, mlx->win);
		exit(0);
	}
	if (keycode == KEY_R)
	{
		init_var(&mlx->var);
		put_pixel(&mlx->img, &mlx->var, mlx->var.set);
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->img.ptr, 0, 0);
	}
	return (0);
}

int	set_hook(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, close_win, mlx);
	mlx_mouse_hook(mlx->win, zoom, mlx);
	mlx_hook(mlx->win, DESTROYMASK, 0, press_winx, mlx);
	return (1);
}

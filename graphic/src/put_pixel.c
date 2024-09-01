/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:41:15 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/24 15:27:12 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	mandelbrot(double width, double height, t_var *var)
{
	int		iter;
	double	temp;

	var->c_re = ((width / (double)WIN_WIDTH * var->scale) + var->real_min);
	var->c_im = ((height / (double)WIN_HEIGHT * var->scale) + var->image_min);
	var->x = 0;
	var->y = 0;
	iter = 0;
	while ((var->x * var->x) + (var->y * var->y) < 4 \
		&& (iter < ITER_MAX))
	{
		temp = (var->x * var->x) - (var->y * var->y) + var->c_re;
		var->y = 2.0 * var->x * var->y + var->c_im;
		var->x = temp;
		iter++;
	}
	return (iter);
}

int	julia(double width, double height, t_var *var)
{
	int		iter;
	double	temp;

	var->x = -(((double)width / (double)WIN_WIDTH * var->scale) + \
		var->real_min);
	var->y = (((double)height / (double)WIN_HEIGHT * var->scale) + \
		var->image_min);
	iter = 0;
	while ((var->x * var->x) + (var->y * var->y) < 4 \
		&& (iter < ITER_MAX))
	{
		temp = (var->x * var->x) - (var->y * var->y) + var->c_re;
		var->y = 2.0 * var->x * var->y + var->c_im;
		var->x = temp;
		iter++;
	}
	return (iter);
}

int	set_color(int iter)
{
	double	r;
	double	g;
	double	b;
	int		color;

	r = 3.0 * iter;
	g = 3.0 * iter;
	b = 3.0 * iter;
	color = ((int)r << 16) + ((int)g << 8) + ((int)b);
	color = color & 0x00FFFFFF;
	return (color);
}

void	put_pixel(t_img *img, t_var *var, int (*set)(double, double, t_var *))
{
	int		iter;
	int		width;
	int		height;
	int		color;
	char	*dst;

	height = -1;
	while (++height <= WIN_HEIGHT)
	{
		width = -1;
		while (++width <= WIN_WIDTH)
		{
			iter = set(width, height, var);
			color = set_color(iter);
			dst = img->addr + (width * img->bpp / 8) + (height * img->length);
			*(unsigned int *)dst = color;
		}
	}
}

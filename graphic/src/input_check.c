/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:26:01 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/26 11:08:54 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

char	check_sign(char c)
{
	if (c == '-')
		return ('-');
	else if (c == '+' || (c >= '0' && c <= '9') || c == '.')
		return ('+');
	return ('\0');
}

double	ft_strtod(const char *str)
{
	long	frac;
	double	dec;
	size_t	index;

	frac = 0;
	index = 0;
	while (str[index] && str[index] != '.')
	{
		if (str[index] >= '0' && str[index] <= '9')
			frac = frac * 10 + (str[index] - '0');
		index++;
	}
	if (str[index] == '.')
		index++;
	else
		return (frac);
	dec = 0;
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			frac = frac * 10 + (str[index] - '0');
		index++;
		dec++;
	}
	return (frac * pow(0.1, dec));
}

double	ft_atod(const char *str)
{
	char	sign;
	double	number;
	size_t	index;

	index = 0;
	sign = check_sign(str[index]);
	if (!sign)
		return (0);
	if (str[index] == '+' || str[index] == '-')
		index++;
	number = ft_strtod(&str[index]);
	if (number > 2)
		number = 2.0;
	if (sign == '-')
		number *= -1;
	return (number);
}

int	is_double(char *str)
{
	size_t	index;
	char	sign;

	index = 0;
	sign = check_sign(str[index]);
	if (!sign)
		return (0);
	if (str[index] == '+' || str[index] == '-')
		index++;
	while (str[index] && str[index] != '.')
	{
		if (!(str[index] >= '0' && str[index] <= '9'))
			return (0);
		index++;
	}
	if (str[index] == '.')
		index++;
	while (str[index])
	{
		if (!(str[index] >= '0' && str[index] <= '9'))
			return (0);
		index++;
	}
	return (1);
}

void	input_check(int argc, char **argv, t_var *var)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])))
		var->set = &mandelbrot;
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) \
	&& (is_double(argv[2]) && is_double(argv[3])))
	{
		var->set = &julia;
		var->c_re = ft_atod(argv[2]);
		var->c_im = ft_atod(argv[3]);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "julia", ft_strlen(argv[1])))
	{
		var->set = &julia;
		var->c_re = -0.835;
		var->c_im = -0.232;
	}
	else
		print_argument();
}

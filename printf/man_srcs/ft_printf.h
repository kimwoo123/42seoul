/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:41:02 by wooseoki          #+#    #+#             */
/*   Updated: 2022/12/05 11:33:13 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

void	pr_char(char c, int *count);
void	pr_str(char *str, int *count);
void	pr_ptr(void *ptr, int *count);
void	pr_num(int number, int *count);
void	pr_unum(unsigned int number, int *count);
void	pr_hex(unsigned int number, int *count, char format);
void	num_to_hex(unsigned long num, char *hex_base, int *count);
void	int_to_hex(unsigned int number, int *count, char *hex_base);
void	print_string(va_list ap, const char *string, int *count);
int		ft_printf(const	char *format, ...);
int		convert_format(va_list ap, char format, int *count);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wada-sil <wada-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:38:01 by wada-sil          #+#    #+#             */
/*   Updated: 2024/06/13 18:42:14 by wada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define BASE10 "0123456789"
# define BASE16L "0123456789abcdef"
# define BASE16U "0123456789ABCDEF"

typedef unsigned int	t_unit;
int						ft_putstr(const char *s, int c, char format);
int						ft_putall(unsigned long long n, char format,
							char *base);
int						ft_printf(const char *format, ...);
int						ft_check_type(char format, va_list *args);

#endif

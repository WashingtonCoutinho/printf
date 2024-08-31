/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wada-sil <wada-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:37:24 by wada-sil          #+#    #+#             */
/*   Updated: 2024/08/31 16:23:12 by wada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrbase(unsigned long long n, char *base)
{
	int					count;
	unsigned long long	baselen;

	baselen = 10;
	if (base[10] != '\0')
		baselen = 16;
	count = 0;
	if (n >= baselen)
		count = ft_putnbrbase(n / baselen, base);
	return (count + write(1, &base[n % baselen], 1));
}

int	ft_putptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_putnbrbase(ptr, BASE16L);
	return (count);
}

int	ft_putstr(const char *s, int c, char fmt)
{
	int	result;

	result = 0;
	if (fmt == 'c')
		return (write(1, &c, 1));
	if (!s && fmt == 's')
		return (write(1, "(null)", 6));
	while (*s && fmt == 's')
		result += write(1, s++, 1);
	return (result);
}

int	ft_check_type(char fmt, va_list *args)
{
	long	n;

	if (fmt == 'c')
		return (ft_putstr(NULL, va_arg(*args, int), fmt));
	if (fmt == 's')
		return (ft_putstr(va_arg(*args, char *), 0, fmt));
	if (fmt == 'x')
		return (ft_putnbrbase(va_arg(*args, t_unit), BASE16L));
	if (fmt == 'X')
		return (ft_putnbrbase(va_arg(*args, t_unit), BASE16U));
	if (fmt == 'u')
		return (ft_putnbrbase(va_arg(*args, t_unit), BASE10));
	if (fmt == 'p')
		return (ft_putptr((unsigned long long)va_arg(*args, void *)));
	if (fmt == 'd' || fmt == 'i')
	{
		n = va_arg(*args, int);
		if (n < 0)
			return (write(1, "-", 1) + ft_putnbrbase(-n, BASE10));
		return (ft_putnbrbase(n, BASE10));
	}
	if (fmt == '%')
		return (write(1, "%", 1));
	return (write(1, "%", 1) + write(1, &fmt, 1));
}

int	ft_printf(const char *fmt, ...)
{
	int		result;
	va_list	args;

	result = 0;
	if (!fmt)
		return (-1);
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
		{
			fmt++;
			result += ft_check_type((*fmt), &args);
		}
		else
			result += write(1, fmt, 1);
		fmt++;
	}
	va_end(args);
	return (result);
}

/* int	main(void)arguments, str);
	while (str[i])
	{
		if (s
{
	ft_printf("Testes P: %p\n", -1);
	ft_printf("Testes P: %p\n", 16);
	ft_printf("Testes P: %p\n", 17);
	ft_printf("Testes P: Min %p Max %p\n", LONG_MIN, LONG_MAX);
	ft_printf("Testes P: Min %p Max %p\n", INT_MIN, INT_MAX);
	ft_printf("Testes P: Min %p Max %p\n", ULONG_MAX, ULLONG_MAX);
	printf("Original\n\n");
	printf("Testes P: %p\n", -1);
	printf("Testes P: %p\n", 16);
	printf("Testes P: %p\n", 17);
	printf("Testes P: Min %p Max %p\n", LONG_MIN, LONG_MAX);
	printf("Testes P: Min %p Max %p\n", INT_MIN, INT_MAX);
	printf("Testes P: Min %p Max %p\n", ULONG_MAX, ULLONG_MAX);
	// int	*ptr;

	// printf("Expected:   Character: A\n");
	// printf("Result:     %d\n", ft_printf("Character: %c\n", 'A'));
	// printf("Expected:   String: Hello, World!\n");
	// printf("Result:     %d\n", ft_printf("String: %s\n", "Hello, World!"));
	// printf("Expected:   Hexadecimal (lowercase): ff\n");
	// printf("Result:     %d\n", ft_printf("Hex (lowercase): %x\n", 255));
	// printf("Expected:   Hexadecimal (uppercase): FF\n");
	// printf("Result:     %d\n", ft_printf("Hex (uppercase): %X\n", 255));
	// printf("Expected:   Unsigned Integer: 3000000000\n");
	// printf("Result:     %d\n", ft_printf("Unsigned Integer: %u\n",
	// 		3000000000U));
	// ptr = (int *)0x12345678;
	// printf("Expected:   Pointer Address: 0x12345678\n");
	// printf("Result:     %d\n", ft_printf("Pointer Address: %p\n", ptr));
	// printf("Expected:   Signed Integer: -12345\n");
	// printf("Result:     %d\n", ft_printf("Signed Integer: %d\n", -12345));
	// printf("Expected:   Signed Integer (i): 6789\n");
	// printf("Result:     %d\n", ft_printf("Signed Integer (i): %i\n", 6789));
	// printf("Expected:   Percent Sign: %%\n");
	// printf("Result:     %d\n", ft_printf("Percent Sign: %%\n"));
	// return (0);
} */

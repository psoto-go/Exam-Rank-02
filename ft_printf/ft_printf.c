/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:56:11 by psoto-go          #+#    #+#             */
/*   Updated: 2021/12/02 17:21:57 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

void	ft_putchar(int c, int *res)
{
	*res = *res + 1;
	write(1, &c, 1);
}

void	ft_write(char *str, int *res)
{
	char 	*aux;
	int		i;

	i = 0;
	if (str == NULL)
		aux = "(null)";
	else
		aux = str;
	while (aux[i])
	{
		write(1, &aux[i], 1);
		i++;
		*res = *res + 1;
	}
}

void	ft_putnbr_base(long long int num, int *res, char *base, long long int n)
{
	if (num < 0)
	{
		num = num * -1;
		ft_putchar('-', res);
	}
	if (num >= n)
	{
		ft_putnbr_base(num / n, res, base, n);
	}
	ft_putchar(base[num % n], res);
}

void	ft_putnbr_basex(long long int num, int *res, char *base, long long int n)
{
	if (num >= n)
	{
		ft_putnbr_base(num / n, res, base, n);
	}
	ft_putchar(base[num % n], res);
}

int		checker(char c, char c1, va_list args)
{
	int res;

	res = 0;
	if (c == '%' && c1 == 's')
		ft_write(va_arg(args, char *), &res);
	if (c == '%' && c1 == 'd')
		ft_putnbr_base(va_arg(args, int), &res, "0123456789", 10);
	if (c == '%' && c1 == 'x')
		ft_putnbr_basex(va_arg(args, unsigned int), &res, "0123456789abcdef", 16);
	return(res);
}

int		ft_printf(const char *var, ... )
{
	va_list args;
	int 	res;
	int 	i;

	va_start(args, var);
	res = 0;
	i = 0;
	while (var[i])
	{
		if(var[i] == '%')
		{
			res += checker(var[i], var[i + 1], args);
			i++;
		}
		else
			ft_putchar(var[i], &res);
		i++;
	}
	va_end(args);
	return (res);
}

// int 	main()
// {
// 	int a;

// 	a = ft_printf("%s %d %x\n", "hola", 1221, -123123);
// 	printf("%s %d %x\n", "hola", 1221, -123123);
// 	printf("%s %d %x\n", "hola", 1221, 123123);

// 	// ft_printf("%s %d", "hola", 1221);
// 	ft_printf("%d\n", a);
// 	printf("%d\n", a);
// }
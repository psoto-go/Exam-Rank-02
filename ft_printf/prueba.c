/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:17:41 by psoto-go          #+#    #+#             */
/*   Updated: 2021/12/01 12:37:09 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (!str)
		aux = "(null)";
	else
		aux = str;
	while (str[i])
	{
		ft_putchar(str[i],res);
		i++;
	}
}

void	ft_putnbr(int long long num, int *res, char *base, int n)
{
	if (num < 0)
	{
		num *= -1;
		ft_putchar('-', res);
	}
	if (num >= n)
		ft_putnbr(num / n, res, base, n);
	ft_putchar(base[num % n], res);

}

void	ft_putnbrx(int long long num, int *res, char *base, int n)
{
	if (num >= n)
		ft_putnbr(num / n, res, base, n);
	ft_putchar(base[num % n], res);

}



int		checker(char c, char c1, va_list args)
{
	int		res;

	res = 0;
	if (c == '%' && c1 == 's')
		ft_write(va_arg(args, char *), &res);
	if (c == '%' && c1 == 'd')
		ft_putnbr(va_arg(args, int), &res, "0123456789", 10);
	if (c == '%' && c1 == 'x')
		ft_putnbr(va_arg(args, unsigned int), &res, "0123456789abcdef", 16);
	return (res);
}

int 	ft_printf(const char *var, ... )
{
	va_list args;
	int		res;
	int 	i;

	va_start(args, var);
	i = 0;
	res = 0;
	while (var[i])
	{
		if (var[i] == '%')
		{
			res += checker(var[i], var[i + 1], args);
			i++;
		}
		else
			ft_putchar(var[i], &res);
		i++;
	}

	va_end(args);
	return(res);
}

int 	main()
{
	int a = 0;
	int b = 0;
	a = ft_printf("%s %d %x %d %x\n", "hola soy pablo", 223423423123, 223423423123, -223423423123, -223423423123);
	b = printf("%s %d %x %d %x\n", "hola soy pablo", 223423423123, 223423423123, -223423423123, -223423423123);
	printf("%d  %d", a, b);
}
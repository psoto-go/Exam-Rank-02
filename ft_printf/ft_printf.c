/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:17:33 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/25 14:15:56 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void    ft_putchar(char c, int *res)
{
    *res = *res + 1;
    write(1, &c, 1);
}

void    ft_putnbr(int num, int *res)
{
    if(num > -2147483648 && num <= 2147483647)
    {
        if (num == -2147483648)
        {
            ft_putchar('-', res);
            ft_putchar('2', res);
            ft_putnbr(147483648, res);
        }
        else if (num >= 10)
        {
            ft_putnbr(num / 10, res);
            ft_putnbr(num % 10, res);

        }
        else if (num < 0)
        {
            num = -num;
            ft_putnbr(num / 10, res);
            ft_putnbr(num % 10, res);
        }
        else
            ft_putchar(num + '0', res);
    }
}

void ft_write(char *str, int *res)
{
    char *aux;
    int i;

    i = 0;
    if (str == NULL){
        aux = "(null)";
    }else
        aux = str;
    while (aux[i])
    {
        write(1, &aux[i], 1);
		i++;
		*res += 1;
    }
}

char    *ft_detohe(unsigned long int num)
{
    int     len;
    int     co;
    int     aux;
    char	*string;
    int     i;

    aux = num;
    len = 1;
    while (aux >= 16)
    {
        co = aux / 16;
        aux = co;
        len++;
    }
    string = malloc(sizeof(char) * (len + 1));
    if (!string)
        return(0);
    if (num == 0)
        string[len - 1] = '0';
    i = len - 1;
    co = 0;
    while (num != 0){
        co = num % 16;
        if (co < 10)
			co += 48;
		else if (co >= 10)
			co += 87;
        string[i--] = co;
		num /= 16;
    }
    string[len] = '\0';
	return (string);
    
}

int checker(char c, char c1, va_list args)
{
    int res;

    res = 0;
    if (c == '%' && c1 == 's')
        ft_write(va_arg(args, char *), &res);
    if (c == '%' && c1 == 'd')
        ft_putnbr(va_arg(args, int), &res);
    if (c == '%' && c1 == 'x')
        ft_write(ft_detohe(va_arg(args, unsigned int)), &res);
    return (res);
}

int ft_printf(const char *var, ...)
{
    va_list args;
    int i;
    int res;

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
        {
            ft_putchar(var[i], &res);
        }
        i++;
    }
    va_end(args);
    return (res);
}
int main()
{
    int i = 0;
    int j = 0;
    i =  printf("Hexadecimal for %d is %x\n", 42, 42);
    j =  ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    printf("%d suyo %d\n", i, j);
    ft_printf("%d suyo %d\n", i, j);

    ft_printf("%s\n", "toto");

    ft_printf("Magic %s is %d", "number", 42);

    ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}
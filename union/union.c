/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:11:47 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/25 12:04:19 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     checker(char *str, char c, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

void    ft_union(char *str1, char *str2)
{
    int i;
	int n;
	int flag;

    i = 0;
	n = 0;
	while (str1[i])
    {
        if (checker(str1, str1[i], i) == 0)
            ft_putchar(str1[i]);
        i++;
    }
    while (str2[n])
    {
        if(checker(str2, str2[n], n) == 0)
		{
			i = 0;
			flag = 0;
			while (str1[i])
			{
				if (str2[n] == str1[i])
				{
					flag = 1;
					break;
				}
				i++;
			}
			if (flag == 0)
				ft_putchar(str2[n]);
		}
		n++;
    }
    
}

int     main(int argc, char **argv)
{
    if (argc != 3)
        ft_putchar('\n');
    else
        ft_union(argv[1], argv[2]);
}

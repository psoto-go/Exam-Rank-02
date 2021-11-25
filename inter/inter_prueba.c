/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_prueba.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:55:27 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/25 11:10:51 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void     ft_putchar(char c)
{
    write(1, &c, 1);
}

int     check(char *str, char c, int index)
{
    int i;

    i = 0;
    while (i < index)
    {
        if(str[i] == c)
            return(1);
        i++;
    }
    return (0);
}

void    inter(char *str, char *str2)
{
    int i;
    int n;

    i = 0;
    while (str[i])
    {
        if(check(str, str[i], i) == 0)
        {
            n = 0;
            while (str2[n])
            {
                if(str[i] == str2[n])
                {
                    ft_putchar(str[i]);
                    break;
                }
                n++;
            }
        }
        i++;
    }
    
}

int     main(int argc, char **argv)
{
    if(argc != 3)
        ft_putchar('\n');
    else
        inter(argv[1], argv[2]);
}
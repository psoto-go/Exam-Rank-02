/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:23:07 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/22 15:33:25 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int	boolean(char *str, char c, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return(0);
}

int	main(int argc, char **argv)
{
	int i;
	int	n;

	n = 0;
	if(argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (boolean(argv[1], argv[1][i], i) == 0)
			{
				n = 0;
				while (argv[2][n])
				{
					if (argv[1][i] == argv[2][n])
					{
						ft_putchar(argv[1][i]);
						break ;
					}
					n++;
				}
			}
			i++;
		}
	}
	else
		ft_putchar('\n');
	return(0);
}
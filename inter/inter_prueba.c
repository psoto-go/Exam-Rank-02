/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_prueba.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:47:30 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/30 13:27:58 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int 	repes(char *str1, char c, int len)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while(i < len)
	{
		if (str1[i] == c)
		{
			flag = 1;
			break;
		}
		i++;
	}
	return (flag);
}

void	checker(char *str1, char *str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str1[i])
	{
		if (repes(str1, str1[i], i) == 0)
		{
				j = 0;
			while(str2[j])
			{
				if(str1[i] == str2[j])
				{
					ft_putchar(str1[i]);
					break;
				}
				j++;
			}
		}
		i++;
	}
}

int 	main(int argc, char **argv)
{
	if(argc != 3)
		ft_putchar('\n');
	else
		checker(argv[1], argv[2]);
}
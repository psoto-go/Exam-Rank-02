/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_prueba.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:17:05 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/30 11:46:19 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int 	repes(char *str, char c, int index)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (i < index)
	{
		if (str[i] == c)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	return(flag);
}

void	checker(char *str1, char *str2)
{
	int i;
	int flag;
	int j;

	i = 0;
	while (str1[i])
	{
		if(!repes(str1, str1[i], i))
			ft_putchar(str1[i]);
		i++;

	}
	i = 0;
	while (str2[i])
	{
		if(!repes(str2, str2[i], i))
		{
			flag = 0;
			j = 0;
			while (str1[j])
			{
				if (str1[j] == str2[i])
				{
					flag = 1;
					break;
				}
				j++;
			}
			if (flag == 0)
				ft_putchar(str2[i]);
		}
		i++;

	}

}
int		main(int argc, char **argv)
{
	if(argc != 3)
		ft_putchar('\n');
	else
		checker(argv[1], argv[2]);


}
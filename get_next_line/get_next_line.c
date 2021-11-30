/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:23:09 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/30 15:45:34 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *str)
{
	size_t i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

char 	*ft_strdup(char *str)
{
	char 	*aux;
	size_t 	i;
	size_t 	count;

	i = ft_strlen(str);
	aux = malloc(sizeof(char) * (i + 1));
	if(!aux)
		return(NULL);
	count = 0;
	while(count < i)
	{
		aux[count] = str[count];
		count++;
	}
	return(aux);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int 	i;
	char	*tmp;
	size_t	len;
	size_t 	count;

	len = ft_strlen(str1) + ft_strlen(str2);
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return(0);
	count = 0;
	while (count < len && str1[count])
	{
		tmp[count] = str1[count];
		count++;
	}
	i = 0;
	while (count < len && str2[i])
	{
		tmp[count++] = str2[i++];
	}
	tmp[count] = '\0';
	free ((char *)str1);
	return(tmp);
}

int 	checker(char *static_buffer)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	if (!static_buffer)
		return(0);
	while (static_buffer[i] != '\0' && flag == 0)
	{
		if (static_buffer[i] == '\n')
		{
			flag = 1;
		}
		i++;
	}
	return (flag);
}

char	*only_line(char *static_buffer)
{
	int 	i;
	char	*aux;

	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
	{
		i++;
	}
	if(static_buffer[i] != '\n')
	{
		i++;
	}
	aux = malloc(sizeof(char) * (i + 1));
	if (!aux)
		return(NULL);
	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
	{
		aux[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
		aux[i++] = '\n';
	aux[i] = '\0';
	return(aux);
}

char	*increment_buffer(char *static_buffer)
{
	char	*aux;
	int 	i;
	int		len;
	int		j;

	i = 0;
	len = ft_strlen(static_buffer);
	j = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (static_buffer[i] == '\n')
		i++;
	aux = malloc(sizeof(char) * (len + 1));
	while (static_buffer[i])
	{
		aux[j++] = static_buffer[i++];
	}
	aux[j] = '\0';
	free(static_buffer);
	return(aux);

}


char	*get_next_line(int fd)
{
	static char *static_buffer;
	char		*buffer;
	int			count;
	char		*line;
	int			flag;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!static_buffer)
		static_buffer = ft_strdup("");
	count = 1;
	flag = 0;
	while (count > 0 && !checker(static_buffer))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			flag = 1;
			break ;
		}
		if (count == 0)
		{
			flag = 2;
			break;
		}
		buffer[count] = '\0';
		static_buffer = ft_strjoin(static_buffer, buffer);
	}
	free(buffer);
	if (!static_buffer || !*static_buffer || flag == 1)
	{
		free(static_buffer);
		static_buffer = NULL;
		return (NULL);
	}
	line = only_line(static_buffer);
	static_buffer = increment_buffer(static_buffer);
	return(line);

    
}

// int main()
// {
// 	int file = open("./hola.txt", O_RDONLY , O_RDONLY);
// 	char *line = get_next_line(file);
// 	int count;

// 	count = 0;
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(file);
// 		count++;
// 	}
// 	free(line);
// 	// printf("%s", line);
// 	// free(line);
// 	// line = get_next_line(file);
// 	close(file);
// 	// free(line);
// 	// system("leaks a.out");
// 	// system("");
// 	// atexit(leaks);
// }

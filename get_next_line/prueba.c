/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:32:43 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/30 21:19:41 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


int		ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

char	*ft_strdup(char *str)
{
	char 	*aux;
	int		len;
	int		i;

	len = ft_strlen(str);
	aux = malloc(sizeof(char) * (len + 1));
	if(!aux)
		return(NULL);
	i = 0;
	while(i < len)
	{
		aux[i] = str[i];
		i++;
	}
	aux[i] = '\0';
	return(aux);
}

int		bool_next_line(char *static_buffer)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (static_buffer[i] != '\0' && flag == 0)
	{
		if (static_buffer[i] == '\n')
		{
			flag = 1;
			break; 
		}
		i++;
	}
	return(flag);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char *aux;
	int i;
	int j;
	int len;

	len = ft_strlen(str1) + ft_strlen(str2);
	aux = malloc(sizeof(char) * (len + 1));
	if (!aux)
		return(NULL);
	i = 0;
	while (i < len && str1[i])
	{
		aux[i] = str1[i];
		i++;
	}
	j = 0;
	while (i < len && str2[j])
	{
		aux[i] = str2[j];
		i++;
		j++;
	}
	aux[i] = '\0';
	free(str1);
	return(aux);
}

char	*only_line(char *static_buffer)
{
	int i;
	char *line;

	i = 0;
	while (static_buffer[i] != '\0' && static_buffer[i] != '\n')
	{
		i++;
	}
	if (static_buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return(NULL);
	i = 0;
	while (static_buffer[i] != '\0' && static_buffer[i] != '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
	{
		line[i++] = '\n';
	}
	line[i] = '\0'; 
	return(line);
}

char	*buff_increment(char *static_buffer)
{
	char *line;
	int i;
	int len;

	len = ft_strlen(static_buffer);
	while (static_buffer[i] != '\0' && static_buffer[i] != '\n')
	{
		i++;
	}
	if (static_buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return(NULL);
	while (static_buffer[i])
	{
		line[i] = static_buffer[i];
	}
	static_buffer[i] = '\0';
	return(line);
}

char	*get_next_line(int fd)
{
    static char		*static_buffer;
	char			*buffer;
	char			*line;
	int				count;
	int				flag;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return(NULL);
	if (!static_buffer)
		static_buffer = ft_strdup("");
	count = 1;
	flag = 0;
	while (count > 0 && bool_next_line(static_buffer) == 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if(count == -1){
			flag = 1;
			break ; 
		}
		if (count == 0){
			flag =2;
			break ;
		}
		buffer[count] = '\0';
		static_buffer = ft_strjoin(static_buffer, buffer);
	}
	free(buffer);
	if (!*static_buffer || !static_buffer || flag == 1)
	{
		free(static_buffer);
		static_buffer = NULL;
		return(NULL);
	}
	line = only_line(static_buffer);
	static_buffer = buff_increment(static_buffer);
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

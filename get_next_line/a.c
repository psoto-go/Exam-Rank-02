#include "a.h"

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
	char *aux;
	int len;
	int i;

	len = ft_strlen(str);
	i  =0;
	aux = malloc(sizeof(char) * (len + 1));
	if(!aux)
		return(NULL);
	while (i < len)
	{
		aux[i] = str[i];
		i++;
	}
	aux[i] = '\0';
	return(aux);
}

int		checker(char *static_buffer)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (static_buffer[i] != '\0' && flag == 0)
	{
		if (static_buffer[i] == '\n')
			flag = 1;
		i++;
	}
	return(flag);
}

char	*ft_strjoin(char *str, char *str2)
{
	char *aux;
	int i;
	int j;
	int len;

	len = ft_strlen(str) + ft_strlen(str2);
	aux = malloc(sizeof(char) * (len + 1));
	if(!aux)
		return(NULL);
	i  =0;
	while (i < len && str[i])
	{
		aux[i] = str[i];
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
	free(str);
	return(aux);
}

char	*onlyline(char *static_buffer)
{
	char *aux;
	int i;

	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (static_buffer[i] == '\n')
		i++;
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
	{
		aux[i++] = '\n';
	}
	aux[i] = '\0';
	return(aux);
}

char	*buffinc(char *static_buffer)
{
	char *aux;
	int len;
	int i;
	int j;

	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (static_buffer[i] == '\n')
		i++;
	len = ft_strlen(static_buffer);
	aux = malloc(sizeof(char) * (len + 1));
	if(!aux)
		return(NULL);
	j = 0;
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
	char *buffer;
	char *line;
	int count;
	int flag;

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
			break;
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
	if (!static_buffer || !*static_buffer|| flag == 1)
	{
		free(static_buffer);
		static_buffer = NULL;
		return (NULL);
	}
	line = onlyline(static_buffer);
	static_buffer = buffinc(static_buffer);
	return(line);
	
}
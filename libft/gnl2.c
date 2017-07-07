/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-pont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 09:13:25 by rde-pont          #+#    #+#             */
/*   Updated: 2017/06/19 11:12:07 by rde-pont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static char		*append_str(char *str, char *app)
{
	char	*temp;

	if (str == NULL)
	{
		str = ft_strdup(app);
		if (app != NULL)
			free(app);
		return (str);
	}
	temp = ft_strjoin(str, app);
	free(str);
	free(app);
	str = temp;
	return (str);
}

static char		*get_line_chunk(char *buff, char *end)
{
	size_t	i_n;
	char	*line_chunk;
	char	temp_buff[BUFF_SIZE + 1];

	i_n = 0;
	while (buff[i_n] && buff[i_n] != '\n')
		++i_n;
	if (buff[i_n] == '\n')
	{
		++i_n;
		*end = 1;
	}
	else
		*end = 0;
	line_chunk = ft_strnew(i_n);
	ft_strncpy(line_chunk, buff, i_n - *end);
	ft_bzero(temp_buff, BUFF_SIZE + 1);
	ft_strcpy(temp_buff, &buff[i_n]);
	ft_bzero(buff, BUFF_SIZE + 1);
	ft_memcpy(buff, temp_buff, sizeof(char) * BUFF_SIZE + 1);
	return (line_chunk);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	char		end;
	char		*temp;
	static char buff[BUFF_SIZE + 1];

	end = 0;
	temp = NULL;
	if (line == NULL)
		return (-1);
	if (buff[0])
		temp = get_line_chunk(buff, &end);
	if (!end)
		while (0 < (ret = read(fd, buff, BUFF_SIZE)))
		{
			temp = append_str(temp, get_line_chunk(buff, &end));
			if (end)
				break ;
		}
	*line = temp;
	if (temp == NULL)
		return (ret);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:07:46 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/19 10:21:21 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		free_leak(char **ptr, int nb, int fd)
{
	if (fd >= 0 && fd < FD_SIZE)
	{
		if (*ptr && ptr)
		{
			free(*ptr);
			*ptr = NULL;
		}
	}
	return (nb);
}

char	*ft_check(char **tmp, int r, int fd)
{
	if (tmp[fd][r] && tmp[fd][r + 1])
		return (ft_strdup(tmp[fd] + r + 1));
	else
	{
		return (NULL);
	}
}

int		ft_remplissage(char **tmp, int fd, char **line)
{
	int		r;
	char	*delt;

	delt = tmp[fd];
	r = 0;
	while (tmp[fd][r] != '\n' && tmp[fd][r])
		r++;
	if (tmp[fd][r] == '\0')
	{
		*line = ft_strdup(tmp[fd]);
		return (free_leak(&tmp[fd], 0, fd));
	}
	*line = ft_substr(tmp[fd], 0, r);
	tmp[fd] = ft_check(tmp, r, fd);
	free(delt);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*tmp[2];
	int			r;

	if ((fd < 0 || fd >= FD_SIZE) || !line || BUFFER_SIZE <= 0 ||
			!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (free_leak(&tmp[1], -1, 1));
	while ((!(ft_strchr(tmp[1], '\n'))) &&
			((r = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[r] = '\0';
		tmp[1] = ft_strjoin_free(tmp[1], buf);
	}
	free(buf);
	if (r == -1 || (r == 0 && !ft_strlen(tmp[1])))
	{
		*line = ft_strdup("");
		return (free_leak(&tmp[1], r, 1));
	}
	return (ft_remplissage(tmp, 1, line));
}

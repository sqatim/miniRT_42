/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:53:21 by sqatim            #+#    #+#             */
/*   Updated: 2019/11/03 22:25:49 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	size_t		j;
	const char	*source;
	char		*copy;

	i = 0;
	j = len;
	source = (char *)src;
	copy = (char *)dst;
	if (!source && !copy)
		return (NULL);
	if (source >= copy)
		ft_memcpy(copy, source, len);
	else
	{
		while (len != 0)
		{
			len--;
			copy[len] = source[len];
		}
	}
	return (copy);
}

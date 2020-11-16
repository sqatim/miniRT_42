/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:02:16 by sqatim            #+#    #+#             */
/*   Updated: 2019/11/05 19:02:40 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t ls;
	size_t ld;
	size_t i;

	ls = ft_strlen(src);
	if (!dst && size == 0)
		return (ls);
	ld = ft_strlen(dst);
	i = 0;
	if (size <= ld)
		ls += size;
	else
		ls += ld;
	while (ld + 1 < size && src[i])
	{
		dst[ld] = src[i];
		ld++;
		i++;
	}
	if (ld < size)
		dst[ld] = '\0';
	return (ls);
}

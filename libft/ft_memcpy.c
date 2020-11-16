/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:51:19 by sqatim            #+#    #+#             */
/*   Updated: 2019/11/05 20:25:42 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*source;
	char	*copy;

	i = 0;
	source = (char *)src;
	copy = (char *)dest;
	if (!source && !copy)
		return (NULL);
	if (source == copy)
		return (dest);
	while (i < n)
	{
		copy[i] = source[i];
		i++;
	}
	return (dest);
}

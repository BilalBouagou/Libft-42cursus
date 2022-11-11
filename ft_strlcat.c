/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:33:15 by bbouagou          #+#    #+#             */
/*   Updated: 2022/10/06 21:55:59 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		init_dst_size;
	size_t		src_size;

	src_size = ft_strlen(src);
	if (dst == NULL && !dstsize)
		return (ft_strlen(src));
	init_dst_size = ft_strlen(dst);
	if (init_dst_size >= dstsize || dstsize == 0)
		return (dstsize + src_size);
	i = 0;
	while (src[i] != '\0' && (i + 1 < (dstsize - init_dst_size)))
	{
		dst[init_dst_size + i] = src[i];
		i++;
	}
	dst[init_dst_size + i] = '\0';
	return (init_dst_size + src_size);
}

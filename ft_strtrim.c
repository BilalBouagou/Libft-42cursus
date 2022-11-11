/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:05:35 by bbouagou          #+#    #+#             */
/*   Updated: 2022/10/08 14:57:04 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	size;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	size = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	if (i == size)
		return (ft_strdup(""));
	while (size > 0 && ft_strchr(set, s1[size]))
		size--;
	trimmed = (char *)malloc(size - i + 2);
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, &s1[i], size - i + 2);
	return (trimmed);
}

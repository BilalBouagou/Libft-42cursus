/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:02:35 by bbouagou          #+#    #+#             */
/*   Updated: 2022/10/08 13:07:09 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*copy;

	if (s == NULL || f == NULL)
		return (NULL);
	copy = ft_strdup(s);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (copy[i] != '\0')
	{
		copy[i] = (*f)(i, copy[i]);
		i++;
	}
	return (copy);
}

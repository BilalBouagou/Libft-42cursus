/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:58:37 by bbouagou          #+#    #+#             */
/*   Updated: 2022/10/06 23:07:11 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
escape_whitespace returns 1 if the character is a whitespace,
otherwise it returns 0.
*/

static	int	escape_whitespaces(char c)
{
	if (c == 32 || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == '\n')
		return (1);
	return (0);
}

/*
ft_atoi first skip all whitespaces in the string if
there's any, then it skips signs if there's any,
if the sign is minus, the variable sign is set to -1..
otherwise sign remains 1 as to not affect the return number.

then it loops on the string as long as the character is digit,
it subtracts '0' (ascii code 48) from it as to set it to its
digit form, and then j is incremented to check the next character.

if the next character is digit, i is multiplied by 10 to make room
for the next number.

i is returned multiplied by sign as to change the number to its correct
sign if it was negative, or remains the same if it was positive.
*/

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	sign;

	j = 0;
	i = 0;
	sign = 1;
	while (escape_whitespaces(str[j]))
		j++;
	if (str[j] == '+' || str[j] == '-')
	{
		if (str[j] == '-')
			sign *= -1;
		j++;
	}
	while (ft_isdigit(str[j]))
	{
		i += str[j] - '0';
		j++;
		if (ft_isdigit(str[j]))
			i *= 10;
	}
	return (i * sign);
}

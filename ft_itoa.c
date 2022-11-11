/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:12:47 by bbouagou          #+#    #+#             */
/*   Updated: 2022/10/09 23:25:16 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
get_integer_lenght IS SELF-EXPLANATORY AND I'M TIREEED...
*/

static	int	get_integer_lenght(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n == INT_MIN)
	{
		n = 147483648;
		count += 2;
	}
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

/*
write_to_string first checks if the integer is INT_MIN, if so
it directly copies int min representation in the string and null
terminates it using the function ft_strlcpy.

if the number isn't INT_MIN it then checks if the number is negative,
if so, the first character of the string is set to '-' and the
integer is turned positive.

it then loops and fills the string with the number representation
as long as size is >= 0 (for indexing) or the current index isn't '-'
(as not to overwrite it.).

it fills the string form the bottom up skipping the last index
for the nul-terminator.

if the integer is >= 10 it assigns the current index to the %
of the integer over 10 to get the last digit of the integer
and adds to it '0' to convert it to it's ascii representation,
it then divides the integer by 10 to get rid of the last digit.

otherwise if the integer is smaller than 10 then there's no need
for dividing or taking the mod, and the integer (what's left of it)
is converted to it's ascii representation.
*/

static	void	write_to_string(int n, char *s, int size)
{
	if (n == INT_MIN)
	{
		ft_strlcpy(s, "-2147483648", 12);
		return ;
	}
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	while (size >= 0 && s[size] != '-')
	{
		if (n >= 10)
		{
			s[size] = n % 10 + '0';
			n /= 10;
		}
		else
			s[size] = n + '0';
		size--;
	}
}

/*
ft_itoa takes an integer as a param and returns an
allocated string representation of it.

to achieve that goal, it first counts the lenght of
the given integer and adds 1 for the nul-terminator.

it then sets the count to size and allocates a pointer
using it, if the allocation fails, NULL is returned.

the allocation is done via the ft_calloc function to initialise
the string.

it then writes the string representation onto the allocated string
using write_to_string function passing the integer, the allocated string
and size - 2 (-1 for the nul-terminator and -1 because it uses size
for indexing.)

then it ends the string with a nul-terminator and returns it.
*/

char	*ft_itoa(int n)
{
	char	*result;
	int		size;

	size = get_integer_lenght(n) + 1;
	result = (char *)ft_calloc(size, sizeof(char));
	if (result == NULL)
		return (NULL);
	write_to_string(n, result, size - 2);
	result[size - 1] = '\0';
	return (result);
}

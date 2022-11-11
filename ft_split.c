/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:49:47 by bbouagou          #+#    #+#             */
/*   Updated: 2022/10/12 22:23:42 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

count segments takes the string and delimiter as params.

it loops on the string and skips delimiters if there's any.

if end-string is not reached, thats a segment.

count is then incremented, then the segment is skipped,
and if end-string isnt reached yet the process is repeated.

*/

static	int	segments_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

/*

if allocation fails in do_magic, undo magic is envoked,
it takes the index from ft_split, decrements it (because we can't free
a null pointer.),  and frees it's memory.

then it frees the double pointer and returns NULL.

*/

static	char	**undo_magic(char **result, int index)
{
	while (index > 0)
	{
		index--;
		free(result[index]);
	}
	free(result);
	return (NULL);
}

/*

do_magic takes the string and the delimiter as params,
it skips the segment to count it's lenght, allocates
a pointer with the corresponding segment lenght plus
one for the nul-terminator, and then copies the segment
in the allocated pointer and returning it.

*/

static	char	*do_magic(char const *s, char c)
{
	int		j;
	char	*clone;

	j = 0;
	while (s[j] != c && s[j] != '\0')
		j++;
	clone = (char *)malloc(j + 1);
	if (!clone)
		return (NULL);
	ft_strlcpy(clone, s, j + 1);
	return (clone);
}

/*

function for array initialisation in ft_split.

*/

static	void	init(int *var)
{
	var[0] = 0;
	var[1] = 0;
}

/*
ft_split first checks if the string is valid, if not it returns null.

then if th string is valid it allocates a double pointer according to
how many segments the string has, if the string has zero segments,
the string will only be allocated one space for the pointer who's
going to have NULL value.

then it initialises an array which is used for indexing with the
function init.

it starts by looping on the string, it skips delimiters if there's
any, then if the string hasn't finished yet it allocates sufficient
space for the segment and copies it in the double pointer.

if by any means allocation fails, the double pointer is freed and
NULL is returned via the undo_magic function.

otherwise the index is incremented, the segment is skipped and the process
is repeated if the string hasn't finished yet.

if end-string is reached, we set the last pointer to NULL and the double pointer
is returned.

*/

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		var[2];

	if (!s)
		return (NULL);
	result = (char **)malloc((segments_count(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	init(var);
	while (s[var[0]] != '\0')
	{
		while (s[var[0]] == c)
			var[0]++;
		if (s[var[0]] != '\0')
		{
			result[var[1]] = do_magic(&s[var[0]], c);
			if (!result[var[1]])
				return (undo_magic(result, var[0]));
			var[1]++;
		}
		while (s[var[0]] && s[var[0]] != c)
			var[0]++;
	}
	result[var[1]] = NULL;
	return (result);
}

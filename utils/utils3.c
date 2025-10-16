/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:31:44 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 11:32:30 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

void	ft_clean_line_from_spaces(char *line)
{
	int	i;
	int	j;

	if (!line)
		return ;
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			line[j++] = line[i];
		i++;
	}
	line[j] = '\0';
}

char	**ft_split_and_trim(char const *s, char c)
{
	char	**arr;
	int		i;
	char	*trimmed;

	arr = ft_split(s, c);
	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		trimmed = ft_trim(arr[i]);
		arr[i] = trimmed;
		i++;
	}
	return (arr);
}

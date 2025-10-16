/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:29:02 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 11:32:52 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (1);
}

char	*ft_trim(char *s)
{
	int	start;
	int	end;
	int	i;

	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] && (s[start] == ' '
			|| s[start] == '\t' || s[start] == '\n'))
		start++;
	while (end > start && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		end--;
	i = 0;
	while (start <= end)
		s[i++] = s[start++];
	s[i] = '\0';
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	size_t			total;
	unsigned char	*p;
	size_t			i;

	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	p = (unsigned char *)ptr;
	i = 0;
	while (i < total)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

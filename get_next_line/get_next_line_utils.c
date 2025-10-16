/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:27:38 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 11:27:39 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*copy;

	i = 0;
	while (s1[i])
		i++;
	copy = malloc(i + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	free_list(t_list **list)
{
	t_list	*current;
	t_list	*next;

	current = *list;
	while (current)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
	*list = NULL;
}

int	check_newline(t_list *list)
{
	int		i;
	t_list	*temp;

	temp = list;
	if (!list)
		return (0);
	while (temp != NULL)
	{
		i = 0;
		while (temp->str[i] != '\0')
		{
			if (temp->str[i] == '\n')
				return (1);
			i++;
		}
		temp = temp->next;
	}
	return (0);
}

int	get_line_len(t_list *list)
{
	t_list	*temp;
	int		len;
	int		i;

	temp = list;
	len = 0;
	while (temp != NULL)
	{
		i = 0;
		while (temp->str[i] != '\0')
		{
			len++;
			if (temp->str[i] == '\n')
				return (len);
			i++;
		}
		temp = temp->next;
	}
	return (len);
}

t_list	*find_newline_node(t_list *list, int *pos)
{
	t_list	*temp;
	int		i;

	temp = list;
	while (temp)
	{
		i = 0;
		while (temp->str[i])
		{
			if (temp->str[i] == '\n')
			{
				*pos = i;
				return (temp);
			}
			i++;
		}
		temp = temp->next;
	}
	return (NULL);
}

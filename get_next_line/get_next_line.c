/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:27:43 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 11:27:44 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	append_node(t_list **list, char *buf)
{
	t_list	*temp;
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return ;
	newnode->str = ft_strdup(buf);
	if (!newnode->str)
	{
		free(newnode);
		return ;
	}
	newnode->next = NULL;
	if (*list == NULL)
	{
		*list = newnode;
		return ;
	}
	temp = *list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newnode;
}

static void	copy_to_line(t_list *list, char *line, int *j)
{
	t_list	*temp;
	int		i;

	temp = list;
	while (temp != NULL)
	{
		i = 0;
		while (temp->str[i] != '\0')
		{
			line[*j] = temp->str[i];
			if (temp->str[i] == '\n')
			{
				(*j)++;
				line[*j] = '\0';
				return ;
			}
			(*j)++;
			i++;
		}
		temp = temp->next;
	}
	line[*j] = '\0';
}

static char	*get_line(t_list *list)
{
	char	*line;
	int		j;

	line = malloc(get_line_len(list) + 1);
	if (!line)
		return (NULL);
	j = 0;
	copy_to_line(list, line, &j);
	return (line);
}

static void	clean_list(t_list **list)
{
	t_list	*newline_node;
	int		newline_pos;
	char	*remaining;

	newline_node = find_newline_node(*list, &newline_pos);
	if (!newline_node)
	{
		free_list(list);
		return ;
	}
	remaining = ft_strdup(newline_node->str + newline_pos + 1);
	free_list(list);
	if (remaining && remaining[0])
		append_node(list, remaining);
	free(remaining);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;
	char			*buf;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!check_newline(list))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buf[bytes_read] = '\0';
		append_node(&list, buf);
	}
	free(buf);
	if (!list)
		return (NULL);
	next_line = get_line(list);
	clean_list(&list);
	return (next_line);
}

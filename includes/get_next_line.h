/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:36:39 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 11:36:41 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "utils.h"

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
void	free_list(t_list **list);
int		check_newline(t_list *list);
int		get_line_len(t_list *list);
t_list	*find_newline_node(t_list *list, int *pos);

#endif

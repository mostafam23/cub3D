/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moha <mel-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:37:08 by mel-moha          #+#    #+#             */
/*   Updated: 2025/10/09 12:08:53 by mel-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_trim(char *s);
void	*ft_calloc(size_t count, size_t size);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	free_split(char **arr);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
void	ft_clean_line_from_spaces(char *line);
int		check_number_in_array(char **array);
char	**ft_split_and_trim(char const *s, char c);
int		handle_empty_line(char *line);
int		validate_array_length(char **colors_array);

#endif
